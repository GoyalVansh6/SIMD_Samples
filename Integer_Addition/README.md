# SIMD Integer Addition

This project demonstrates the use of SIMD (Single Instruction, Multiple Data) intrinsics for performing integer addition on 16-bit integers using SSE/AVX registers. It includes examples of both wraparound and saturated addition.

## Project Structure

```text
Integer_Addition/
├── includes/
│   ├── integer_addition.hpp    # Function declarations
│   └── XmmVal.hpp              # Shared SIMD data structure (union)
├── src/
│   ├── integer_addition.cpp    # Main entry point and test harness
│   └── integer_addition_fcpp.cpp # SIMD implementations using intrinsics
└── README.md
```

## Features

- **Wraparound Addition**: Standard integer addition where overflows wrap around (using `_mm_add_epi16`).
- **Saturated Addition**: Addition where values are clamped to the maximum/minimum possible value instead of wrapping (using `_mm_adds_epi16` for signed and `_mm_adds_epu16` for unsigned).
- **SIMD Optimization**: Processes 8 integers (16-bit each) simultaneously in a single 128-bit XMM register.

## Requirements

- A C++ compiler (e.g., GCC or Clang)
- An x86 CPU with AVX/SSE support

## Compilation

To compile the project, use the following command from the `Integer_Addition/` directory:

```bash
g++ -mavx src/integer_addition.cpp src/integer_addition_fcpp.cpp -o integer_addition
```

## Usage

Run the compiled executable:

```bash
./integer_addition
```

### Example Output

The program will output the results for both `c1` (wraparound) and `c2` (saturated) for signed and unsigned 16-bit integers.

```text
c1: 2 4 6 8 10 12 14 16
c2: 2 4 6 8 10 12 14 16
...
```
