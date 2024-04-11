/** @file       clibs_logging.h
 *  @brief      Logging-related macros.
 *  @author     OpenTechCoder
 *  @copyright  MIT
 */
#ifndef CLIBS_LOGGING_H
#define CLIBS_LOGGING_H

#include <stdio.h>
#include <stdlib.h>

#define CLIBS_LOG_LEVEL_DEBUG 5
#define CLIBS_LOG_LEVEL_INFO  4
#define CLIBS_LOG_LEVEL_WARN  3
#define CLIBS_LOG_LEVEL_ERROR 2
#define CLIBS_LOG_LEVEL_FATAL 1
#define CLIBS_LOG_LEVEL_NONE  0

/** @def CLIBS_LOG_LEVEL
 *  @brief The logging level of an application.
 *
 *  Available logging levels: <tt>DEBUG</tt>, <tt>INFO</tt>, <tt>WARN</tt>, <tt>ERROR</tt> and <tt>FATAL</tt>.
 *  Logging levels are defined by macro variables of the same names. 
 */
#if DEBUG
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_DEBUG
#elif INFO
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_INFO
#elif WARN
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_WARN
#elif ERROR
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_ERROR
#elif FATAL
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_FATAL
#else
    #define CLIBS_LOG_LEVEL CLIBS_LOG_LEVEL_NONE
#endif

#ifndef END_OF_LINE
    #define END_OF_LINE  "\n"
#endif

/** @def     CLIBS_LOG_DEBUG(format, ...)
 *  @brief   <tt>DEBUG</tt>-level log
 *  @param   format The formated string.
 *
 *  The logs are available only when \c CLIBS_LOG_LEVEL is at <tt>DEBUG</tt>.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_DEBUG
    #define CLIBS_LOG_DEBUG(format, ...) { \
        fprintf(stderr, "[DEBUG] (%s:%d) " format "%s", \
            __FILE__, __LINE__, ##__VA_ARGS__, END_OF_LINE); \
    }
#else
    #define CLIBS_LOG_DEBUG(format, ...)
#endif

/** @def     CLIBS_LOG_INFO(format, ...)
 *  @brief   <tt>INFO</tt>-level log
 *  @param   format The formated string.
 *
 *  The logs are available only when \c CLIBS_LOG_LEVEL is at \c INFO or above.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_INFO
    #define CLIBS_LOG_INFO(format, ...) { \
        fprintf(stderr, "[INFO] " format "%s", \
            ##__VA_ARGS__, END_OF_LINE); \
    }
#else
    #define CLIBS_LOG_INFO(format, ...)
#endif

/** @def     CLIBS_LOG_WARN(format, ...)
 *  @brief   <tt>WARN</tt>-level log
 *  @param   format The formated string.
 *
 *  The logs are available only when \c CLIBS_LOG_LEVEL is at \c WARN or above.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_WARN
    #define CLIBS_LOG_WARN(format, ...) { \
        fprintf(stderr, "[WARN] " format "%s", \
            ##__VA_ARGS__, END_OF_LINE); \
    }
#else
    #define CLIBS_LOG_WARN(format, ...)
#endif

/** @def     CLIBS_LOG_ERROR(format, ...)
 *  @brief   <tt>ERROR</tt>-level log
 *  @param   format The formated string.
 *
 *  The logs are available only when \c CLIBS_LOG_LEVEL is at \c ERROR or above.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_ERROR
    #define CLIBS_LOG_ERROR(format, ...) { \
        fprintf(stderr, "[ERROR] " format "%s", \
            ##__VA_ARGS__, END_OF_LINE); \
        exit(1); \
    }
#else
    #define CLIBS_LOG_ERROR(format, ...)
#endif

/** @def     CLIBS_LOG_FATAL(format, ...)
 *  @brief   <tt>FATAL</tt>-level log
 *  @param   format The formated string.
 *
 *  The logs are available only when \c CLIBS_LOG_LEVEL is at \c FATAL or above.
 */
#if CLIBS_LOG_LEVEL >= CLIBS_LOG_LEVEL_FATAL
    #define CLIBS_LOG_FATAL(format, ...) { \
        fprintf(stderr, "[FATAL] " format "%s", \
            ##__VA_ARGS__, END_OF_LINE); \
        abort(); \
    }
#else
    #define CLIBS_LOG_FATAL(format, ...)
#endif

#endif  /* CLIBS_LOGGING_H */