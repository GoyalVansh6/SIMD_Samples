#include "../includes/PMM.hpp"

void CalcMinMaxU8_cpp(uint8_t* x_min, uint8_t* x_max, const uint8_t* x, size_t size){
    uint8_t min_val = x[0];
    uint8_t max_val = x[0];
    for(size_t i = 1; i < size; ++i){
        if(x[i] < min_val){
            min_val = x[i];
        }
        if(x[i] > max_val){
            max_val = x[i];
        }
    }
    *x_min = min_val;
    *x_max = max_val;
}

void CalcMinMaxU8_Iavx(uint8_t* x_min, uint8_t* x_max, const uint8_t* x, size_t size){
    __m128i min_vals = _mm_set1_epi8(0xff);
    __m128i max_vals = _mm_set1_epi8(0x00);
    
    const size_t num_simd_elements = 16;

    for(size_t i = 0; i < size; i+= num_simd_elements){
        __m128i x_vals = _mm_load_si128((__m128i*)(x + i));

        min_vals = _mm_min_epu8(min_vals, x_vals);
        max_vals = _mm_max_epu8(max_vals, x_vals);
    }

    __m128i temp1, temp2, temp3, temp4;
    __m128i vals_r1, vals_r2, vals_r3, vals_r4;

    temp1 = _mm_srli_si128 (min_vals, 8);
    vals_r1 = _mm_min_epu8 (min_vals, temp1);
    temp2 = _mm_srli_si128 (vals_r1, 4);
    vals_r2 = _mm_min_epu8 (vals_r1, temp2);
    temp3 = _mm_srli_si128 (vals_r2, 2);
    vals_r3 = _mm_min_epu8 (vals_r2, temp3);
    temp4 = _mm_srli_si128 (vals_r3, 1);
    vals_r4 = _mm_min_epu8 (vals_r3, temp4);

    *x_min = _mm_extract_epi8(vals_r4, 0);

    temp1 = _mm_srli_si128 (max_vals, 8);
    vals_r1 = _mm_max_epu8 (max_vals, temp1);
    temp2 = _mm_srli_si128 (vals_r1, 4);
    vals_r2 = _mm_max_epu8 (vals_r1, temp2);
    temp3 = _mm_srli_si128 (vals_r2, 2);
    vals_r3 = _mm_max_epu8 (vals_r2, temp3);
    temp4 = _mm_srli_si128 (vals_r3, 1);
    vals_r4 = _mm_max_epu8 (vals_r3, temp4);

    *x_max = _mm_extract_epi8(vals_r4, 0);
}