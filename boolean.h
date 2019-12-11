/* boolean.h - boolean type for C.
   Copyright (c) 2019 Michael Chen. Licensed under MIT. */
#ifndef CLIBS_BOOLEAN_H
#define CLIBS_BOOLEAN_H

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
