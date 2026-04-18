# SIMD Integer Multiplication

This project demonstrates the implementation of integer multiplication using SIMD (Single Instruction, Multiple Data) instructions with AVX2. It includes routines for 16-bit and 32-bit integer multiplication, providing both low-precision results and full-precision results.

## Project Structure

- `includes/`: Header files
    - `XmmVal.hpp`: Definition of the `XmmVal` union for SIMD data handling.
    - `integer_multiplication.hpp`: Function declarations for SIMD multiplication routines.
- `src/`: Source files
    - `integer_multiplication.cpp`: Main entry point and demonstration logic.
    - `integer_multiplication_fcpp.cpp`: Implementation of SIMD multiplication using intrinsics.

## Features

- **MulI16_Iavx**: Multiplies eight 16-bit integers and stores the results as eight 32-bit integers across two 128-bit registers.
- **MulI32a_Iavx**: Multiplies four 32-bit integers, returning the lower 32 bits of each result.
- **MulI32b_Iavx**: Multiplies four 32-bit integers, returning the full 64-bit results for each multiplication.

## Building and Running

To compile and run the project, use a C++ compiler with AVX2 support (e.g., `g++`):

```bash
g++ -mavx2 -I./includes src/integer_multiplication.cpp src/integer_multiplication_fcpp.cpp -o integer_multiplication
./integer_multiplication
```

## Sample Output

The program outputs the results of the multiplication operations, verifying the correctness of the SIMD logic.

```text
c1: 1 0 4 0 9 0 16 0
c2: 25 0 36 0 49 0 64 0
a: 10 3000 -2000 4200
b: -500 100 -12000 1000
c: -5000 300000 24000000 4200000
...
```
