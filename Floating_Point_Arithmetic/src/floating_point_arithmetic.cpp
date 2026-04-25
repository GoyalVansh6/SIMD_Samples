#include <iostream>
#include <iomanip>
#include "../includes/floating_point_arithmetic.hpp"

static void PackedMathF32(void);
static void PackedMathF64(void);

static const char* operations[8] = {
    "Add", "Sub", "Mul", "Div", "Min", "Max", "Sqrt a", "Abs b"
};

int main(){
    PackedMathF32();
    PackedMathF64();
    return 0;
}

void PackedMathF32(void){
    char nl = '\n';
    YmmVal a, b, c[8];

    a.m_F32[0] = 36.0f;
    a.m_F32[1] = 25.0f;
    a.m_F32[2] = (1.0 / 32.0);
    a.m_F32[3] = (1.0 / 64.0);
    a.m_F32[4] = 81.0f;
    a.m_F32[5] = 49.0f;
    a.m_F32[6] = (1.0 / 128.0);
    a.m_F32[7] = (1.0 / 256.0);

    b.m_F32[0] = 12.0f;
    b.m_F32[1] = 5.0f;
    b.m_F32[2] = 2.0f;
    b.m_F32[3] = 4.0f;
    b.m_F32[4] = 9.0f;
    b.m_F32[5] = 7.0f;
    b.m_F32[6] = 8.0f;
    b.m_F32[7] = 16.0f;

    PackedMathF32_Iavx(c, &a, &b);

    std::cout << "Floating Point Arithmetic (Scalar, SSE2) " << nl << nl;
    for(int i = 0; i < 8; i++){
        std::cout << operations[i] << nl;
        for(int j = 0; j < 8; j++){
            std::cout << std::fixed << std::setw(10) << a.m_F32[j] << "    ";
        }
        std::cout << nl;
        for(int j = 0; j < 8; j++){
            std::cout << std::fixed << std::setw(10) << b.m_F32[j] << "    ";
        }
        std::cout << nl;
        for(int j = 0; j < 8; j++){
            std::cout << std::fixed << std::setw(10) << c[i].m_F32[j] << "    ";
        }
        std::cout << nl << nl;
    }
}

void PackedMathF64(void){
    char nl = '\n';
    YmmVal a, b, c[4];

    a.m_F64[0] = 36.0;
    a.m_F64[1] = 25.0;
    a.m_F64[2] = (1.0 / 32.0);
    a.m_F64[3] = (1.0 / 64.0);

    b.m_F64[0] = 12.0;
    b.m_F64[1] = 5.0;
    b.m_F64[2] = 2.0;
    b.m_F64[3] = 4.0;

    PackedMathF64_Iavx(c, &a, &b);

    std::cout << "Floating Point Arithmetic (Scalar, SSE2) " << nl << nl;
    for(int i = 0; i < 4; i++){
        std::cout << operations[i] << nl;
        for(int j = 0; j < 4; j++){
            std::cout << std::fixed << std::setw(10) << a.m_F64[j] << "    ";
        }
        std::cout << nl;
        for(int j = 0; j < 4; j++){
            std::cout << std::fixed << std::setw(10) << b.m_F64[j] << "    ";
        }
        std::cout << nl;
        for(int j = 0; j < 4; j++){
            std::cout << std::fixed << std::setw(10) << c[i].m_F64[j] << "    ";
        }
        std::cout << nl << nl;
    }
}