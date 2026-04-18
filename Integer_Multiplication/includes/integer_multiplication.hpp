#ifndef INTEGER_MULTIPLICATION_HPP
#define INTEGER_MULTIPLICATION_HPP

#include "XmmVal.hpp"

extern void MulI16_Iavx(XmmVal c[2], XmmVal* a, XmmVal* b);
extern void MulI32a_Iavx(XmmVal* c, XmmVal* a, XmmVal* b);
extern void MulI32b_Iavx(XmmVal* c, XmmVal* a, XmmVal* b);

#endif