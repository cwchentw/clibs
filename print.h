/**
 * @file    print.h
 * @brief   Thread-aware printing macros with redirect support.
 *
 * This module provides print macros (like printf, puts) that redirect output
 * to thread-local FILE* streams, with fallback to stdout/stderr.
 * Intended for portable, lock-free console or file printing.
 *
 * @author  ByteBard
 * @copyright MIT
 */

#ifndef CLIBS_PRINT_H
#define CLIBS_PRINT_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sets thread-local output and error streams.
 *
 * @param out  Stream for normal output (default: stdout).
 * @param err  Stream for error output (default: stderr).
 */
void clibs_set_output(FILE *out, FILE *err);

/**
 * @brief Gets current output stream (fallback: stdout).
 */
FILE *clibs_get_out(void);

/**
 * @brief Gets current error stream (fallback: stderr).
 */
FILE *clibs_get_err(void);

/**
 * @def PRINT
 * @brief Print to output stream (like printf).
 */
#define PRINT(fmt, ...) \
    do { fprintf(clibs_get_out(), fmt, ##__VA_ARGS__); } while (0)

/**
 * @def PERROR
 * @brief Print to error stream (like fprintf(stderr,...)).
 */
#define PERROR(fmt, ...) \
    do { fprintf(clibs_get_err(), fmt, ##__VA_ARGS__); } while (0)

/**
 * @def PUTS
 * @brief Print one line to output stream, with newline.
 */
#define PUTS(fmt, ...) \
    do { fprintf(clibs_get_out(), fmt "\n", ##__VA_ARGS__); } while (0)

/**
 * @def PUTERR
 * @brief Print one line to error stream, with newline.
 */
#define PUTERR(fmt, ...) \
    do { fprintf(clibs_get_err(), fmt "\n", ##__VA_ARGS__); } while (0)

/**
 * @def DEBUG_INFO
 * @brief Print debug message with file and line info.
 */
#define DEBUG_INFO(fmt, ...) \
    do { fprintf(clibs_get_err(), "(%s:%d) " fmt "\n", \
        __FILE__, __LINE__, ##__VA_ARGS__); } while (0)

#ifdef __cplusplus
}
#endif

#endif /* CLIBS_PRINT_H */
