#ifndef FLOATING_POINT_ARITHMETIC_HPP
#define FLOATING_POINT_ARITHMETIC_HPP

#include "YmmVal.hpp"
#include <immintrin.h>

bool PackedMathF32_Iavx(YmmVal c[8], YmmVal* a, YmmVal* b);
bool PackedMathF64_Iavx(YmmVal c[4], YmmVal* a, YmmVal* b);

#endif