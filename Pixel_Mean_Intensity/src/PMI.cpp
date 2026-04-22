#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include "../includes/PMI.hpp"

void CalcMeanU8_bm(void) {
    std::vector<uint8_t> src(numElements);
    InitArray(src.data(), numElements, rnd_seed);

    uint64_t mean_cpp = 0, sum_cpp = 0;
    uint64_t mean_iavx = 0, sum_iavx = 0;

    // C++ Benchmark
    auto start_cpp = std::chrono::high_resolution_clock::now();
    CalcMeanU8_Cpp(&mean_cpp, &sum_cpp, src.data(), numElements);
    auto end_cpp = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff_cpp = end_cpp - start_cpp;

    // AVX Benchmark
    auto start_iavx = std::chrono::high_resolution_clock::now();
    CalcMeanU8_Iavx(&mean_iavx, &sum_iavx, src.data(), numElements);
    auto end_iavx = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff_iavx = end_iavx - start_iavx;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "C++ Results:\n";
    std::cout << "  Sum:  " << sum_cpp << "\n";
    std::cout << "  Mean: " << mean_cpp << "\n";
    std::cout << "  Time: " << diff_cpp.count() << " ms\n\n";

    std::cout << "AVX Results:\n";
    std::cout << "  Sum:  " << sum_iavx << "\n";
    std::cout << "  Mean: " << mean_iavx << "\n";
    std::cout << "  Time: " << diff_iavx.count() << " ms\n\n";

    if (sum_cpp == sum_iavx && mean_cpp == mean_iavx) {
        std::cout << "TEST PASSED\n";
        std::cout << "Speedup: " << diff_cpp.count() / diff_iavx.count() << "x\n";
    } else {
        std::cout << "TEST FAILED\n";
    }
}

int main() {
    std::cout << "Pixel Mean Intensity Benchmark (" << numElements << " elements)\n";
    CalcMeanU8_bm();
    return 0;
}
