# clibs

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) [![Build status](https://ci.appveyor.com/api/projects/status/69a3u5o6wm3itj8w?svg=true)](https://ci.appveyor.com/project/cwchentw/clibs)

Self-contained Utilities for C.

Visit the website of **clibs** [here](https://cwchentw.github.io/clibs/html/index.html).

Vist the repository of **clibs** [here](https://github.com/cwchentw/clibs/).

## Warning

clibs is still experimental and mostly for personal use. The API may change without warning.

## What is clibs anyway?

**clibs** are utility code (types, typedefs, macros, functions) used across C programs. They are self-contained and domain neutral, able to be applied to various situations.

## System Requirements

* A C compiler that supports ANSI C
* GNU Make (only for testing)

**clibs** is written in ANSI C (C89). Nevertheless, We tested **clibs** against C89, C99 and C11. Hence, you may use it for code in either classic C or modern C.

We compile and run **clibs** with GCC, Clang, Visual C++ and Intel C++ Compiler.

We test **clibs** against several Unix or Unix-like systems:

* Ubuntu 20.04 LTS
* Rocky Linux 8.5
* openSUSE Leap 15.3
* FreeBSD 13.0

It should work on other Unix or Unix-like systems as well.

In addition, we test **clibs** on a Windows container provided by [AppVeyor](https://www.appveyor.com/). Hence, **clibs** should work on Windows as well.

## How to Use?

The utilities in **clibs** are self-contained, distributed as either single header or single header plus single source combo. Just copy what you need to your own C project.

test_\*.c are test programs. You don't need them to use **clibs**.

## Available Utilities:

* *boolean.h*: boolean type for C
* *cio.h* and *cio.c*: basic input and output
* *clibs_control_structure.h*: common control structures
* *clibs_logging.h*: logging for C
* *clibs_math.h*: basic math operations
* *clibs_time.h* and *clibs_time.c*: basic time operations
* *cstring.h* and *cstring.c*: utility functions for C strings (null-terminated `char` arrays)
* *integer.h*: fixed-width integer type for C (*experimental*)
* *platform.h*: platform-specific data
* *print.h*: console printing related function-like macros
* *term_color.h*: console color related macros

Check the API of **clibs** [here](https://cwchentw.github.io/clibs/html/index.html).

## Copyright

Copyright (c) 2019-2021 Michelle Chen. All code is licensed under MIT unless mentioned otherwise.
