/** @file       boolean.h
 *  @brief      Custom Boolean type for C
 *  @author     ByteBard
 *  @copyright  MIT
 *
 *  Win32 API provides its own \b BOOL type. Hence, this header is useless in Win32 API programming.
 */
#ifndef CLIBS_BOOLEAN_H
#define CLIBS_BOOLEAN_H

/** @typedef  BOOL
 *  @brief    Custom boolean type
 *
 *  @def    FALSE
 *  @brief  False in boolean type
 *
 *  @def    TRUE
 *  @brief  True in boolean type
 */
#if _WIN32
    /* Windows API provides its own BOOL type.
    
       TRUE and FALSE is availabe as well. */
    #include <windows.h>
#else
#ifdef __cplusplus
    /* C++ provides native bool type. */
    #ifndef _BOOL_IS_DEFINED
        typedef bool BOOL;
        #define FALSE  false
        #define TRUE   true
        #define _BOOL_IS_DEFINED
    #endif  /* BOOL */
#else
    #if __STDC_VERSION__ < 199901L
        /* Home-made BOOL type for ANSI C. */
        #ifndef _BOOL_IS_DEFINED
            typedef unsigned char BOOL;
            #define FALSE  0
            #define TRUE   1
            #define _BOOL_IS_DEFINED
        #endif  /* BOOL */
    #else
        /* `bool` type is available after C99. */
        #ifndef _BOOL_IS_DEFINED
            #include <stdbool.h>
            typedef bool BOOL;
            #define FALSE  false
            #define TRUE   true
            #define _BOOL_IS_DEFINED
        #endif  /* BOOL */
    #endif  /* C89 */
#endif  /* __cplusplus */
#endif  /* Windows. */

#endif  /* CLIBS_BOOLEAN_H */
