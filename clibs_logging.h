/**
 * @file    clibs_logging.h
 * @brief   Thread-local lightweight logging macros for C.
 *
 * This module provides lightweight, compile-time filtered logging macros
 * for C programs. Log output is written to the current thread-local error
 * stream returned by clibs_get_err(), with fallback to stderr.
 *
 * Users may set CLIBS_LOG_LEVEL before including this header:
 *
 *   #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_DEBUG
 *   #include "clibs_logging.h"
 *
 * If CLIBS_LOG_LEVEL is not defined, logging is disabled by default.
 *
 * This header intentionally does not enforce any build flag convention
 * such as DEBUG or NDEBUG, and it does not terminate the process in any
 * logging macro. Process control remains the caller's responsibility.
 *
 * @author  ByteBard
 * @copyright MIT
 */

#ifndef CLIBS_LOGGING_H
#define CLIBS_LOGGING_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CLIBS_LOG_LEVELS Logging level definitions
 * @brief Compile-time logging verbosity levels.
 * @{
 */
#define CLIBS_LOG_LEVEL_NONE   0
#define CLIBS_LOG_LEVEL_FATAL  1
#define CLIBS_LOG_LEVEL_ERROR  2
#define CLIBS_LOG_LEVEL_WARN   3
#define CLIBS_LOG_LEVEL_INFO   4
#define CLIBS_LOG_LEVEL_DEBUG  5
/** @} */

/**
 * @def CLIBS_LOG_LEVEL
 * @brief Compile-time logging verbosity level.
 *
 * Define this macro before including this header, for example:
 *
 *   #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_DEBUG
 *
 * If not defined, CLIBS_LOG_LEVEL defaults to CLIBS_LOG_LEVEL_NONE.
 */
#ifndef CLIBS_LOG_LEVEL
#define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_NONE
#endif

/**
 * @brief Sets thread-local output streams.
 *
 * @param out  Output stream for general messages (default fallback: stdout).
 * @param err  Output stream for log messages (default fallback: stderr).
 */
void clibs_set_output(FILE *out, FILE *err);

/**
 * @brief Returns the current thread-local output stream.
 *
 * Falls back to stdout if no thread-local output stream is set.
 *
 * @return FILE* current output stream.
 */
FILE *clibs_get_out(void);

/**
 * @brief Returns the current thread-local error stream.
 *
 * Falls back to stderr if no thread-local error stream is set.
 *
 * @return FILE* current error stream.
 */
FILE *clibs_get_err(void);

/**
 * @def CLIBS_LOG_DEBUG
 * @brief Logs a debug message with file and line information.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_DEBUG
#define CLIBS_LOG_DEBUG(fmt, ...)                                           \
    do {                                                                    \
        fprintf(clibs_get_err(), "[DEBUG] (%s:%d) " fmt "\n",               \
                __FILE__, __LINE__, ##__VA_ARGS__);                         \
    } while (0)
#else
#define CLIBS_LOG_DEBUG(...) ((void)0)
#endif

/**
 * @def CLIBS_LOG_INFO
 * @brief Logs an informational message.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_INFO
#define CLIBS_LOG_INFO(fmt, ...)                                            \
    do {                                                                    \
        fprintf(clibs_get_err(), "[INFO] " fmt "\n", ##__VA_ARGS__);        \
    } while (0)
#else
#define CLIBS_LOG_INFO(...) ((void)0)
#endif

/**
 * @def CLIBS_LOG_WARN
 * @brief Logs a warning message.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_WARN
#define CLIBS_LOG_WARN(fmt, ...)                                            \
    do {                                                                    \
        fprintf(clibs_get_err(), "[WARN] " fmt "\n", ##__VA_ARGS__);        \
    } while (0)
#else
#define CLIBS_LOG_WARN(...) ((void)0)
#endif

/**
 * @def CLIBS_LOG_ERROR
 * @brief Logs an error message.
 *
 * This macro only logs. It does not terminate the process.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_ERROR
#define CLIBS_LOG_ERROR(fmt, ...)                                           \
    do {                                                                    \
        fprintf(clibs_get_err(), "[ERROR] " fmt "\n", ##__VA_ARGS__);       \
    } while (0)
#else
#define CLIBS_LOG_ERROR(...) ((void)0)
#endif

/**
 * @def CLIBS_LOG_FATAL
 * @brief Logs a fatal message with file and line information.
 *
 * This macro only logs. It does not abort the process.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_FATAL
#define CLIBS_LOG_FATAL(fmt, ...)                                           \
    do {                                                                    \
        fprintf(clibs_get_err(), "[FATAL] (%s:%d) " fmt "\n",               \
                __FILE__, __LINE__, ##__VA_ARGS__);                         \
    } while (0)
#else
#define CLIBS_LOG_FATAL(...) ((void)0)
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLIBS_LOGGING_H */
