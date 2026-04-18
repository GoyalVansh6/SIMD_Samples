#include <immintrin.h>
#include "../includes/bitwise_logical_operation.hpp"

void And_Iavx(XmmVal* c, XmmVal* a, XmmVal* b){
    __m128i a_vals = _mm_load_si128((__m128i*) a);
    __m128i b_vals = _mm_load_si128((__m128i*) b);

    __m128i result_vals = _mm_and_si128(a_vals, b_vals);

    _mm_store_si128((__m128i*) c, result_vals);
}

void Or_Iavx(XmmVal* c, XmmVal* a, XmmVal* b){
    __m128i a_vals = _mm_load_si128((__m128i*) a);
    __m128i b_vals = _mm_load_si128((__m128i*) b);

    __m128i result_vals = _mm_or_si128(a_vals, b_vals);

    _mm_store_si128((__m128i*) c, result_vals);
}

void Xor_Iavx(XmmVal* c, XmmVal* a, XmmVal* b){
    __m128i a_vals = _mm_load_si128((__m128i*) a);
    __m128i b_vals = _mm_load_si128((__m128i*) b);

    __m128i result_vals = _mm_xor_si128(a_vals, b_vals);

    _mm_store_si128((__m128i*) c, result_vals);
}
