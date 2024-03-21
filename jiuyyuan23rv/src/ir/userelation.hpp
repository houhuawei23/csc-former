#ifndef __USERELATION_HPP__
#define __USERELATION_HPP__

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
  size_t _index;
  User *_user;
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
protected:
  Type *_type;
  std::string _name;
  std::list<Use *> _uses;

public:
  Value(Type *type, const std::string &name);
  virtual ~Value() = default;
  Type *type();
  std::string name();
  std::list<Use *> &uses();
  void newUse(Use *use);
  void delUse(Use *use);
  void replaceAllUseWith(Value *_value);  // 夺舍
  void rename(const std::string &name);
};

class User : public Value {
protected:
  std::vector<Use> _operands;

public:
  User(Type *type, const std::string &name);
  std::vector<Use> &operands();
  Value *operand(size_t index);
  void newOperand(Value *value);
  void setOperand(size_t index, Value *value);
  template <typename Container>
  void newOperands(const Container &operands) {
    for (const auto &operand : operands) newOperand(operand);
  }
};

}  // namespace IR

#endif
