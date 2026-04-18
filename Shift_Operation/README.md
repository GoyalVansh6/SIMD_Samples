# SIMD Shift Operations

This project demonstrates SIMD-accelerated shift operations on signed 32-bit integers using AVX/AVX2 intrinsics. It implements both Left Shift and Arithmetic Right Shift.

## Project Structure

- `includes/`: Header files
    - `XmmVal.hpp`: Union for SIMD data handling.
    - `shift_operations.hpp`: Function declarations for SIMD shift routines.
- `src/`: Source files
    - `shift_operation.cpp`: Main demonstration and output logic.
    - `shift_operations_fcpp.cpp`: Implementation of SIMD shifts using intrinsics.

## Features

- **ShiftLeft_Iavx**: Uses `_mm_slli_epi32` to shift four 32-bit integers to the left by a specified count.
- **ShiftRight_Iavx**: Uses `_mm_srai_epi32` (Arithmetic Right Shift) to shift four 32-bit integers to the right while preserving the sign bit.

## Building and Running

```bash
g++ -mavx2 -I./includes src/shift_operation.cpp src/shift_operations_fcpp.cpp -o shift_operation
./shift_operation
```

## Sample Output

```text
ShiftLeft:
a: 40 12000 -8000 16800
b: -500 100 -12000 1000

ShiftRight:
a: 2 750 -500 1050
b: -500 100 -12000 1000
```