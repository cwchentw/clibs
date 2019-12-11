# clibs

Tiny but handy utility libraries for C.

## Warning

DON'T USE IT IN PRODUCTION ENVIRONMENT.

clibs is still experimental and for personal use only. The API may change without warning.

## What is clibs anyway?

**clibs** are common utilities (types, macros, functions) used across C programs. They are mostly domain neutral, able to be applied to various situations.

## System Requirements

* A C compiler that supports ANSI C

**clibs** is written in ANSI C (C89). Nevertheless, We tested **clibs** against C89, C99 and C11. Hence, you may use it for code in either ANSI C or modern C.

We tested **clibs** against several Unix or Unix-like systems:

* Ubuntu 18.04 LTS
* CentOS 8
* openSUSE Leap 15.1
* TrueOS, FreeBSD compatible
* Solaris 11

It should work on other Unix or Unix-like systems as well.

BTW, though we didn't test **clibs** against Windows, it should also work because **clibs** is implemented in ANSI C.

## How to Use?

The libraries in **clibs** are self-contained, distributed in either single header or single header plus single source combo. Just copy what you need to your own C project.

test_\*.c are test programs. You don't need them to use **clibs**.

## Available Utilities:

* *boolean.h*: boolean type for C
* *cstring.h* and *cstring.c*: utility functions for C string (null-terminated `char` array)
* *platform.h*: platform-specific data
* *print_function.h*: handy console printing related function-like macros

## Copyright

Copyright (c) 2019 Michael Chen. Licensed under MIT.
