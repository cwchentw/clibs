/** @file       boolean.h
 *  @brief      Boolean type for C
 *  @author     Michael Chen
 *  @copyright  MIT
 * 
 *  This header may fail on Windows because Win32 C API defines its own BOOL type.
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

#endif  /* CLIBS_BOOLEAN_H */
