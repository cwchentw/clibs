/**
 * @file    clibs_logging.c
 * @brief   Thread-local output stream implementation for clibs_logger.
 */

#include "clibs_logging.h"

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    #define THREAD_LOCAL _Thread_local
#elif defined(__cplusplus)
    #define THREAD_LOCAL thread_local
#else
    #define THREAD_LOCAL __thread
#endif

/**
 * @brief Per-thread output stream for stdout-equivalent messages.
 */
THREAD_LOCAL FILE *clibs_out = NULL;

/**
 * @brief Per-thread output stream for logging (stderr by default).
 */
THREAD_LOCAL FILE *clibs_err = NULL;

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
