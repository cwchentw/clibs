/** @file       print.c
 *  @brief      Implementation for thread-safe print redirection
 *  @author     ByteBard
 *  @copyright  MIT
 */

#include "print.h"

/* Thread-local output streams */
THREAD_LOCAL FILE *clibs_out = NULL;
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
