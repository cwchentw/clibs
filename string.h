#ifndef CLIBS_STRING_H
#define CLIBS_STRING_H

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


#ifdef __cplusplus
extern "C" {
#endif

BOOL string_is_equal(char *a, char *b);
BOOL string_starts_with(char *a, char *b);
BOOL string_contains(char *a, char *b);

/* string_is_space_only will skip end of line. */
BOOL string_is_space_only(char *a);

#ifdef __cplusplus
}
#endif

#endif  /* CLIBS_STRING_H */
