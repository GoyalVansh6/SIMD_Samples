#ifndef YMMVAL_HPP
#define YMMVAL_HPP

#include <cstdint>

struct alignas(32) YmmVal { 
    union{
        uint8_t m_u8[32]; 
        int16_t m_i16[16]; 
        int32_t m_i32[8]; 
        int64_t m_i64[4]; 
        uint16_t m_u16[16]; 
        uint32_t m_u32[8]; 
        uint64_t m_u64[4]; 
        float m_F32[8]; 
        double m_F64[4]; 
    };
};

#endif
