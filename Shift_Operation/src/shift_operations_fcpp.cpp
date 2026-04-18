#include <immintrin.h>
#include "../includes/shift_operations.hpp"

void ShiftLeft_Iavx(XmmVal* a, XmmVal* b, int count){
    __m128i a_vals = _mm_load_si128((__m128i*) a);
    __m128i b_vals = _mm_load_si128((__m128i*) b);

    __m128i result_vals = _mm_slli_epi32(a_vals, count);

    _mm_store_si128((__m128i*) a, result_vals);
}

void ShiftRight_Iavx(XmmVal* a, XmmVal* b, int count){
    __m128i a_vals = _mm_load_si128((__m128i*) a);
    __m128i b_vals = _mm_load_si128((__m128i*) b);

    __m128i result_vals = _mm_srai_epi32(a_vals, count);

    _mm_store_si128((__m128i*) a, result_vals);
}