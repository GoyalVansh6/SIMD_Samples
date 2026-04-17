# SIMD Integer Subtraction

This project demonstrates the use of SIMD (Single Instruction, Multiple Data) intrinsics for performing integer subtraction on 16-bit integers using SSE/AVX registers. It includes examples of both wraparound and saturated subtraction.

## Project Structure

```text
Integer_Subtraction/
├── includes/
│   ├── integer_Subtraction.hpp    # Function declarations
│   └── XmmVal.hpp                # Shared SIMD data structure (union)
├── src/
│   ├── integer_Subtraction.cpp    # Main entry point and test harness
│   └── integer_Subtraction_fcpp.cpp # SIMD implementations using intrinsics
└── README.md
```

## Features

- **Wraparound Subtraction**: Standard integer subtraction where overflows/underflows wrap around (using `_mm_sub_epi16`).
- **Saturated Subtraction**: Subtraction where values are clamped to the minimum/maximum possible value instead of wrapping (using `_mm_subs_epi16` for signed and `_mm_subs_epu16` for unsigned).
- **SIMD Optimization**: Processes 8 integers (16-bit each) simultaneously in a single 128-bit XMM register.

## Requirements

- A C++ compiler (e.g., GCC or Clang)
- An x86 CPU with AVX/SSE support

## Compilation

To compile the project, use the following command from the `Integer_Subtraction/` directory:

```bash
g++ -mavx src/integer_Subtraction.cpp src/integer_Subtraction_fcpp.cpp -o integer_subtraction
```

## Usage

Run the compiled executable:

```bash
./integer_subtraction
```

### Example Output

The program will output the results for both `c1` (wraparound) and `c2` (saturated) for signed and unsigned 16-bit integers.

```text
c1: 0 -2 -4 -6 -8 -10 -12 -14
c2: 0 -2 -4 -6 -8 -10 -12 -14
...
```
