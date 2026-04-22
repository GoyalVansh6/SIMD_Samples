#include "../includes/PMI.hpp"
#include <immintrin.h>

bool CalcMeanU8_Cpp(uint64_t* mean_x, uint64_t* sum_x, const uint8_t* src, size_t count) {
    if (count == 0) return false;
    uint64_t sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += src[i];
    }
    *sum_x = sum;
    *mean_x = sum / count;
    return true;
}

bool CalcMeanU8_Iavx(uint64_t* mean_x, uint64_t* sum_x, const uint8_t* src, size_t count) {
    if (count == 0) return false;
 
    const size_t num_simd_elements = 16;

    __m128i pixel_sum_u32 = _mm_setzero_si128();
    __m128i packed_zero = _mm_setzero_si128();
 
    for(size_t i = 0; i < count; i += num_simd_elements * 4){
        __m128i pixel_sum_u16 = _mm_setzero_si128();
        
        __m128i pixel_vals_u8 = _mm_loadu_si128((__m128i const*)&src[i]);
        __m128i pixel_vals_lo_u16 = _mm_unpacklo_epi8(pixel_vals_u8, packed_zero);
        __m128i pixel_vals_hi_u16 = _mm_unpackhi_epi8(pixel_vals_u8, packed_zero);

        pixel_sum_u16 = _mm_add_epi16(pixel_sum_u16, pixel_vals_lo_u16);
        pixel_sum_u16 = _mm_add_epi16(pixel_sum_u16, pixel_vals_hi_u16);
 
        
        pixel_vals_u8 = _mm_loadu_si128((__m128i const*)&src[i + num_simd_elements]);
        pixel_vals_lo_u16 = _mm_unpacklo_epi8(pixel_vals_u8, packed_zero);
        pixel_vals_hi_u16 = _mm_unpackhi_epi8(pixel_vals_u8, packed_zero);

        pixel_sum_u16 = _mm_add_epi16(pixel_sum_u16, pixel_vals_lo_u16);
        pixel_sum_u16 = _mm_add_epi16(pixel_sum_u16, pixel_vals_hi_u16);


        pixel_vals_u8 = _mm_loadu_si128((__m128i const*)&src[i + num_simd_elements * 2]);
        pixel_vals_lo_u16 = _mm_unpacklo_epi8(pixel_vals_u8, packed_zero);
        pixel_vals_hi_u16 = _mm_unpackhi_epi8(pixel_vals_u8, packed_zero);

        pixel_sum_u16 = _mm_add_epi16(pixel_sum_u16, pixel_vals_lo_u16);
        pixel_sum_u16 = _mm_add_epi16(pixel_sum_u16, pixel_vals_hi_u16);

        
        pixel_vals_u8 = _mm_loadu_si128((__m128i const*)&src[i + num_simd_elements * 3]);
        pixel_vals_lo_u16 = _mm_unpacklo_epi8(pixel_vals_u8, packed_zero);
        pixel_vals_hi_u16 = _mm_unpackhi_epi8(pixel_vals_u8, packed_zero);

        pixel_sum_u16 = _mm_add_epi16(pixel_sum_u16, pixel_vals_lo_u16);
        pixel_sum_u16 = _mm_add_epi16(pixel_sum_u16, pixel_vals_hi_u16);

        __m128i pixel_sum_lo_u32 = _mm_unpacklo_epi16(pixel_sum_u16, packed_zero);
        __m128i pixel_sum_hi_u32 = _mm_unpackhi_epi16(pixel_sum_u16, packed_zero);

        pixel_sum_u32 = _mm_add_epi32(pixel_sum_u32, pixel_sum_lo_u32);
        pixel_sum_u32 = _mm_add_epi32(pixel_sum_u32, pixel_sum_hi_u32);
    }

    uint64_t pixel_sum = 0;
    
    pixel_sum += _mm_extract_epi32(pixel_sum_u32, 0);
    pixel_sum += _mm_extract_epi32(pixel_sum_u32, 1);
    pixel_sum += _mm_extract_epi32(pixel_sum_u32, 2);
    pixel_sum += _mm_extract_epi32(pixel_sum_u32, 3);
    
    *sum_x = pixel_sum;
    *mean_x = pixel_sum / count;
    return true;
}
