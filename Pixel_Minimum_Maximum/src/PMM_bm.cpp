#include <iostream>
#include <chrono>
#include "../includes/PMM.hpp"

int main(){
    std::cout << "Running Benchmark function CalcMinMax_BM:" << std::endl;

    size_t n = c_NumElements;
    uint8_t* x_aa = (uint8_t*)std::aligned_alloc(16, n);
    if (!x_aa) {
        std::cerr << "Memory allocation failed!" << std::endl;
        return 1;
    }

    InitArray(x_aa, n, c_RngSeed);

    uint8_t x_min1, x_max1;
    uint8_t x_min2, x_max2;

    const size_t num_runs = 500;

    auto start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < num_runs; ++i){
        CalcMinMaxU8_cpp(&x_min1, &x_max1, x_aa, n);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken C++: " << diff.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < num_runs; ++i){
        CalcMinMaxU8_Iavx(&x_min2, &x_max2, x_aa, n);
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "Time taken Iavx: " << diff.count() << " seconds" << std::endl;

    std::cout << (x_min1 == x_min2 && x_max1 == x_max2 ? "Results match: True" : "Results match: False") << std::endl;

    std::free(x_aa);
}