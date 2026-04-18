#ifndef SHIFT_OPERATIONS_HPP
#define SHIFT_OPERATIONS_HPP

#include "XmmVal.hpp"

extern void ShiftLeft_Iavx(XmmVal* a, XmmVal* b, int count);
extern void ShiftRight_Iavx(XmmVal* a, XmmVal* b, int count);

#endif