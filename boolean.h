/** @file       boolean.h
 *  @brief      Boolean type for C
 *  @author     Michael Chen
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

#endif  /* CLIBS_BOOLEAN_H */
