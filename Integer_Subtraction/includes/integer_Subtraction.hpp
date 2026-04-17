#ifndef INTEGER_SUBTRACTION_HPP
#define INTEGER_SUBTRACTION_HPP
#include "XmmVal.hpp"

void SubI16_Iavx(XmmVal* c1, XmmVal* c2, XmmVal* a, XmmVal* b);
void SubU16_Iavx(XmmVal* c1, XmmVal* c2, XmmVal* a, XmmVal* b);

#endif