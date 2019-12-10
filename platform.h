#ifndef CLIBS_PLATFORM_H
#define CLIBS_PLATFORM_H

#ifdef _WIN32
    #define END_OF_LINE "\r\n"
#elif __unix__ || __APPLE__
    #define END_OF_LINE "\n"
#else
    #error "Unsupported platform"
#endif

#ifdef _WIN32
    #define DIRECTORY_SEPARATOR "\\"
#elif __unix__ || __APPLE__
    #define DIRECTORY_SEPARATOR "/"
#else
    #error "Unsupported platform"
#endif

#endif  /* CLIBS_PLATFORM_H */
