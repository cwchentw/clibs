# clibs

Tiny but handy utility libraries for C.

## Warning

DON'T USE IT IN PRODUCTION ENVIRONMENT.

clibs is still experimental and for personal use only. The API may change without warning.

## What is clibs anyway?

**clibs** are common utility declarations (types, macros, functions) used across various C programs. They are mostly domain neutral, able to be applied in different situations.

## System Requirements

* A C compiler that supports ANSI C

**clibs** is written in ANSI C (C89). Nevertheless, We tested **clibs** against C89, C99 and C11. Hence, you may use it for code in either ANSI C or modern C.

We tested **clibs** against several Unix or Unix-like systems:

* Ubuntu 18.04 LTS
* CentOS 8
* openSUSE Leap 15.1
* TrueOS, FreeBSD compatible
* Solaris 11

It should work on other Unix or Unix-like systems.

BTW, though we didn't test **clibs** against Windows, it should work as well because **clibs** is implemented in ANSI C.

## How to Use?

The libraries in **clibs** are self-contained, distributed in either single header or single header plus single source combo. Just copy what you need to your own C project.

test_\*.c are test programs. You don't need them to use **clibs**.

## Available Libraries:

* *boolean.h*: boolean type for C
* *platform.h*: manage platform-specific issues
* *print_function.h*: handy print macro functions
* *string.h* and *string.c*: utility functions for C string (null-terminated `char` array)

## Copyright

Copyright (c) 2019 Michael Chen. Licensed under MIT.
