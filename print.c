/**
 * @file    print.c
 * @brief   Implementation of thread-local output streams for print macros.
 */

#include "print.h"

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    #define THREAD_LOCAL _Thread_local
#elif defined(__cplusplus)
    #define THREAD_LOCAL thread_local
#else
    #define THREAD_LOCAL __thread
#endif

/* internal thread-local streams */
static THREAD_LOCAL FILE *clibs_out = NULL;
static THREAD_LOCAL FILE *clibs_err = NULL;

void clibs_set_output(FILE *out, FILE *err) {
    clibs_out = out;
    clibs_err = err;
}

FILE *clibs_get_out(void) {
    return clibs_out ? clibs_out : stdout;
}

FILE *clibs_get_err(void) {
    return clibs_err ? clibs_err : stderr;
}
