# SIMD Pixel Minimum Maximum (PMM)

This project demonstrates efficient calculation of the minimum and maximum pixel values (`uint8_t`) in an image or large array using SIMD (Single Instruction, Multiple Data) with AVX/SSE instructions. It provides a performance comparison between standard C++ loops and optimized SIMD routines.

## Project Structure

- `includes/`: Header files
    - [XmmVal.hpp]: Definition of the `XmmVal` union for SIMD data handling.
    - [PMM.hpp]: Function declarations for the PMM routines and constants.
- `src/`: Source files
    - [PMM.cpp]: Implementation of the min/max calculation logic using both standard C++ and SIMD intrinsics.
    - [PMM_misc.cpp]: Utility functions for array initialization and RNG seeding.
    - [PMM_bm.cpp]: Benchmark and main entry point.

## Features

- **CalcMinMaxU8_cpp**: A standard C++ implementation using a simple loop to find the minimum and maximum values.
- **CalcMinMaxU8_Iavx**: An optimized implementation using SIMD intrinsics (`_mm_min_epu8`, `_mm_max_epu8`) to process 16 pixels at a time, followed by horizontal reduction to find the global min/max.

## Building and Running

To compile and run the project, use a C++ compiler with AVX2 support (e.g., `g++`):

```bash
g++ -mavx2 -I./includes src/PMM.cpp src/PMM_misc.cpp src/PMM_bm.cpp -o Pixel_Min_Max
./Pixel_Min_Max
```

## Sample Output

The program performs the calculations and displays the execution time for both methods, along with the results for verification.

```
Pixel Minimum Maximum Benchmark
Elements: 10000000
RNG Seed: 42

[C++ Loop]
Min: 2, Max: 253
Time: 12.45 ms

[SIMD AVX/SSE]
Min: 2, Max: 253
Time: 1.23 ms

Speedup: ~10x
```
