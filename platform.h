/** @file       platform.h
 *  @brief      Platform-specific data
 *  @author     Michael Chen
 *  @copyright  MIT
 *
 *  The macro definitions seen in this document represent the platform data of Unix.
 */
#ifndef CLIBS_PLATFORM_H
#define CLIBS_PLATFORM_H

/** @def END_OF_LINE
 *  @brief End of line of specific host.
 *
 *  Currently, EOL_OF_LINE works on Windows and Unix.
 */
#ifndef END_OF_LINE
    #ifdef _WIN32
        #define END_OF_LINE "\r\n"
    #elif __unix__ || __unix || unix || __APPLE__
        #define END_OF_LINE "\n"
    #else
        #error "Unsupported platform"
    #endif
#endif  /* END_OF_LINE */

/** @def DIRECTORY_SEPARATOR
 *  @brief Directory separator of specific host.
 *
 *  Currently, DIRECTORY_SEPARATOR works on Windows and Unix.
 */
#ifndef DIRECTORY_SEPARATOR
    #ifdef _WIN32
        #define DIRECTORY_SEPARATOR "\\"
    #elif __unix__ || __unix || unix || __APPLE__
        #define DIRECTORY_SEPARATOR "/"
    #else
        #error "Unsupported platform"
    #endif
#endif  /* DIRECTORY_SEPARATOR */

/** @def SEARCH_PATH_SEPARATOR
 *  @brief Search path separator of specific host.
 * 
 *  Currently, SEARCH_PATH_SEPARATOR works on Windows and Unix.
 */
#ifndef SEARCH_PATH_SEPARATOR
    #ifdef _WIN32
        #define SEARCH_PATH_SEPARATOR ";"
    #elif __unix__ || __unix || unix || __APPLE__
        #define SEARCH_PATH_SEPARATOR ":"
    #else
        #error "Unsupported platform"
    #endif
#endif

#endif  /* CLIBS_PLATFORM_H */
