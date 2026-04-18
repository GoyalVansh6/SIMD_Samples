#include <immintrin.h>
#include "../includes/integer_multiplication.hpp"

void MulI16_Iavx(XmmVal c[2], XmmVal* a, XmmVal* b){
    __m128i a_vals = _mm_load_si128((const __m128i*) a);
    __m128i b_vals = _mm_load_si128((const __m128i*) b);

    __m128i temp_lo = _mm_mullo_epi16(a_vals, b_vals);
    __m128i temp_hi = _mm_mulhi_epi16(a_vals, b_vals);

    __m128i result_lo = _mm_unpacklo_epi16(temp_lo, temp_hi);
    __m128i result_hi = _mm_unpackhi_epi16(temp_lo, temp_hi);

    _mm_store_si128((__m128i*) c, result_lo);
    _mm_store_si128((__m128i*) c + 1, result_hi);
}

void MulI32a_Iavx(XmmVal* c, XmmVal* a, XmmVal* b){
    __m128i a_vals = _mm_load_si128((__m128i*) a);
    __m128i b_vals = _mm_load_si128((__m128i*) b);

    __m128i result_lo = _mm_mullo_epi32(a_vals, b_vals);

    _mm_store_si128((__m128i*) c, result_lo);
}

void MulI32b_Iavx(XmmVal c[2], XmmVal* a, XmmVal* b){
    __m128i a_vals = _mm_load_si128((__m128i*) a);
    __m128i b_vals = _mm_load_si128((__m128i*) b);

    __m128i temp1 = _mm_mul_epi32(a_vals, b_vals);
    __m128i temp2 = _mm_srli_si128(a_vals, 4);
    __m128i temp3 = _mm_srli_si128(b_vals, 4);
    __m128i temp4 = _mm_mul_epi32(temp2, temp3);

    __m128i result_lo = _mm_unpacklo_epi64(temp1, temp4); // [R0, R1]
    __m128i result_hi = _mm_unpackhi_epi64(temp1, temp4); // [R2, R3]

    _mm_store_si128((__m128i*) c, result_lo);
    _mm_store_si128((__m128i*) c + 1, result_hi);
}