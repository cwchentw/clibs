/* cstring.h and cstring.c -
     string utilities for C string, aka null-terminated `char` array.
   Copyright (c) 2019 Michael Chen. Licensed under MIT. */
#ifndef CLIBS_CSTRING_H
#define CLIBS_CSTRING_H

#ifdef __cplusplus
    #include <cstdio>
#else
    #include <stdio.h>
#endif

/* Custom boolean type. */
#ifdef __cplusplus
    #ifndef BOOL
        typedef bool BOOL;
        #define FALSE  false
        #define TRUE   true
    #endif  /* BOOL */
#else
    #if __STDC_VERSION__ < 199901L
        #ifndef BOOL
            typedef char BOOL;
            #define FALSE  0
            #define TRUE   1
        #endif  /* BOOL */
    #else
        #ifndef BOOL
            #include <stdbool.h>
            typedef bool BOOL;
            #define FALSE  false
            #define TRUE   true
        #endif  /* BOOL */
    #endif  /* C89 */
#endif  /* __cplusplus */

/* Fix Windows-specific DLL issue */
#ifdef _WIN32
    #ifndef DLL_EXPORT
        #define DLL_EXPORT __declspec(dllimport)
    #endif  /* DLL_EXPORT */
#else
    #define DLL_EXPORT
#endif  /* WIN32 */

#ifdef __cplusplus
extern "C" {
#endif

DLL_EXPORT BOOL string_is_equal(char *a, char *b);
DLL_EXPORT BOOL string_starts_with(char *a, char *b);
DLL_EXPORT BOOL string_contains(char *a, char *b);

/* string_is_space_only will skip end of line. */
DLL_EXPORT BOOL string_is_space_only(char *a);

/* Allocate a new C string from input. */
DLL_EXPORT char * string_allocate(char *s);

/* Allocate a new C substring from input. */
DLL_EXPORT char * string_allocate_substring(char *s, size_t from, size_t to);

DLL_EXPORT FILE * string_to_stream(char *s);

#ifdef __cplusplus
}
#endif

#endif  /* CLIBS_CSTRING_H */
