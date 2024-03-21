#include "util.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

namespace Util {

int32_t parseInt(const std::string &literal) {
  const int64_t INTMAX = 2147483647ll;
  const int64_t INTMIN = -2147483648ll;
  const std::string oct = "0";
  const std::string hex = "0X";
  std::string int_literal(literal);
  std::transform(literal.begin(), literal.end(), int_literal.begin(), ::toupper);
  int64_t ret = 0;
  if (std::equal(hex.begin(), hex.end(), int_literal.begin())) {
    for (size_t i = 2; i < int_literal.length(); i++) {
      ret *= 16;
      if ('0' <= int_literal[i] && int_literal[i] <= '9')
        ret += int_literal[i] - '0';
      else
        ret += int_literal[i] - 'A' + 10;
      if (ret > INTMAX)
        assert(0);
      else if (ret < INTMIN)
        assert(0);
    }
  } else if (std::equal(oct.begin(), oct.end(), int_literal.begin())) {
    for (size_t i = 1; i < int_literal.length(); i++) {
      ret = ret * 8 + int_literal[i] - '0';
      if (ret > INTMAX)
        assert(0);
      else if (ret < INTMIN)
        assert(0);
    }
  } else {
    for (auto ch : int_literal) {
      ret = ret * 10 + ch - '0';
      if (ret > INTMAX)
        assert(0);
      else if (ret < INTMIN)
        assert(0);
    }
  }
  return static_cast<int32_t>(ret);
}

int32_t floatToI32(float number) {
  union {
    int32_t ivalue;
    float fvalue;
  } temp;
  temp.fvalue = number;
  return temp.ivalue;
}

float i32ToFloat(int32_t number) {
  union {
    int32_t ivalue;
    float fvalue;
  } temp;
  temp.ivalue = number;
  return temp.fvalue;
}

}  // namespace Util
