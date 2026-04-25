# Floating Point Arithmetic (SIMD)

This project demonstrates high-performance floating-point arithmetic operations using Intel AVX (Advanced Vector Extensions) intrinsics. It performs parallel calculations on 256-bit registers, handling 8 single-precision (`float`) or 4 double-precision (`double`) values simultaneously.

## Features

- **Parallel Processing**: Utilizes `__m256` and `__m256d` registers for vectorization.
- **Operations Supported**:
  - Addition (`_mm256_add_ps` / `pd`)
  - Subtraction (`_mm256_sub_ps` / `pd`)
  - Multiplication (`_mm256_mul_ps` / `pd`)
  - Division (`_mm256_div_ps` / `pd`)
  - Minimum/Maximum (`_mm256_min_ps`, `_mm256_max_ps`)
  - Square Root (`_mm256_sqrt_ps`)
  - Absolute Value (via bitwise AND with a mask)
- **Data Alignment**: Uses `alignas(32)` to ensure data is properly aligned for AVX memory operations.

## Project Structure

- `src/`: Source files containing the main logic and SIMD implementations.
- `includes/`: Header files and the `YmmVal` union definition.
- `README.md`: Project documentation.

## Technical Requirements

### AVX vs AVX2
While this project targets floating-point operations, it's important to understand the hardware requirements:
- **AVX**: Required for `__m256` (float) and `__m256d` (double) arithmetic.
- **AVX2**: Required if you wish to perform 256-bit **integer** operations (`__m256i`). 

Currently, the project uses `-mavx` (or `-mavx2`) during compilation to enable these instruction sets.

## Compilation and Usage

To compile the project, use `g++` with the `-mavx` flag:

```bash
g++ -mavx src/floating_point_arithmetic.cpp src/floating_point_arithmetic_fcpp.cpp -o fpa_simd
```

To run the executable:

```bash
./fpa_simd
```

## Data Structure Detail

The project uses a `union` called `YmmVal` to facilitate easy conversion between different data types and the 256-bit registers:

```cpp
struct alignas(32) YmmVal { 
    union{
        float m_F32[8]; 
        double m_F64[4]; 
    };
};
```
This allow the program to initialize data as standard arrays and then load them directly into SIMD registers using `_mm256_load_ps`.
