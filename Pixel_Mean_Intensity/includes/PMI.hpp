#ifndef PMI_HPP
#define PMI_HPP

#include "XmmVal.hpp"
#include <immintrin.h>

extern bool CalcMeanU8_Cpp(uint64_t* mean_x, uint64_t* sum_x, const uint8_t* src, size_t count);
extern bool CalcMeanU8_Iavx(uint64_t* mean_x, uint64_t* sum_x, const uint8_t* src, size_t count);

extern void InitArray(uint8_t* arr, size_t count, uint32_t seed);

extern void CalcMeanU8_bm(void);

const size_t numElements = 10000000;
const unsigned int rnd_seed = 42;

#endif