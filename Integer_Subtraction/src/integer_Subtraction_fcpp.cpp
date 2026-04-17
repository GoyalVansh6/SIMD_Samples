#include <immintrin.h>
#include "../includes/integer_Subtraction.hpp"

void SubI16_Iavx(XmmVal* c2, XmmVal* c1, XmmVal* a, XmmVal* b){
    __m128i a_vals = _mm_load_si128((const __m128i*)a);
    __m128i b_vals = _mm_load_si128((const __m128i*)b);

    __m128i c1_vals = _mm_sub_epi16(a_vals, b_vals);
    __m128i c2_vals = _mm_subs_epi16(a_vals, b_vals);

    _mm_store_si128((__m128i*) c1, c1_vals);
    _mm_store_si128((__m128i*) c2, c2_vals);
}

void SubU16_Iavx(XmmVal* c2, XmmVal* c1, XmmVal* a, XmmVal* b){
    __m128i a_vals = _mm_load_si128((const __m128i*)a);
    __m128i b_vals = _mm_load_si128((const __m128i*)b);

    __m128i c1_vals = _mm_sub_epi16(a_vals, b_vals);
    __m128i c2_vals = _mm_subs_epu16(a_vals, b_vals);

    _mm_store_si128((__m128i*)c1, c1_vals);
    _mm_store_si128((__m128i*)c2, c2_vals);
}