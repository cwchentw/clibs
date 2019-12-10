#ifndef CLIBS_PRINT_FUNCTION_H
#define CLIBS_PRINT_FUNCTION_H

#ifndef END_OF_LINE
    #if _WIN32
        #define END_OF_LINE  "\r\n"
    #elif __unix__ || __APPLE__
        #define END_OF_LINE  "\n"
    #else
        #error "Unsupported"
    #endif
#endif

#define PRINT(format, ...) { \
    fprintf(stdout, format, ##__VA_ARGS__); \
}

#define PERROR(format, ...) { \
    fprintf(stderr, format, ##__VA_ARGS__); \
}

#define PUTS(format, ...) { \
    fprintf(stdout, format "%s", ##__VA_ARGS__, END_OF_LINE); \
}

#define PUTERR(format, ...) { \
    fprintf(stderr, format "%s", ##__VA_ARGS__, END_OF_LINE); \
}

#define DEBUG(format, ...) { \
    fprintf(stderr, "(%s:%d) " format "%s", \
        __FILE__, __LINE__, ##__VA_ARGS__, END_OF_LINE); \
}

#endif  /* CLIBS_PRINT_FUNCTION_H */
