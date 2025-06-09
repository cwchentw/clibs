/** @file       boolean.h
 *  @brief      Custom Boolean type for C (portable & self-contained)
 *  @author     ByteBard
 *  @copyright  MIT
 *
 *  Note: Win32 API provides its own BOOL type. This header is not intended for use in Win32 API programming.
 */

#ifndef CLIBS_BOOLEAN_H
#define CLIBS_BOOLEAN_H

#if defined(_WIN32)
    /* On Windows, use the native Win32 BOOL */
    #include <windows.h>

#else  /* Not Windows */

    #ifndef CLIBS_BOOL_DEFINED

        #if defined(__cplusplus)
            typedef bool BOOL;
            #define TRUE  true
            #define FALSE false

        #elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
            #include <stdbool.h>
            typedef bool BOOL;
            #define TRUE  true
            #define FALSE false

        #else
            typedef unsigned char BOOL;
            #define TRUE  1
            #define FALSE 0
        #endif

        #define CLIBS_BOOL_DEFINED
    #endif  /* CLIBS_BOOL_DEFINED */

#endif  /* _WIN32 */

#endif  /* CLIBS_BOOLEAN_H */
