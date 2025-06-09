/** @file       print.h
 *  @brief      Thread-safe console printing macros with redirect support
 *  @author     ByteBard
 *  @copyright  MIT
 */

#ifndef CLIBS_PRINT_H
#define CLIBS_PRINT_H

#ifdef __cplusplus
    #include <cstdio>
#else
    #include <stdio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Cross-platform thread-local definition */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    #define THREAD_LOCAL _Thread_local
#elif defined(__cplusplus)
    #define THREAD_LOCAL thread_local
#else
    #define THREAD_LOCAL __thread
#endif

/* Per-thread output targets */
extern THREAD_LOCAL FILE *clibs_out;
extern THREAD_LOCAL FILE *clibs_err;

/* Set thread-local output streams */
void clibs_set_output(FILE *out, FILE *err);

/* Get current output targets with fallback to stdout/stderr */
FILE *clibs_get_out(void);
FILE *clibs_get_err(void);

/* Macros */
#ifndef PRINT
#define PRINT(fmt, ...) \
    do { fprintf(clibs_get_out(), fmt, ##__VA_ARGS__); } while (0)
#endif

#ifndef PERROR
#define PERROR(fmt, ...) \
    do { fprintf(clibs_get_err(), fmt, ##__VA_ARGS__); } while (0)
#endif

#ifndef PUTS
#define PUTS(fmt, ...) \
    do { fprintf(clibs_get_out(), fmt "%s", ##__VA_ARGS__, "\n"); } while (0)
#endif

#ifndef PUTERR
#define PUTERR(fmt, ...) \
    do { fprintf(clibs_get_err(), fmt "%s", ##__VA_ARGS__, "\n"); } while (0)
#endif

#ifndef DEBUG_INFO
#define DEBUG_INFO(fmt, ...) \
    do { fprintf(clibs_get_err(), "(%s:%d) " fmt "%s", \
        __FILE__, __LINE__, ##__VA_ARGS__, "\n"); } while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLIBS_PRINT_H */
