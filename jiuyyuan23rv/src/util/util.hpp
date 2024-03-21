#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <string>

#include "range.hpp"

namespace Util {

int32_t parseInt(const std::string& literal);

int32_t floatToI32(float number);

float i32ToFloat(int32_t number);

template <class T>
T max(const T& lhs, const T& rhs) {
  return lhs < rhs ? rhs : lhs;
}

}  // namespace Util

#endif
