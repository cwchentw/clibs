/** @file       cstring.h
 *  @brief      Utility functions for C strings.
 *  @author     OpenTechCoder
 *  @copyright  MIT
 *
 *  \b cstring.h and \b cstring.c only support null-terminated \c char array.
 */
#ifndef CLIBS_CSTRING_H
#define CLIBS_CSTRING_H

#ifdef __cplusplus
    #include <cstdio>
#else
    #include <stdio.h>
#endif

/* Custom boolean type. */
#if _MSC_VER
    #include <windows.h>
#else
#ifdef __cplusplus
    #ifndef _BOOL_IS_DEFINED
        typedef bool BOOL;
        #define FALSE  false
        #define TRUE   true
        #define _BOOL_IS_DEFINED
    #endif  /* BOOL */
#else
    #if __STDC_VERSION__ < 199901L
        #ifndef _BOOL_IS_DEFINED
            typedef unsigned char BOOL;
            #define FALSE  0
            #define TRUE   1
            #define _BOOL_IS_DEFINED
        #endif  /* BOOL */
    #else
        #ifndef _BOOL_IS_DEFINED
            #include <stdbool.h>
            typedef bool BOOL;
            #define FALSE  false
            #define TRUE   true
            #define _BOOL_IS_DEFINED
        #endif  /* BOOL */
    #endif  /* C89 */
#endif  /* __cplusplus */
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** @def     string_is_equal(a, b)
 *  @brief   Check whether two strings are equal.
 *  @param   a The first string.
 *  @param   b The second string.
 *  @return  BOOL
 */
#define string_is_equal(a, b) (0 == strcmp((a), (b)))

/** @fn      string_starts_with(const char *a, const char *b)
 *  @brief   Check whether string \a a starts with string \a b
 *  @param   a The source string.
 *  @param   b The target string.
 *  @return  BOOL
 */
BOOL string_starts_with(const char *a, const char *b);

/** @fn      string_contains(const char *a, const char *b)
 *  @brief   Check whether string \a a contains string \a b
 *  @param   a The source string.
 *  @param   b The target string.
 *  @return  BOOL
 */
BOOL string_contains(const char *a, const char *b);

/** @fn      string_is_space_only(const char *s)
 *  @brief   Check whether string \a s composes of only spaces
 *  @param   s The source string.
 *  @return  BOOL
 *
 *  string_is_space_only will always skip end of line.
 */
BOOL string_is_space_only(const char *s);

/** @fn      string_allocate_char(const char c)
 *  @brief   Allocate a new string out of char \a c
 *  @param   c The source char.
 *  @return  char *
 *  @warning  Free the memory of the returning string by yourself.
 */
char * string_allocate_char(const char c);

/** @fn      string_allocate(const char *s)
 *  @brief   Allocate a new string out of string \a s
 *  @param   s The source string.
 *  @return  char *
 *  @warning  Free the memory of the returning string by yourself.
 */
char * string_allocate(const char *s);

/** @fn       string_allocate_substring(const char *s, size_t from, size_t to)
 *  @brief    Allocate a new substring out of string \a s from \a from to \a to
 *  @param    s The source string.
 *  @param    from The start index of the substring.
 *  @param    to The end index of the substring
 *  @return   char *
 *  @warning  Free the memory of the returning string by yourself.
 */
char * string_allocate_substring(const char *s, size_t from, size_t to);

/** @fn       string_concat(const char *a, const char *b)
 *  @brief    Concat two strings \a and \b
 *  @param    a The source string.
 *  @param    b The source string.
 *  @return   char *
 *  @warning  Free the memory of the returning string by yourself.
 */
char * string_concat(const char *a, const char *b);

/** @fn       string_to_stream(char *s)
 *  @brief    Convert a string to a file stream.
 *  @param    s The source string.
 *  @return   FILE *
 *  @warning  Close the file stream by yourself.
 *
 *  Internally, the returning file stream is a temporary file. Due to the limitation imposed by the \a stdio.h on Windows, this function may fail.
 */
FILE * string_to_stream(char *s);

#ifdef __cplusplus
}
#endif

#endif  /* CLIBS_CSTRING_H */
