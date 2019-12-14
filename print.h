/** @file       print.h
 *  @brief      Console printing related macros
 *  @author     Michael Chen
 *  @copyright  MIT
 */
#ifndef CLIBS_PRINT_H
#define CLIBS_PRINT_H

#ifdef __cplusplus
    #include <cstdio>
#else
    #include <stdio.h>
#endif

#ifndef END_OF_LINE
    #if _WIN32
        #define END_OF_LINE  "\r\n"
    #elif __unix__ || __APPLE__
        #define END_OF_LINE  "\n"
    #else
        #error "Unsupported"
    #endif
#endif

/** @def   PRINT(format, ...)
 *  @brief Print formated string to \b stdout without trailing EOL.
 *
 *  Basically, \b PRINT is just a repackaged \a printf function seen
 *  \b stdio.h.
 */
#ifndef PRINT
    #define PRINT(format, ...) { \
        fprintf(stdout, format, ##__VA_ARGS__); \
    }
#endif

/** @def   PERROR(format, ...)
 *  @brief Print formated string to \b stderr without trailing EOL.
 *
 *  \b PERROR works as \b PRINT, but to \b stderr.
 */
#ifndef PERROR
    #define PERROR(format, ...) { \
        fprintf(stderr, format, ##__VA_ARGS__); \
    }
#endif

/** @def   PUTS(format, ...)
 *  @brief Print formated string to \b stdout with trailing EOL.
 *
 *  The EOL will change according to the host environment.
 */
#ifndef PUTS
    #define PUTS(format, ...) { \
        fprintf(stdout, format "%s", ##__VA_ARGS__, END_OF_LINE); \
    }
#endif

/** @def   PUTERR(format, ...)
 *  @brief Print formated string to \b stderr with trailing EOL.
 *
 *  The EOL will change according to the host environment.
 */
#ifndef PUTERR
    #define PUTERR(format, ...) { \
        fprintf(stderr, format "%s", ##__VA_ARGS__, END_OF_LINE); \
    }
#endif

/** @def DEBUG_INFO(format, ...)
 *  @brief Print formated debug message to \b stderr with trailing EOL.
 *
 *  \b DEBUG_INFO works similarly to \b PUTERR but adds source file
 *  and line number. Hence, developers can track the location of the
 *  message more easily.
 */
#ifndef DEBUG_INFO
    #define DEBUG_INFO(format, ...) { \
        fprintf(stderr, "(%s:%d) " format "%s", \
            __FILE__, __LINE__, ##__VA_ARGS__, END_OF_LINE); \
    }
#endif

#endif  /* CLIBS_PRINT_H */
