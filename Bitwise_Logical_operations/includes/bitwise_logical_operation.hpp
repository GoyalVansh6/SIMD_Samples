#ifndef BITWISE_LOGICAL_OPERATION_HPP
#define BITWISE_LOGICAL_OPERATION_HPP

#include "XmmVal.hpp"

extern void And_Iavx(XmmVal* c, XmmVal* a, XmmVal* b);
extern void Or_Iavx(XmmVal* c, XmmVal* a, XmmVal* b);
extern void Xor_Iavx(XmmVal* c, XmmVal* a, XmmVal* b);

#endif