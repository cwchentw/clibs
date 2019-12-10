# clibs

Tiny but handy utility libraries for C.

## Warning

DON'T USE IT IN PRODUCTION ENVIRONMENT.

clibs is still experimental and for personal use only. The API may change without warning.

## System Requirements

* A C compiler that supports ANSI C

**clibs** is written in ANSI C. Nevertheless, We tested **clibs** in C89, C99 and C11.

## What is clibs anyway?

**clibs** are common utility declarations (types, macros, functions) used across various C programs. They are mostly domain neutral, able to be applied in different situations.

## How to Use?

The libraries in **clibs** are self-contained, distributed in either single header or single header plus single source combo. Just copy what you need to your own C project.

test_\*.c are test programs. You don't need them to use **clibs**.

## Available Libraries:

* *boolean.h*: boolean type for C
* *print_function.h*: handy print macro functions

## Copyright

Copyright (c) 2019 Michael Chen. Licensed under MIT.
