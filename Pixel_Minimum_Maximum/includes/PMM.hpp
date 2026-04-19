#ifndef PIXEL_MINIMUM_MAXIMUM_HPP
#define PIXEL_MINIMUM_MAXIMUM_HPP

#include <cstddef>
#include <cstdint>
#include <immintrin.h>

#include "XmmVal.hpp"

// pixel_minimum_maximum_fcpp.cpp
extern void CalcMinMaxU8_cpp(uint8_t* x_min, uint8_t* x_max, const uint8_t* x, size_t size);
extern void CalcMinMaxU8_Iavx(uint8_t* x_min, uint8_t* x_max, const uint8_t* x, size_t size);

// pixel_minimum_maximum_misc.cpp
extern void InitArray(uint8_t* x, size_t size, unsigned int rnd_seed);

// pixel_minimum_maximum_BM.cpp
extern void CalcMinMax_BM();

const size_t c_NumElements = 10000000;
const unsigned int c_RngSeed = 42;

#endif