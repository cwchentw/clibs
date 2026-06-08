/** @file       boolean.h
 *  @brief      Custom Boolean type for C (portable & self-contained)
 *  @author     ByteBard
 *  @copyright  MIT
 *
 *  Note: Win32 API provides its own BOOL type. This header is not intended for use in Win32 API programming.
 */

#ifndef CLIBS_BOOLEAN_H
#define CLIBS_BOOLEAN_H

/* Custom boolean type. */
#ifndef _WINDOWS_
#ifdef __cplusplus
    #ifndef _BOOL_IS_DEFINED
        typedef bool BOOL;
        #define FALSE  false
        #define TRUE   true
        #define _BOOL_IS_DEFINED
    #endif
#else
    #if __STDC_VERSION__ < 199901L
        #ifndef _BOOL_IS_DEFINED
            typedef char BOOL;
            #define FALSE  0
            #define TRUE   1
            #define _BOOL_IS_DEFINED
        #endif
    #else
        #ifndef _BOOL_IS_DEFINED
            #include <stdbool.h>
            typedef bool BOOL;
            #define FALSE  false
            #define TRUE   true
            #define _BOOL_IS_DEFINED
        #endif
    #endif
#endif
#endif

#endif  /* CLIBS_BOOLEAN_H */
