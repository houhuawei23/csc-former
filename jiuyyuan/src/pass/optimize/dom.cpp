#include "dom.hpp"

#include <map>
#include <set>

static std::unordered_map<IR::BasicBlock*, IR::BasicBlock*> parent;     //基本快的直接支配者，父节点
static std::unordered_map<IR::BasicBlock*, IR::BasicBlock*> ancenstor;  //最近支配者
static std::unordered_map<IR::BasicBlock*, IR::BasicBlock*> best;       //半支配节点
static std::unordered_map<IR::BasicBlock*, int> semi;                   //半支配值
static std::unordered_map<IR::BasicBlock*, IR::BasicBlock*> child;      //支配子节点
static std::unordered_map<IR::BasicBlock*, IR::BasicBlock*> samedom;    //同级支配节点
static std::unordered_map<IR::BasicBlock*, int> rank;                   //遍历基本快的顺序
using BBset = std::set<IR::BasicBlock*>;
static std::map<IR::BasicBlock*, BBset>
    bucket;  //存储基本块的指针，按照半支配值分组的桶。对于每个半支配值，bucket映射到一个基本块指针的集合。
static std::vector<IR::BasicBlock*>
    dfnumVertex;  //存储基本块的指针，按照遍历时的顺序排列的向量。对于每个遍历顺序，dfnumVertex映射到一个基本块指针。

static void clearIdomAll()  //将所有的声明初始化
{
  parent.clear();
  ancenstor.clear();
  best.clear();
  semi.clear();
  child.clear();
  samedom.clear();
  rank.clear();
  bucket.clear();
  dfnumVertex.clear();
}
void Pass::IdomGen::compress(IR::BasicBlock* v)  //计算v的最近支配者
{
  auto a = ancenstor[v];
  if (ancenstor[a]) {
    compress(a);
    if (semi[best[a]] < semi[best[v]]) best[v] = best[a];
    ancenstor[v] = ancenstor[a];
  }
}
IR::BasicBlock* Pass::IdomGen::eval(IR::BasicBlock* v)  //返回最近支配者
{
  if (!ancenstor[v]) return best[v];
  compress(v);
  if (semi[best[ancenstor[v]]] >= semi[best[v]])
    return best[v];
  else
    return best[ancenstor[v]];
}
void Pass::IdomGen::link(IR::BasicBlock* v, IR::BasicBlock* w) {
  auto s = w;
  while (semi[best[w]] < semi[best[child[s]]]) {
    if (rank[s] + rank[child[child[s]]] >= 2 * rank[child[s]]) {
      ancenstor[child[s]] = s;
      child[s] = child[child[s]];
    } else {
      rank[child[s]] = rank[s];
      s = ancenstor[s] = child[s];
    }
  }
  best[s] = best[w];
  rank[v] += rank[w];
  if (rank[v] < 2 * rank[w]) std::swap(s, child[v]);
  while (s) {
    ancenstor[s] = v;
    s = child[s];
  }
}
void Pass::IdomGen::getDfnum(IR::Function* func) {  //计算每个基本块的DFN值，并初始化半支配节点为自己

  int num = 0;
  std::unordered_map<IR::BasicBlock*, bool> vis;
  dfnumVertex = std::vector<IR::BasicBlock*>(func->basicBlocks().size(), nullptr);
  for (auto& bb : func->basicBlocks()) vis[bb.get()] = false;
  IR::BasicBlock::BasicBlockDfs(nullptr, func->allocas(), [&](IR::BasicBlock* pre, IR::BasicBlock* bb) -> bool {
    if (vis[bb]) return true;
    ancenstor[bb] = nullptr;
    child[bb] = nullptr;
    best[bb] = bb;
    semi[bb] = num;
    rank[bb] = 1;
    dfnumVertex[num] = bb;
    parent[bb] = pre;
    num++;
    vis[bb] = true;
    return false;
  });
}
void Pass::IdomGen::run(IR::Function* func) {
  for(auto &bb : func->basicBlocks()){
    bb->idom = nullptr;
    bb->sdom = nullptr;
    bb->domTree.clear();
    bb->domFrontier.clear();
    bb->domLevel = -1;
    bb->dom.clear();
  }
  clearIdomAll();
  getDfnum(func);
  semi[nullptr] = rank[nullptr] = 0;
  best[nullptr] = nullptr;
  for (auto iter = dfnumVertex.rbegin(); iter != dfnumVertex.rend(); iter++) {
    auto n = *iter;
    if (!parent[n])  // The Entry Block
      continue;
    auto p = parent[n];
    for (auto v : n->predecessors()) {
      auto u = eval(v);
      if (semi[u] < semi[n]) semi[n] = semi[u];
    }                                        //更新每个节点的半支配值
    bucket[dfnumVertex[semi[n]]].insert(n);  //按照半支配值分组
    link(p, n);
    for (auto v : bucket[p]) {
      auto u = eval(v);
      if (semi[u] < semi[v])
        v->idom = u;
      else
        v->idom = p;
    }
    bucket[p].clear();
  }
  for (auto n : dfnumVertex) {
    if (!parent[n]) continue;
    if (n->idom != dfnumVertex[semi[n]]) n->idom = n->idom->idom;
  }
  func->allocas()->idom = nullptr;
}
std::string_view Pass::IdomGen::name() {
  return "idom";
}

static std::set<IR::BasicBlock*> doms;
void Pass::DomTreeGen::computeAllDom(IR::BasicBlock* bb) {
  doms.insert(bb);
  bb->dom = std::set<IR::BasicBlock*>(doms);
  for (auto next : bb->domTree) computeAllDom(next);
  doms.erase(bb);
}
void Pass::DomTreeGen::computeDomLevel(IR::BasicBlock* bb, int level) {
  bb->domLevel = (level);
  for (auto succ : bb->domTree) computeDomLevel(succ, level + 1);
}
void Pass::DomTreeGen::run(IR::Function* func) {
  doms.clear();
  for (auto& bb : func->basicBlocks()) bb->domTree.clear();
  for (auto& bb : func->basicBlocks())
    if (bb->idom) {
      bb->idom->domTree.push_back(bb.get());
    }
  computeAllDom(func->allocas());
  computeDomLevel(func->allocas(), 0);
}

void Pass::DomFrontierGen::computeDF(IR::BasicBlock* bb) {
  std::vector<IR::BasicBlock*> S;
  bb->domFrontier.clear();
  for (auto y : bb->successors())
    if (y->idom != bb) {
      S.push_back(y);
    }
  for (auto c : bb->domTree) {
    computeDF(c);
    for (auto w : c->domFrontier)
      if (!w->dom.count(bb) || bb == w) {
        S.push_back(w);
      }
  }
  bb->domFrontier = std::move(S);
}
void Pass::DomFrontierGen::run(IR::Function* func) {
  computeDF(func->allocas());
}
