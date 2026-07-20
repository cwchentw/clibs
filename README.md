# clibs

Self-contained utilities for C.

Visit the **clibs** website [here](https://cwchentw.github.io/clibs/html/index.html).  
Visit the **clibs** repository [here](https://github.com/cwchentw/clibs/).

## ⚠️ Warning

**clibs** is still experimental and primarily intended for personal use.  
The API may change without notice.

## ❓ What is clibs?

**clibs** is a collection of utility code (types, typedefs, macros, functions) used across C programs.  
It is self-contained and domain-neutral, designed to be applicable in various contexts.

## 🐧 Project Status

The original goal of **clibs** was to build a portable compatibility and abstraction layer in C. However, it is no longer the 1970s. For most developers today, the efficient development model is managed code + C ABI + kernel code. Mainstream languages all support FFI, allowing kernel code to be linked through the C ABI.

If one truly intends to develop systems programs, C++ or Rust should be used instead of C. The contemporary primary use case for C development is resource-constrained environments.

This project has entered maintenance mode. No new libraries will be added, but bug fixes will be applied when necessary.

## 🖥️ System Requirements

- A C compiler that supports ANSI C
- GNU Make (for testing only)

**clibs** is written in ANSI C (C89). However, we have tested it with C89, C99, and C11.  
You can use it with either classic or modern C codebases.

## 📦 How to Use

The utilities in **clibs** are self-contained, provided either as:

- single-header files, or
- single-header + single-source file combos.

Just copy the components you need into your C project.

Files starting with `test_*.c` are for testing purposes and are **not required** for using **clibs**.

## 🧰 Available Utilities

- **boolean.h** – Boolean type for C
- **cio.h**, **cio.c** – Basic input/output
- **clibs_control_structure.h** – Common control structures
- **clibs_logging.h** – Logging for C
- **clibs_math.h** – Basic math operations
- **clibs_time.h**, **clibs_time.c** – Time utility functions
- **cstring.h**, **cstring.c** – Utility functions for C strings (`char` arrays)
- **hash_table.h**, **hash_table.c** - Constant C string hash table
- **integer.h** – Fixed-width integer types (*experimental*)
- **platform.h** – Platform-specific data
- **print.h**, **print.c** – Console printing function-like macros
- **term_color.h** – Console color macros

Browse the **clibs** API documentation [here](https://cwchentw.github.io/clibs/html/index.html).

## 📝 License

Copyright © 2019–2021 ByteBard  
All code is licensed under the MIT License unless otherwise specified.
