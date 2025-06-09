/*
 * @file      integer.h
 * @brief     Fixed-width integer types for C (portable across platforms).
 * @author    ByteBard
 * @copyright MIT
 *
 * This header provides fixed-width integer types (e.g., int32_t, uint64_t)
 * for C89, C99, and MSVC environments. For pre-C99 compilers, run
 * `get_sizeof_data_type.c` to generate `_sizeof_data_type.h` with
 * platform-specific size definitions.
 *
 * @note This header is experimental. Use with caution.
 */

#ifndef INTEGER_H
#define INTEGER_H

/*
 * @typedef int8_t
 * @brief   8-bit signed integer
 *
 * @typedef uint8_t
 * @brief   8-bit unsigned integer
 *
 * @typedef int16_t
 * @brief   16-bit signed integer
 *
 * @typedef uint16_t
 * @brief   16-bit unsigned integer
 *
 * @typedef int32_t
 * @brief   32-bit signed integer
 *
 * @typedef uint32_t
 * @brief   32-bit unsigned integer
 *
 * @typedef int64_t
 * @brief   64-bit signed integer
 *
 * @typedef uint64_t
 * @brief   64-bit unsigned integer
 *
 * @def     INT8_IS_DEFINED
 * @brief   Flag indicating 8-bit signed integer is defined
 *
 * @def     UINT8_IS_DEFINED
 * @brief   Flag indicating 8-bit unsigned integer is defined
 *
 * @def     INT16_IS_DEFINED
 * @brief   Flag indicating 16-bit signed integer is defined
 *
 * @def     UINT16_IS_DEFINED
 * @brief   Flag indicating 16-bit unsigned integer is defined
 *
 * @def     INT32_IS_DEFINED
 * @brief   Flag indicating 32-bit signed integer is defined
 *
 * @def     UINT32_IS_DEFINED
 * @brief   Flag indicating 32-bit unsigned integer is defined
 *
 * @def     INT64_IS_DEFINED
 * @brief   Flag indicating 64-bit signed integer is defined
 *
 * @def     UINT64_IS_DEFINED
 * @brief   Flag indicating 64-bit unsigned integer is defined
 */

/* Definition for Microsoft Visual C++ */
#if defined(_MSC_VER)
    typedef signed __int8     int8_t;
    typedef unsigned __int8   uint8_t;
    typedef signed __int16    int16_t;
    typedef unsigned __int16  uint16_t;
    typedef signed __int32    int32_t;
    typedef unsigned __int32  uint32_t;
    typedef signed __int64    int64_t;
    typedef unsigned __int64  uint64_t;
    #define INT8_IS_DEFINED
    #define UINT8_IS_DEFINED
    #define INT16_IS_DEFINED
    #define UINT16_IS_DEFINED
    #define INT32_IS_DEFINED
    #define UINT32_IS_DEFINED
    #define INT64_IS_DEFINED
    #define UINT64_IS_DEFINED

/* Definition for C99 and later */
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #include <stdint.h>
    #define INT8_IS_DEFINED
    #define UINT8_IS_DEFINED
    #define INT16_IS_DEFINED
    #define UINT16_IS_DEFINED
    #define INT32_IS_DEFINED
    #define UINT32_IS_DEFINED
    #define INT64_IS_DEFINED
    #define UINT64_IS_DEFINED

/* Fallback definition for C89 (with custom sizeof detection) */
#else
    #include "_sizeof_data_type.h"

    /* Use char */
    #if _SIZEOF_CHAR >= 32
        typedef signed char    int32_t;
        typedef unsigned char  uint32_t;
        #define INT32_IS_DEFINED
        #define UINT32_IS_DEFINED
    #elif _SIZEOF_CHAR >= 16
        typedef signed char    int16_t;
        typedef unsigned char  uint16_t;
        #define INT16_IS_DEFINED
        #define UINT16_IS_DEFINED
    #else
        typedef signed char    int8_t;
        typedef unsigned char  uint8_t;
        #define INT8_IS_DEFINED
        #define UINT8_IS_DEFINED
    #endif

    /* Use short */
    #if _SIZEOF_SHORT >= 32
        typedef signed short    int32_t;
        typedef unsigned short  uint32_t;
        #define INT32_IS_DEFINED
        #define UINT32_IS_DEFINED
    #else
        #ifndef INT16_IS_DEFINED
        typedef signed short    int16_t;
        typedef unsigned short  uint16_t;
        #define INT16_IS_DEFINED
        #define UINT16_IS_DEFINED
        #endif
    #endif

    /* Use int */
    #if _SIZEOF_INT >= 64
        #ifndef INT64_IS_DEFINED
        typedef signed int      int64_t;
        typedef unsigned int    uint64_t;
        #define INT64_IS_DEFINED
        #define UINT64_IS_DEFINED
        #endif
    #elif _SIZEOF_INT >= 32
        #ifndef INT32_IS_DEFINED
        typedef signed int      int32_t;
        typedef unsigned int    uint32_t;
        #define INT32_IS_DEFINED
        #define UINT32_IS_DEFINED
        #endif
    #else
        #ifndef INT16_IS_DEFINED
        typedef signed int      int16_t;
        typedef unsigned int    uint16_t;
        #define INT16_IS_DEFINED
        #define UINT16_IS_DEFINED
        #endif
    #endif

    /* Use long */
    #if _SIZEOF_LONG >= 64
        #ifndef INT64_IS_DEFINED
        typedef signed long     int64_t;
        typedef unsigned long   uint64_t;
        #define INT64_IS_DEFINED
        #define UINT64_IS_DEFINED
        #endif
    #else
        #ifndef INT32_IS_DEFINED
        typedef signed long     int32_t;
        typedef unsigned long   uint32_t;
        #define INT32_IS_DEFINED
        #define UINT32_IS_DEFINED
        #endif
    #endif

    /* Use long long (GCC / Clang extension) */
    #if defined(__GNUC__) || defined(__clang__)
        #ifndef INT64_IS_DEFINED
            #if _SIZEOF_LONG_LONG >= 64
            typedef signed long long    int64_t;
            typedef unsigned long long  uint64_t;
            #define INT64_IS_DEFINED
            #define UINT64_IS_DEFINED
            #endif
        #endif
    #endif

#endif /* End of fallback */

#endif /* INTEGER_H */
