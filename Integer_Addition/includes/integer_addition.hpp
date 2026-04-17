#ifndef INTEGER_ADDITION_HPP
#define INTEGER_ADDITION_HPP

#include "XmmVal.hpp"

extern void AddI16_Iavx(XmmVal* c1, XmmVal* c2, XmmVal* a, XmmVal* b);
extern void AddU16_Iavx(XmmVal* c1, XmmVal* c2, XmmVal* a, XmmVal* b);

#endif