# SIMD Pixel Mean Intensity (PMI)

This project demonstrates efficient calculation of the mean intensity and total sum of pixel values (`uint8_t`) in a large array using SIMD (Single Instruction, Multiple Data) with AVX/SSE instructions. It provides a performance comparison between standard C++ loops and optimized SIMD routines.

## Project Structure

- `includes/`: Header files
    - [XmmVal.hpp]: Definition of the `XmmVal` union for SIMD data handling.
    - [PMI.hpp]: Function declarations for the PMI routines and constants.
- `src/`: Source files
    - [PMI.cpp]: Main entry point and benchmark logic.
    - [PMI_fcpp.cpp]: Implementation of mean/sum calculation logic using both standard C++ and SIMD intrinsics.
    - [PMI_misc.cpp]: Utility functions for array initialization.

## Features

- **CalcMeanU8_Cpp**: A standard C++ implementation using a simple loop to accumulate the sum and calculate the mean.
- **CalcMeanU8_Iavx**: An optimized implementation using SIMD intrinsics (`_mm_unpacklo_epi8`, `_mm_add_epi16`, etc.) to process multiple pixels simultaneously, minimizing loop overhead and leveraging hardware parallelism.

## Building and Running

To compile and run the project, use a C++ compiler with AVX2 support (e.g., `g++`):

```bash
g++ -mavx2 -I./includes src/PMI.cpp src/PMI_fcpp.cpp src/PMI_misc.cpp -o Pixel_Mean_Intensity
./Pixel_Mean_Intensity
```

## Sample Output

The program performs the calculations and displays the execution time for both methods, along with the results for verification.

```
Pixel Mean Intensity Benchmark (10000000 elements)
C++ Results:
  Sum:  1274945321
  Mean: 127
  Time: 12.4500 ms

AVX Results:
  Sum:  1274945321
  Mean: 127
  Time: 1.2300 ms

TEST PASSED
Speedup: 10.12x
```
