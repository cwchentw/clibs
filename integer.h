/*
 * @file      integer.h
 * @brief     Fixed-width integer types for C (portable across platforms).
 * @author    ByteBard
 * @copyright MIT
 *
 * This header provides fixed-width integer types (e.g., int32_t, uint64_t)
 * for C89, C99, and MSVC environments.
 *
 * For pre-C99 compilers, run get_sizeof_data_type.c first to generate
 * _sizeof_data_type.h with platform-specific size definitions.
 *
 * Design goals:
 * - Prefer the native implementation when <stdint.h> is available.
 * - Provide a practical C89/MSVC fallback for exact-width integer types.
 * - Define min/max macros for the integer types that are actually available.
 * - Define intmax_t / uintmax_t.
 * - Define intptr_t / uintptr_t only when a suitable integer type exists.
 * - Define SIZE_MAX if it is missing.
 *
 * Notes:
 * - Exact-width types are only defined if the implementation actually
 *   provides a matching width.
 * - On unusual architectures, some exact-width types may be unavailable.
 */

#ifndef INTEGER_H
#define INTEGER_H

#include <limits.h>
#include <stddef.h>

/* ------------------------------------------------------------------------- */
/* Native C99+ path                                                          */
/* ------------------------------------------------------------------------- */

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)

    #include <stdint.h>

    #ifdef INT8_MAX
        #define INT8_IS_DEFINED
        #define UINT8_IS_DEFINED
    #endif

    #ifdef INT16_MAX
        #define INT16_IS_DEFINED
        #define UINT16_IS_DEFINED
    #endif

    #ifdef INT32_MAX
        #define INT32_IS_DEFINED
        #define UINT32_IS_DEFINED
    #endif

    #ifdef INT64_MAX
        #define INT64_IS_DEFINED
        #define UINT64_IS_DEFINED
    #endif

    #ifndef SIZE_MAX
        #define SIZE_MAX ((size_t)-1)
    #endif

/* ------------------------------------------------------------------------- */
/* Microsoft Visual C++ path                                                 */
/* ------------------------------------------------------------------------- */

#elif defined(_MSC_VER)

    typedef signed char        int8_t;
    typedef unsigned char      uint8_t;
    typedef signed short       int16_t;
    typedef unsigned short     uint16_t;
    typedef signed int         int32_t;
    typedef unsigned int       uint32_t;
    typedef signed __int64     int64_t;
    typedef unsigned __int64   uint64_t;

    #define INT8_IS_DEFINED
    #define UINT8_IS_DEFINED
    #define INT16_IS_DEFINED
    #define UINT16_IS_DEFINED
    #define INT32_IS_DEFINED
    #define UINT32_IS_DEFINED
    #define INT64_IS_DEFINED
    #define UINT64_IS_DEFINED

    #ifndef INT8_MIN
        #define INT8_MIN    SCHAR_MIN
    #endif
    #ifndef INT8_MAX
        #define INT8_MAX    SCHAR_MAX
    #endif
    #ifndef UINT8_MAX
        #define UINT8_MAX   UCHAR_MAX
    #endif

    #ifndef INT16_MIN
        #define INT16_MIN   SHRT_MIN
    #endif
    #ifndef INT16_MAX
        #define INT16_MAX   SHRT_MAX
    #endif
    #ifndef UINT16_MAX
        #define UINT16_MAX  USHRT_MAX
    #endif

    #ifndef INT32_MIN
        #define INT32_MIN   INT_MIN
    #endif
    #ifndef INT32_MAX
        #define INT32_MAX   INT_MAX
    #endif
    #ifndef UINT32_MAX
        #define UINT32_MAX  UINT_MAX
    #endif

    #ifndef INT64_MIN
        #define INT64_MIN   (-9223372036854775807i64 - 1)
    #endif
    #ifndef INT64_MAX
        #define INT64_MAX   9223372036854775807i64
    #endif
    #ifndef UINT64_MAX
        #define UINT64_MAX  18446744073709551615ui64
    #endif

    typedef int64_t           intmax_t;
    typedef uint64_t          uintmax_t;

    #ifndef INTMAX_MIN
        #define INTMAX_MIN   INT64_MIN
    #endif
    #ifndef INTMAX_MAX
        #define INTMAX_MAX   INT64_MAX
    #endif
    #ifndef UINTMAX_MAX
        #define UINTMAX_MAX  UINT64_MAX
    #endif

    #if defined(_WIN64)
        typedef signed __int64    intptr_t;
        typedef unsigned __int64  uintptr_t;
        #ifndef INTPTR_MIN
            #define INTPTR_MIN   INT64_MIN
        #endif
        #ifndef INTPTR_MAX
            #define INTPTR_MAX   INT64_MAX
        #endif
        #ifndef UINTPTR_MAX
            #define UINTPTR_MAX  UINT64_MAX
        #endif
    #else
        typedef signed int        intptr_t;
        typedef unsigned int      uintptr_t;
        #ifndef INTPTR_MIN
            #define INTPTR_MIN   INT32_MIN
        #endif
        #ifndef INTPTR_MAX
            #define INTPTR_MAX   INT32_MAX
        #endif
        #ifndef UINTPTR_MAX
            #define UINTPTR_MAX  UINT32_MAX
        #endif
    #endif

    #ifndef SIZE_MAX
        #define SIZE_MAX ((size_t)-1)
    #endif

