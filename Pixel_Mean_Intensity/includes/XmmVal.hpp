#ifndef XMMVAL_HPP
#define XMMVAL_HPP

#include <cstdint>

struct alignas(16) XmmVal{
    public:
        union{
            uint8_t u8[16];
            int16_t i16[8];
            int32_t i32[4];
            int64_t i64[2];
            uint16_t u16[8];
            uint32_t u32[4];
            uint64_t u64[2];
            float f32[4];
            double f64[2];
        };
};
#endif