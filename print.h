/* print_function.h - console printing utilities.
   Copyright (c) 2019 Michael Chen. Licensed under MIT. */
#ifndef CLIBS_PRINT_FUNCTION_H
#define CLIBS_PRINT_FUNCTION_H

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

#ifndef PRINT
    #define PRINT(format, ...) { \
        fprintf(stdout, format, ##__VA_ARGS__); \
    }
#endif

#ifndef PERROR
    #define PERROR(format, ...) { \
        fprintf(stderr, format, ##__VA_ARGS__); \
    }
#endif

#ifndef PUTS
    #define PUTS(format, ...) { \
        fprintf(stdout, format "%s", ##__VA_ARGS__, END_OF_LINE); \
    }
#endif

#ifndef PUTERR
    #define PUTERR(format, ...) { \
        fprintf(stderr, format "%s", ##__VA_ARGS__, END_OF_LINE); \
    }
#endif

#ifndef DEBUG_INFO
    #define DEBUG_INFO(format, ...) { \
        fprintf(stderr, "(%s:%d) " format "%s", \
            __FILE__, __LINE__, ##__VA_ARGS__, END_OF_LINE); \
    }
#endif

#endif  /* CLIBS_PRINT_FUNCTION_H */
