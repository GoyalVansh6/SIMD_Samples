#ifndef FLOATING_POINT_COMPARISION_HPP
#define FLOATING_POINT_COMPARISION_HPP

#include "YmmVal.hpp"
#include <immintrin.h>

bool PackedCompF32_Iavx(YmmVal c[8], YmmVal* a, YmmVal* b);
bool PackedCompF64_Iavx(YmmVal c[8], YmmVal* a, YmmVal* b);

#endif