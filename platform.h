/* platform.h - platform specific data for C.
   Copyright (c) 2019 Michael Chen. Licensed under MIT. */
#ifndef CLIBS_PLATFORM_H
#define CLIBS_PLATFORM_H

#ifndef END_OF_LINE
    #ifdef _WIN32
        #define END_OF_LINE "\r\n"
    #elif __unix__ || __APPLE__
        #define END_OF_LINE "\n"
    #else
        #error "Unsupported platform"
    #endif
#endif  /* END_OF_LINE */

#ifndef DIRECTORY_SEPARATOR
    #ifdef _WIN32
        #define DIRECTORY_SEPARATOR "\\"
    #elif __unix__ || __APPLE__
        #define DIRECTORY_SEPARATOR "/"
    #else
        #error "Unsupported platform"
    #endif
#endif

#endif  /* CLIBS_PLATFORM_H */
