# clibs

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build status](https://ci.appveyor.com/api/projects/status/69a3u5o6wm3itj8w?svg=true)](https://ci.appveyor.com/project/cwchentw/clibs)

Self-contained utilities for C.

Visit the **clibs** website [here](https://cwchentw.github.io/clibs/html/index.html).  
Visit the **clibs** repository [here](https://github.com/cwchentw/clibs/).

---

## ⚠️ Warning

**clibs** is still experimental and primarily intended for personal use.  
The API may change without notice.

---

## ❓ What is clibs?

**clibs** is a collection of utility code (types, typedefs, macros, functions) used across C programs.  
It is self-contained and domain-neutral, designed to be applicable in various contexts.

---

## 🖥️ System Requirements

- A C compiler that supports ANSI C
- GNU Make (for testing only)

**clibs** is written in ANSI C (C89). However, we have tested it with C89, C99, and C11.  
You can use it with either classic or modern C codebases.

We have successfully compiled and run **clibs** with:

- GCC
- Clang
- Visual C++
- Intel C++ Compiler

We also test **clibs** on the following Unix or Unix-like systems:

- Ubuntu 20.04 LTS
- Rocky Linux 8.5
- openSUSE Leap 15.3
- FreeBSD 13.0

It should also work on other Unix-like systems.

Additionally, we test **clibs** on Windows using [AppVeyor](https://www.appveyor.com/),  
so it should be compatible with Windows as well.

---

## 📦 How to Use

The utilities in **clibs** are self-contained, provided either as:

- single-header files, or
- single-header + single-source file combos.

Just copy the components you need into your C project.

Files starting with `test_*.c` are for testing purposes and are **not required** for using **clibs**.

---

## 🧰 Available Utilities

- **boolean.h** – Boolean type for C
- **cio.h**, **cio.c** – Basic input/output
- **clibs_control_structure.h** – Common control structures
- **clibs_logging.h** – Logging for C
- **clibs_math.h** – Basic math operations
- **clibs_print.h**, **clibs_print.c** – Console printing function-like macros
- **clibs_time.h**, **clibs_time.c** – Time utility functions
- **cstring.h**, **cstring.c** – Utility functions for C strings (`char` arrays)
- **integer.h** – Fixed-width integer types (*experimental*)
- **platform.h** – Platform-specific data
- **term_color.h** – Console color macros

Browse the **clibs** API documentation [here](https://cwchentw.github.io/clibs/html/index.html).

---

## 📝 License

Copyright © 2019–2021 ByteBard  
All code is licensed under the MIT License unless otherwise specified.
