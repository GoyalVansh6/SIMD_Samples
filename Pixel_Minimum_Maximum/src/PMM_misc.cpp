#include "../includes/PMM.hpp"
#include <random>

void InitArray(uint8_t* x, size_t size, unsigned int rng_seed){
    int rng_min_val = 5;
    int rng_max_val = 250;

    std::mt19937 rng(rng_seed);
    std::uniform_int_distribution<uint8_t> dist(rng_min_val, rng_max_val);
    for(size_t i = 0; i < size; ++i){
        x[i] = dist(rng);
    }

    // using known values for easier testing
    x[(size / 4) * 3 + 1] = 2;
    x[(size / 2) + 2] = 253;
}