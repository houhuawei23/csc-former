#include "userelation.hpp"

#include <cassert>
#include <iostream>

namespace IR {

Use::Use(size_t index, User *user, Value *value) : _index(index), _user(user), _value(value) {
}

size_t Use::index() {
  return _index;
}

User *Use::user() {
  return _user;
}

Value *Use::value() {
  return _value;
}

void Use::setIndex(size_t index) {
  _index = index;
}

void Use::setValue(Value *value) {
  _value = value;
}

void Use::setUser(User *user) {
  _user = user;
}

Value::Value(Type *type, const std::string &name) : _type(type), _name(name), _uses() {
}

Type *Value::type() {
  return _type;
}

std::string Value::name() {
  return _name;
}

std::list<std::shared_ptr<Use>> &Value::uses() {
  return _uses;
}

void Value::newUse(std::shared_ptr<Use> use) {
  _uses.push_back(use);
}

void Value::delUse(std::shared_ptr<Use> use) {
  _uses.remove(use);
}

void Value::replaceAllUseWith(Value *value) {
  for (auto &use : _uses) use->user()->setOperand(use->index(), value);
  _uses.clear();
}

// void Value::removeUse(std::shared_ptr<Use> use) {
//   _uses.remove(use);
// }

void Value::removeAllUse() {
  for (auto &use : _uses){
    // std::cout << use->user()->_operands[use->index()]->value()->name() << "\n";
    use->user()->_operands[use->index()] = nullptr;
  }
  _uses.clear();
}

void Value::rename(const std::string &name) {
  _name = name;
}

User::User(Type *type, const std::string &name) : Value(type, name) {
}

std::vector<std::shared_ptr<Use>> &User::operands() {
  return _operands;
}

Value *User::operand(size_t index) {
  return _operands[index]->value();
}

void User::newOperand(Value *value) {
  auto ptr = std::make_shared<Use>(_operands.size(), this, value);
  _operands.emplace_back(ptr);
  value->newUse(ptr);
}

void User::setOperand(size_t _index, Value *_value) {
  assert(_index < _operands.size());
  auto ptr = std::make_shared<Use>(_index, this, _value);    // 2. initial new use
  _value->newUse(ptr);                                       // 3. add a new use
  _operands[_index] = ptr;                                   // 4. set the operand.
}

}  // namespace IR