/* ------------------------------------------------------------------------- */
/* Fallback C89 path                                                         */
/* ------------------------------------------------------------------------- */

#else

    #include "_sizeof_data_type.h"

    /* --------------------------------------------------------------------- */
    /* Exact-width integer typedef discovery                                  */
    /* --------------------------------------------------------------------- */

    /* Use char */
    #if _SIZEOF_CHAR == 8
        typedef signed char    int8_t;
        typedef unsigned char  uint8_t;
        #define INT8_IS_DEFINED
        #define UINT8_IS_DEFINED
        #define INTEGER_INT8_BASE_SCHAR
        #define INTEGER_UINT8_BASE_UCHAR
    #elif _SIZEOF_CHAR == 16
        typedef signed char    int16_t;
        typedef unsigned char  uint16_t;
        #define INT16_IS_DEFINED
        #define UINT16_IS_DEFINED
        #define INTEGER_INT16_BASE_SCHAR
        #define INTEGER_UINT16_BASE_UCHAR
    #elif _SIZEOF_CHAR == 32
        typedef signed char    int32_t;
        typedef unsigned char  uint32_t;
        #define INT32_IS_DEFINED
        #define UINT32_IS_DEFINED
        #define INTEGER_INT32_BASE_SCHAR
        #define INTEGER_UINT32_BASE_UCHAR
    #elif _SIZEOF_CHAR == 64
        typedef signed char    int64_t;
        typedef unsigned char  uint64_t;
        #define INT64_IS_DEFINED
        #define UINT64_IS_DEFINED
        #define INTEGER_INT64_BASE_SCHAR
        #define INTEGER_UINT64_BASE_UCHAR
    #endif

    /* Use short */
    #if _SIZEOF_SHORT == 8
        #ifndef INT8_IS_DEFINED
            typedef signed short    int8_t;
            typedef unsigned short  uint8_t;
            #define INT8_IS_DEFINED
            #define UINT8_IS_DEFINED
            #define INTEGER_INT8_BASE_SHORT
            #define INTEGER_UINT8_BASE_USHORT
        #endif
    #elif _SIZEOF_SHORT == 16
        #ifndef INT16_IS_DEFINED
            typedef signed short    int16_t;
            typedef unsigned short  uint16_t;
            #define INT16_IS_DEFINED
            #define UINT16_IS_DEFINED
            #define INTEGER_INT16_BASE_SHORT
            #define INTEGER_UINT16_BASE_USHORT
        #endif
    #elif _SIZEOF_SHORT == 32
        #ifndef INT32_IS_DEFINED
            typedef signed short    int32_t;
            typedef unsigned short  uint32_t;
            #define INT32_IS_DEFINED
            #define UINT32_IS_DEFINED
            #define INTEGER_INT32_BASE_SHORT
            #define INTEGER_UINT32_BASE_USHORT
        #endif
    #elif _SIZEOF_SHORT == 64
        #ifndef INT64_IS_DEFINED
            typedef signed short    int64_t;
            typedef unsigned short  uint64_t;
            #define INT64_IS_DEFINED
            #define UINT64_IS_DEFINED
            #define INTEGER_INT64_BASE_SHORT
            #define INTEGER_UINT64_BASE_USHORT
        #endif
    #endif

    /* Use int */
    #if _SIZEOF_INT == 8
        #ifndef INT8_IS_DEFINED
            typedef signed int    int8_t;
            typedef unsigned int  uint8_t;
            #define INT8_IS_DEFINED
            #define UINT8_IS_DEFINED
            #define INTEGER_INT8_BASE_INT
            #define INTEGER_UINT8_BASE_UINT
        #endif
    #elif _SIZEOF_INT == 16
        #ifndef INT16_IS_DEFINED
            typedef signed int    int16_t;
            typedef unsigned int  uint16_t;
            #define INT16_IS_DEFINED
            #define UINT16_IS_DEFINED
            #define INTEGER_INT16_BASE_INT
            #define INTEGER_UINT16_BASE_UINT
        #endif
    #elif _SIZEOF_INT == 32
        #ifndef INT32_IS_DEFINED
            typedef signed int    int32_t;
            typedef unsigned int  uint32_t;
            #define INT32_IS_DEFINED
            #define UINT32_IS_DEFINED
            #define INTEGER_INT32_BASE_INT
            #define INTEGER_UINT32_BASE_UINT
        #endif
    #elif _SIZEOF_INT == 64
        #ifndef INT64_IS_DEFINED
            typedef signed int    int64_t;
            typedef unsigned int  uint64_t;
            #define INT64_IS_DEFINED
            #define UINT64_IS_DEFINED
            #define INTEGER_INT64_BASE_INT
            #define INTEGER_UINT64_BASE_UINT
        #endif
    #endif

    /* Use long */
    #if _SIZEOF_LONG == 8
        #ifndef INT8_IS_DEFINED
            typedef signed long    int8_t;
            typedef unsigned long  uint8_t;
            #define INT8_IS_DEFINED
            #define UINT8_IS_DEFINED
            #define INTEGER_INT8_BASE_LONG
            #define INTEGER_UINT8_BASE_ULONG
        #endif
    #elif _SIZEOF_LONG == 16
        #ifndef INT16_IS_DEFINED
            typedef signed long    int16_t;
            typedef unsigned long  uint16_t;
            #define INT16_IS_DEFINED
            #define UINT16_IS_DEFINED
            #define INTEGER_INT16_BASE_LONG
            #define INTEGER_UINT16_BASE_ULONG
        #endif
    #elif _SIZEOF_LONG == 32
        #ifndef INT32_IS_DEFINED
            typedef signed long    int32_t;
            typedef unsigned long  uint32_t;
            #define INT32_IS_DEFINED
            #define UINT32_IS_DEFINED
            #define INTEGER_INT32_BASE_LONG
            #define INTEGER_UINT32_BASE_ULONG
        #endif
    #elif _SIZEOF_LONG == 64
        #ifndef INT64_IS_DEFINED
            typedef signed long    int64_t;
            typedef unsigned long  uint64_t;
            #define INT64_IS_DEFINED
            #define UINT64_IS_DEFINED
            #define INTEGER_INT64_BASE_LONG
            #define INTEGER_UINT64_BASE_ULONG
        #endif
    #endif

    /* Use long long if supported */
    #if defined(__GNUC__) || defined(__clang__)
        #ifdef _SIZEOF_LONG_LONG
            #if _SIZEOF_LONG_LONG == 8
                #ifndef INT8_IS_DEFINED
                    typedef signed long long    int8_t;
                    typedef unsigned long long  uint8_t;
                    #define INT8_IS_DEFINED
                    #define UINT8_IS_DEFINED
                    #define INTEGER_INT8_BASE_LLONG
                    #define INTEGER_UINT8_BASE_ULLONG
                #endif
            #elif _SIZEOF_LONG_LONG == 16
                #ifndef INT16_IS_DEFINED
                    typedef signed long long    int16_t;
                    typedef unsigned long long  uint16_t;
                    #define INT16_IS_DEFINED
                    #define UINT16_IS_DEFINED
                    #define INTEGER_INT16_BASE_LLONG
                    #define INTEGER_UINT16_BASE_ULLONG
                #endif
            #elif _SIZEOF_LONG_LONG == 32
                #ifndef INT32_IS_DEFINED
                    typedef signed long long    int32_t;
                    typedef unsigned long long  uint32_t;
                    #define INT32_IS_DEFINED
                    #define UINT32_IS_DEFINED
                    #define INTEGER_INT32_BASE_LLONG
                    #define INTEGER_UINT32_BASE_ULLONG
                #endif
            #elif _SIZEOF_LONG_LONG == 64
                #ifndef INT64_IS_DEFINED
                    typedef signed long long    int64_t;
                    typedef unsigned long long  uint64_t;
                    #define INT64_IS_DEFINED
                    #define UINT64_IS_DEFINED
                    #define INTEGER_INT64_BASE_LLONG
                    #define INTEGER_UINT64_BASE_ULLONG
                #endif
            #endif
        #endif
    #endif

    /* --------------------------------------------------------------------- */
    /* Exact-width limits                                                     */
    /* --------------------------------------------------------------------- */

    #ifdef INT8_IS_DEFINED
        #ifndef INT8_MIN
            #if defined(INTEGER_INT8_BASE_SCHAR)
                #define INT8_MIN   SCHAR_MIN
                #define INT8_MAX   SCHAR_MAX
            #elif defined(INTEGER_INT8_BASE_SHORT)
                #define INT8_MIN   SHRT_MIN
                #define INT8_MAX   SHRT_MAX
            #elif defined(INTEGER_INT8_BASE_INT)
                #define INT8_MIN   INT_MIN
                #define INT8_MAX   INT_MAX
            #elif defined(INTEGER_INT8_BASE_LONG)
                #define INT8_MIN   LONG_MIN
                #define INT8_MAX   LONG_MAX
            #elif defined(INTEGER_INT8_BASE_LLONG)
                #define INT8_MIN   (-127LL - 1LL)
                #define INT8_MAX   127LL
            #endif
        #endif
    #endif

    #ifdef UINT8_IS_DEFINED
        #ifndef UINT8_MAX
            #if defined(INTEGER_UINT8_BASE_UCHAR)
                #define UINT8_MAX  UCHAR_MAX
            #elif defined(INTEGER_UINT8_BASE_USHORT)
                #define UINT8_MAX  USHRT_MAX
            #elif defined(INTEGER_UINT8_BASE_UINT)
                #define UINT8_MAX  UINT_MAX
            #elif defined(INTEGER_UINT8_BASE_ULONG)
                #define UINT8_MAX  ULONG_MAX
            #elif defined(INTEGER_UINT8_BASE_ULLONG)
                #define UINT8_MAX  255ULL
            #endif
        #endif
    #endif

    #ifdef INT16_IS_DEFINED
        #ifndef INT16_MIN
            #if defined(INTEGER_INT16_BASE_SCHAR)
                #define INT16_MIN  SCHAR_MIN
                #define INT16_MAX  SCHAR_MAX
            #elif defined(INTEGER_INT16_BASE_SHORT)
                #define INT16_MIN  SHRT_MIN
                #define INT16_MAX  SHRT_MAX
            #elif defined(INTEGER_INT16_BASE_INT)
                #define INT16_MIN  INT_MIN
                #define INT16_MAX  INT_MAX
            #elif defined(INTEGER_INT16_BASE_LONG)
                #define INT16_MIN  LONG_MIN
                #define INT16_MAX  LONG_MAX
            #elif defined(INTEGER_INT16_BASE_LLONG)
                #define INT16_MIN  (-32767LL - 1LL)
                #define INT16_MAX  32767LL
            #endif
        #endif
    #endif

    #ifdef UINT16_IS_DEFINED
        #ifndef UINT16_MAX
            #if defined(INTEGER_UINT16_BASE_UCHAR)
                #define UINT16_MAX  UCHAR_MAX
            #elif defined(INTEGER_UINT16_BASE_USHORT)
                #define UINT16_MAX  USHRT_MAX
            #elif defined(INTEGER_UINT16_BASE_UINT)
                #define UINT16_MAX  UINT_MAX
            #elif defined(INTEGER_UINT16_BASE_ULONG)
                #define UINT16_MAX  ULONG_MAX
            #elif defined(INTEGER_UINT16_BASE_ULLONG)
                #define UINT16_MAX  65535ULL
            #endif
        #endif
    #endif

    #ifdef INT32_IS_DEFINED
        #ifndef INT32_MIN
            #if defined(INTEGER_INT32_BASE_SCHAR)
                #define INT32_MIN  SCHAR_MIN
                #define INT32_MAX  SCHAR_MAX
            #elif defined(INTEGER_INT32_BASE_SHORT)
                #define INT32_MIN  SHRT_MIN
                #define INT32_MAX  SHRT_MAX
            #elif defined(INTEGER_INT32_BASE_INT)
                #define INT32_MIN  INT_MIN
                #define INT32_MAX  INT_MAX
            #elif defined(INTEGER_INT32_BASE_LONG)
                #define INT32_MIN  LONG_MIN
                #define INT32_MAX  LONG_MAX
            #elif defined(INTEGER_INT32_BASE_LLONG)
                #define INT32_MIN  (-2147483647LL - 1LL)
                #define INT32_MAX  2147483647LL
            #endif
        #endif
    #endif

    #ifdef UINT32_IS_DEFINED
        #ifndef UINT32_MAX
            #if defined(INTEGER_UINT32_BASE_UCHAR)
                #define UINT32_MAX  UCHAR_MAX
            #elif defined(INTEGER_UINT32_BASE_USHORT)
                #define UINT32_MAX  USHRT_MAX
            #elif defined(INTEGER_UINT32_BASE_UINT)
                #define UINT32_MAX  UINT_MAX
            #elif defined(INTEGER_UINT32_BASE_ULONG)
                #define UINT32_MAX  ULONG_MAX
            #elif defined(INTEGER_UINT32_BASE_ULLONG)
                #define UINT32_MAX  4294967295ULL
            #endif
        #endif
    #endif

    #ifdef INT64_IS_DEFINED
        #ifndef INT64_MIN
            #if defined(INTEGER_INT64_BASE_SCHAR)
                #define INT64_MIN  SCHAR_MIN
                #define INT64_MAX  SCHAR_MAX
            #elif defined(INTEGER_INT64_BASE_SHORT)
                #define INT64_MIN  SHRT_MIN
                #define INT64_MAX  SHRT_MAX
            #elif defined(INTEGER_INT64_BASE_INT)
                #define INT64_MIN  INT_MIN
                #define INT64_MAX  INT_MAX
            #elif defined(INTEGER_INT64_BASE_LONG)
                #define INT64_MIN  LONG_MIN
                #define INT64_MAX  LONG_MAX
            #elif defined(INTEGER_INT64_BASE_LLONG)
                #define INT64_MIN  (-9223372036854775807LL - 1LL)
                #define INT64_MAX  9223372036854775807LL
            #endif
        #endif
    #endif

    #ifdef UINT64_IS_DEFINED
        #ifndef UINT64_MAX
            #if defined(INTEGER_UINT64_BASE_UCHAR)
                #define UINT64_MAX  UCHAR_MAX
            #elif defined(INTEGER_UINT64_BASE_USHORT)
                #define UINT64_MAX  USHRT_MAX
            #elif defined(INTEGER_UINT64_BASE_UINT)
                #define UINT64_MAX  UINT_MAX
            #elif defined(INTEGER_UINT64_BASE_ULONG)
                #define UINT64_MAX  ULONG_MAX
            #elif defined(INTEGER_UINT64_BASE_ULLONG)
                #define UINT64_MAX  18446744073709551615ULL
            #endif
        #endif
    #endif

    /* --------------------------------------------------------------------- */
    /* intmax_t / uintmax_t                                                   */
    /* --------------------------------------------------------------------- */

    #ifdef INT64_IS_DEFINED
        typedef int64_t   intmax_t;
        typedef uint64_t  uintmax_t;
        #ifndef INTMAX_MIN
            #define INTMAX_MIN   INT64_MIN
        #endif
        #ifndef INTMAX_MAX
            #define INTMAX_MAX   INT64_MAX
        #endif
        #ifndef UINTMAX_MAX
            #define UINTMAX_MAX  UINT64_MAX
        #endif
    #elif defined(INT32_IS_DEFINED)
        typedef int32_t   intmax_t;
        typedef uint32_t  uintmax_t;
        #ifndef INTMAX_MIN
            #define INTMAX_MIN   INT32_MIN
        #endif
        #ifndef INTMAX_MAX
            #define INTMAX_MAX   INT32_MAX
        #endif
        #ifndef UINTMAX_MAX
            #define UINTMAX_MAX  UINT32_MAX
        #endif
    #elif defined(INT16_IS_DEFINED)
        typedef int16_t   intmax_t;
        typedef uint16_t  uintmax_t;
        #ifndef INTMAX_MIN
            #define INTMAX_MIN   INT16_MIN
        #endif
        #ifndef INTMAX_MAX
            #define INTMAX_MAX   INT16_MAX
        #endif
        #ifndef UINTMAX_MAX
            #define UINTMAX_MAX  UINT16_MAX
        #endif
    #elif defined(INT8_IS_DEFINED)
        typedef int8_t    intmax_t;
        typedef uint8_t   uintmax_t;
        #ifndef INTMAX_MIN
            #define INTMAX_MIN   INT8_MIN
        #endif
        #ifndef INTMAX_MAX
            #define INTMAX_MAX   INT8_MAX
        #endif
        #ifndef UINTMAX_MAX
            #define UINTMAX_MAX  UINT8_MAX
        #endif
    #endif

    /* --------------------------------------------------------------------- */
    /* intptr_t / uintptr_t                                                   */
    /* --------------------------------------------------------------------- */

    #if _SIZEOF_VOID_P == 8
        #ifdef INT8_IS_DEFINED
            typedef int8_t    intptr_t;
            typedef uint8_t   uintptr_t;
            #ifndef INTPTR_MIN
                #define INTPTR_MIN   INT8_MIN
            #endif
            #ifndef INTPTR_MAX
                #define INTPTR_MAX   INT8_MAX
            #endif
            #ifndef UINTPTR_MAX
                #define UINTPTR_MAX  UINT8_MAX
            #endif
        #endif
    #elif _SIZEOF_VOID_P == 16
        #ifdef INT16_IS_DEFINED
            typedef int16_t   intptr_t;
            typedef uint16_t  uintptr_t;
            #ifndef INTPTR_MIN
                #define INTPTR_MIN   INT16_MIN
            #endif
            #ifndef INTPTR_MAX
                #define INTPTR_MAX   INT16_MAX
            #endif
            #ifndef UINTPTR_MAX
                #define UINTPTR_MAX  UINT16_MAX
            #endif
        #endif
    #elif _SIZEOF_VOID_P == 32
        #ifdef INT32_IS_DEFINED
            typedef int32_t   intptr_t;
            typedef uint32_t  uintptr_t;
            #ifndef INTPTR_MIN
                #define INTPTR_MIN   INT32_MIN
            #endif
            #ifndef INTPTR_MAX
                #define INTPTR_MAX   INT32_MAX
            #endif
            #ifndef UINTPTR_MAX
                #define UINTPTR_MAX  UINT32_MAX
            #endif
        #endif
    #elif _SIZEOF_VOID_P == 64
        #ifdef INT64_IS_DEFINED
            typedef int64_t   intptr_t;
            typedef uint64_t  uintptr_t;
            #ifndef INTPTR_MIN
                #define INTPTR_MIN   INT64_MIN
            #endif
            #ifndef INTPTR_MAX
                #define INTPTR_MAX   INT64_MAX
            #endif
            #ifndef UINTPTR_MAX
                #define UINTPTR_MAX  UINT64_MAX
            #endif
        #endif
    #endif

    /* --------------------------------------------------------------------- */
    /* size_t-related                                                         */
    /* --------------------------------------------------------------------- */

    #ifndef SIZE_MAX
        #define SIZE_MAX ((size_t)-1)
    #endif

#endif /* platform selection */

#endif /* INTEGER_H */