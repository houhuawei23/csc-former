#ifndef __USERELATION_HPP__
#define __USERELATION_HPP__
#include <cassert>
#include <list>
#include <string>

#include "typesystem.hpp"

namespace IR {

class Use;
class Value;
class User;

class Use {
  friend class Value;
  friend class User;

protected:
  size_t _index;  // 在user的operands中的索引
  User *_user;    // user use value
  Value *_value;

public:
  Use(size_t index, User *user, Value *value);
  size_t index();
  User *user();
  Value *value();
  void setIndex(size_t index);
  void setValue(Value *value);
  void setUser(User *user);
};

class Value {
  friend class User;

protected:
  Type *_type;
  std::string _name;
  std::list<std::shared_ptr<Use>> _uses;  // 所有使用者

public:
  Value(Type *type, const std::string &name);
  virtual ~Value() = default;
  Type *type();
  std::string name();
  std::list<std::shared_ptr<Use>> &uses();
  void newUse(std::shared_ptr<Use> use);
  void delUse(std::shared_ptr<Use> use);
  void replaceAllUseWith(Value *_value);  // 夺舍
  // void removeUse(std::shared_ptr<Use> use);
  void removeAllUse();  // 夺舍
  void rename(const std::string &name);
};

class User : public Value {
  friend class Value;

protected:
  std::vector<std::shared_ptr<Use>> _operands;  // 所有操作数

public:
  User(Type *type, const std::string &name);
  std::vector<std::shared_ptr<Use>> &operands();
  Value *operand(size_t index);
  void newOperand(Value *value);
  void setOperand(size_t index, Value *value);
  template <typename Container>
  void newOperands(const Container &operands) {
    for (const auto &operand : operands) newOperand(operand);
  }
  void unUseAll() {
    for (auto &operand : _operands) {
      if (operand) {
        operand->value()->uses().remove(operand);
      }
    }
  }
  void replaceOpeandWith(unsigned index, Value *_value) {
    {
      assert(_operands.size() > index);
      if (!_value) {
        _operands.at(index)->value()->delUse(_operands.at(index));
        _operands.at(index) = nullptr;
        return;
      }
      _operands.at(index)->value()->delUse(_operands.at(index));
      auto ptr = std::make_shared<Use>(index, this, _value);
      _value->newUse(ptr);
      _operands.at(index) = ptr;
    }
  }
};
}  // namespace IR

#endif
