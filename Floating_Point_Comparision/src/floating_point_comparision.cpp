#include <iostream>
#include <iomanip>
#include <random>
#include <limits>
#include <cmath>
#include <string>
#include "../includes/floating_point_comparision.hpp"

static void PackedCompF32(void);
static void PackedCompF64(void);

int main(void) {
    PackedCompF32();
    std::cout << "\n" << std::string(100, '=') << "\n\n";
    PackedCompF64();
    return 0;
}

static void PackedCompF32(void) {
    YmmVal a, b, c[8];
    float nan = std::numeric_limits<float>::quiet_NaN();
    float inf = std::numeric_limits<float>::infinity();

    // Setup Test Cases for 8 lanes
    struct TestCase { const char* name; float a; float b; };
    TestCase cases[8] = {
        {"a < b",    1.0f,  2.0f},
        {"a > b",    2.0f,  1.0f},
        {"a == b",   1.0f,  1.0f},
        {"a is NaN", nan,   1.0f},
        {"b is NaN", 1.0f,  nan},
        {"Both NaN", nan,   nan},
        {"0 == -0",  0.0f, -0.0f},
        {"inf==inf", inf,   inf}
    };

    for (int i = 0; i < 8; i++) {
        a.m_F32[i] = cases[i].a;
        b.m_F32[i] = cases[i].b;
    }

    PackedCompF32_Iavx(c, &a, &b);

    std::cout << "--- Single Precision (F32) AVX Comparison Matrix ---\n\n";
    
    // Header Row (Case Names)
    std::cout << std::left << std::setw(12) << "Test Case" << "| ";
    for (int i = 0; i < 8; i++) std::cout << std::right << std::setw(10) << cases[i].name;
    std::cout << "\n" << std::string(12, '-') << "+-" << std::string(80, '-') << "\n";

    // Input Rows
    std::cout << std::left << std::setw(12) << "Value a" << "| ";
    for (int i = 0; i < 8; i++) std::cout << std::right << std::setw(10) << a.m_F32[i];
    std::cout << "\n";
    
    std::cout << std::left << std::setw(12) << "Value b" << "| ";
    for (int i = 0; i < 8; i++) std::cout << std::right << std::setw(10) << b.m_F32[i];
    std::cout << "\n" << std::string(12, '-') << "+-" << std::string(80, '-') << "\n";

    // Result Rows
    const char* comp_names[] = {
        "EQ_OQ", "NEQ_OQ", "LT_OQ", "LE_OQ", "GT_OQ", "GE_OQ", "ORD_Q", "UNORD_Q"
    };

    for (int i = 0; i < 8; i++) {
        std::cout << std::left << std::setw(12) << comp_names[i] << "| ";
        for (int j = 0; j < 8; j++) {
            bool res = (c[i].m_u32[j] != 0);
            std::cout << std::right << std::setw(10) << (res ? "TRUE" : ".");
        }
        std::cout << "\n";
    }
}

static void PackedCompF64(void) {
    YmmVal a, b, c[8];
    double nan = std::numeric_limits<double>::quiet_NaN();
    double inf = std::numeric_limits<double>::infinity();

    // Setup Test Cases for 4 lanes
    struct TestCase { const char* name; double a; double b; };
    TestCase cases[4] = {
        {"a < b",    10.0,  20.0},
        {"a == b",   3.14,  3.14},
        {"a is NaN", nan,   0.0},
        {"inf > -inf", inf, -inf}
    };

    for (int i = 0; i < 4; i++) {
        a.m_F64[i] = cases[i].a;
        b.m_F64[i] = cases[i].b;
    }

    PackedCompF64_Iavx(c, &a, &b);

    std::cout << "--- Double Precision (F64) AVX Comparison Matrix ---\n\n";

    // Header Row (Case Names)
    std::cout << std::left << std::setw(12) << "Test Case" << "| ";
    for (int i = 0; i < 4; i++) std::cout << std::right << std::setw(15) << cases[i].name;
    std::cout << "\n" << std::string(12, '-') << "+-" << std::string(60, '-') << "\n";

    // Input Rows
    std::cout << std::left << std::setw(12) << "Value a" << "| ";
    for (int i = 0; i < 4; i++) std::cout << std::right << std::setw(15) << a.m_F64[i];
    std::cout << "\n";

    std::cout << std::left << std::setw(12) << "Value b" << "| ";
    for (int i = 0; i < 4; i++) std::cout << std::right << std::setw(15) << b.m_F64[i];
    std::cout << "\n" << std::string(12, '-') << "+-" << std::string(60, '-') << "\n";

    // Result Rows
    const char* comp_names[] = {
        "EQ_OQ", "NEQ_OQ", "LT_OQ", "LE_OQ", "GT_OQ", "GE_OQ", "ORD_Q", "UNORD_Q"
    };

    for (int i = 0; i < 8; i++) {
        std::cout << std::left << std::setw(12) << comp_names[i] << "| ";
        for (int j = 0; j < 4; j++) {
            bool res = (c[i].m_u64[j] != 0);
            std::cout << std::right << std::setw(15) << (res ? "TRUE" : ".");
        }
        std::cout << "\n";
    }
}
