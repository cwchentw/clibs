/**
 * @file    clibs_logging.h
 * @brief   Thread-local lightweight logging macros for C.
 * 
 * This logger provides per-thread output support without locking,
 * and logs messages to stderr by default unless redirected.
 * 
 * Logging level is determined at compile-time via macros like DEBUG, INFO, etc.
 * Output macros are printf-style and safely fallback to stderr.
 * 
 * @author  ByteBard
 * @copyright MIT
 */

#ifndef CLIBS_LOGGING_H
#define CLIBS_LOGGING_H

#include <stdio.h>

/**
 * @defgroup CLIBS_LOG_LEVELS Logging Level Definitions
 * @{
 */
#define CLIBS_LOG_LEVEL_DEBUG 5
#define CLIBS_LOG_LEVEL_INFO  4
#define CLIBS_LOG_LEVEL_WARN  3
#define CLIBS_LOG_LEVEL_ERROR 2
#define CLIBS_LOG_LEVEL_FATAL 1
#define CLIBS_LOG_LEVEL_NONE  0
/** @} */

/**
 * @def CLIBS_LOG_LEVEL
 * @brief Logging verbosity level for compile-time filtering.
 *
 * Set one of DEBUG / INFO / WARN / ERROR / FATAL before including this header.
 */
#if defined(DEBUG)
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_DEBUG
#elif defined(INFO)
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_INFO
#elif defined(WARN)
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_WARN
#elif defined(ERROR)
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_ERROR
#elif defined(FATAL)
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_FATAL
#else
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_NONE
#endif

/**
 * @brief Sets thread-local output streams.
 *
 * @param out  Output stream for general messages (default: stdout).
 * @param err  Output stream for log messages (default: stderr).
 */
void clibs_set_output(FILE *out, FILE *err);

/**
 * @brief Returns the current thread-local output stream (fallback: stdout).
 *
 * @return FILE* output stream for general messages.
 */
FILE *clibs_get_out(void);

/**
 * @brief Returns the current thread-local error stream (fallback: stderr).
 *
 * @return FILE* output stream for log messages.
 */
FILE *clibs_get_err(void);

/**
 * @def CLIBS_LOG_DEBUG
 * @brief Logs a debug message if level is DEBUG or higher.
 * @param fmt printf-style format string.
 * @param ... optional arguments.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_DEBUG
# define CLIBS_LOG_DEBUG(fmt, ...) \
    do { fprintf(clibs_get_err(), "[DEBUG] (%s:%d) " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); } while (0)
#else
# define CLIBS_LOG_DEBUG(fmt, ...) do {} while (0)
#endif

/**
 * @def CLIBS_LOG_INFO
 * @brief Logs an info message if level is INFO or higher.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_INFO
# define CLIBS_LOG_INFO(fmt, ...) \
    do { fprintf(clibs_get_err(), "[INFO] " fmt "\n", ##__VA_ARGS__); } while (0)
#else
# define CLIBS_LOG_INFO(fmt, ...) do {} while (0)
#endif

/**
 * @def CLIBS_LOG_WARN
 * @brief Logs a warning message if level is WARN or higher.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_WARN
# define CLIBS_LOG_WARN(fmt, ...) \
    do { fprintf(clibs_get_err(), "[WARN] " fmt "\n", ##__VA_ARGS__); } while (0)
#else
# define CLIBS_LOG_WARN(fmt, ...) do {} while (0)
#endif

/**
 * @def CLIBS_LOG_ERROR
 * @brief Logs an error message and exits if level is ERROR or higher.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_ERROR
# define CLIBS_LOG_ERROR(fmt, ...) \
    do { \
        fprintf(clibs_get_err(), "[ERROR] " fmt "\n", ##__VA_ARGS__); \
        exit(1); \
    } while (0)
#else
# define CLIBS_LOG_ERROR(fmt, ...) do {} while (0)
#endif

/**
 * @def CLIBS_LOG_FATAL
 * @brief Logs a fatal message and aborts if level is FATAL or higher.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_FATAL
# define CLIBS_LOG_FATAL(fmt, ...) \
    do { \
        fprintf(clibs_get_err(), "[FATAL] " fmt "\n", ##__VA_ARGS__); \
        abort(); \
    } while (0)
#else
# define CLIBS_LOG_FATAL(fmt, ...) do {} while (0)
#endif

#endif /* CLIBS_LOGGING_H */
