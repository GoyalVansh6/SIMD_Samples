#include "../includes/PMI.hpp"
#include <random>

void InitArray(uint8_t* arr, size_t count, uint32_t seed){
    
    std::default_random_engine eng(seed);
    std::uniform_int_distribution<uint8_t> dist(0, 255);

    for(size_t i = 0; i < count; i++){
        arr[i] = dist(eng);
    }
}
