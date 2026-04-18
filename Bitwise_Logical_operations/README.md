# SIMD Bitwise Logical Operations

This project demonstrates Bitwise Logical Operations (AND, OR, XOR) using SIMD (Single Instruction, Multiple Data) with AVX/AVX2 intrinsics.

## Project Structure

- `includes/`: Header files
    - `XmmVal.hpp`: Definition of the `XmmVal` union for SIMD data handling.
    - `bitwise_logical_operation.hpp`: Function declarations for SIMD bitwise routines.
- `src/`: Source files
    - `bitwise_logical_operation.cpp`: Main entry point and demonstration logic.
    - `bitwise_logical_operation_fcpp.cpp`: Implementation of SIMD bitwise operations using intrinsics.

## Features

- **And_Iavx**: Performs a bitwise AND between two 128-bit registers.
- **Or_Iavx**: Performs a bitwise OR between two 128-bit registers.
- **Xor_Iavx**: Performs a bitwise XOR between two 128-bit registers.

## Building and Running

To compile and run the project:

```bash
g++ -mavx2 -I./includes src/bitwise_logical_operation.cpp src/bitwise_logical_operation_fcpp.cpp -o bitwise_logical_operation
./bitwise_logical_operation
```

## Sample Output

```text
And:
a: 10 3000 -2000 4200
b: -500 100 -12000 1000
c: 8 32 -12256 104

Or:
a: 10 3000 -2000 4200
b: -500 100 -12000 1000
c: -498 3068 -1744 5096

Xor:
a: 10 3000 -2000 4200
b: -500 100 -12000 1000
c: -506 3036 10512 4992
```
