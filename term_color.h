/** @file       term_color.h
 *  @brief      Add colors, either foreground or background, on console environment.
 *  @author     Michelle Chen
 *  @copyright  MIT
 *
 * Windows is not supported.
 */
#ifndef CLIBS_TERM_COLOR
#define CLIBS_TERM_COLOR

#if _WIN32
    #error "term_color.h is not supported"
#endif

/** @typedef  term_color_t
 *  @brief    Type of term color
 */
#ifndef _TERM_COLOR_DEFINED
    typedef const char * term_color_t;
    #define _TERM_COLOR_DEFINED
#endif


/** @def TERM_COLOR_RESET
 *  @brief Reset console color.
 */
#define TERM_COLOR_RESET  "\e[0m"


/** @def TERM_COLOR_BLACK
 *  @brief Regular black color in foreground.
 */
#define TERM_COLOR_BLACK  "\e[0;30m"

/** @def TERM_COLOR_RED
 *  @brief Regular red color in foreground.
 */
#define TERM_COLOR_RED  "\e[0;31m"

/** @def TERM_COLOR_GREEN
 *  @brief Regular green color in foreground.
 */
#define TERM_COLOR_GREEN  "\e[0;32m"

/** @def TERM_COLOR_YELLOW
 *  @brief Regular yellow color in foreground.
 */
#define TERM_COLOR_YELLOW  "\e[0;33m"

/** @def TERM_COLOR_BLUE
 *  @brief Regular blue color in foreground.
 */
#define TERM_COLOR_BLUE  "\e[0;34m"

/** @def TERM_COLOR_PURPLE
 *  @brief Regular purple color in foreground.
 */
#define TERM_COLOR_PURPLE  "\e[0;35m"

/** @def TERM_COLOR_CYAN
 *  @brief Regular cyan color in foreground.
 */
#define TERM_COLOR_CYAN  "\e[0;36m"

/** @def TERM_COLOR_WHITE
 *  @brief Regular white color in foreground.
 */
#define TERM_COLOR_WHITE  "\e[0;37m"


/** @def TERM_BRIGHT_COLOR_BLACK
 *  @brief Bright black color in foreground.
 */
#define TERM_BRIGHT_COLOR_BLACK  "\e[0;90m"

/** @def TERM_BRIGHT_COLOR_RED
 *  @brief Bright red color in foreground.
 */
#define TERM_BRIGHT_COLOR_RED  "\e[0;91m"

/** @def TERM_BRIGHT_COLOR_GREEN
 *  @brief Bright green color in foreground.
 */
#define TERM_BRIGHT_COLOR_GREEN  "\e[0;92m"

/** @def TERM_BRIGHT_COLOR_YELLOW
 *  @brief Bright yellow color in foreground.
 */
#define TERM_BRIGHT_COLOR_YELLOW  "\e[0;93m"

/** @def TERM_BRIGHT_COLOR_BLUE
 *  @brief Bright blue color in foreground.
 */
#define TERM_BRIGHT_COLOR_BLUE  "\e[0;94m"

/** @def TERM_BRIGHT_COLOR_PURPLE
 *  @brief Bright purple color in foreground.
 */
#define TERM_BRIGHT_COLOR_PURPLE  "\e[0;95m"

/** @def TERM_BRIGHT_COLOR_CYAN
 *  @brief Bright cyan color in foreground.
 */
#define TERM_BRIGHT_COLOR_CYAN  "\e[0;96m"

/** @def TERM_BRIGHT_COLOR_WHITE
 *  @brief Bright white color in foreground.
 */
#define TERM_BRIGHT_COLOR_WHITE  "\e[0;97m"


/** @def TERM_BOLD_COLOR_BLACK
 *  @brief Bold black color in foreground.
 */
#define TERM_BOLD_COLOR_BLACK  "\e[1;30m"

/** @def TERM_BOLD_COLOR_RED
 *  @brief Bold red color in foreground.
 */
#define TERM_BOLD_COLOR_RED  "\e[1;31m"

/** @def TERM_BOLD_COLOR_GREEN
 *  @brief Bold  green color in foreground.
 */
#define TERM_BOLD_COLOR_GREEN  "\e[1;32m"

/** @def TERM_BOLD_COLOR_YELLOW
 *  @brief Bold yellow color in foreground.
 */
#define TERM_BOLD_COLOR_YELLOW  "\e[1;33m"

/** @def TERM_BOLD_COLOR_BLUE
 *  @brief Bold blue color in foreground.
 */
#define TERM_BOLD_COLOR_BLUE  "\e[1;34m"

/** @def TERM_BOLD_COLOR_PURPLE
 *  @brief Bold purple color in foreground.
 */
#define TERM_BOLD_COLOR_PURPLE  "\e[1;35m"

/** @def TERM_BOLD_COLOR_CYAN
 *  @brief Bold cyan color in foreground.
 */
#define TERM_BOLD_COLOR_CYAN  "\e[1;36m"

/** @def TERM_BOLD_COLOR_WHITE
 *  @brief Bold white color in foreground.
 */
#define TERM_BOLD_COLOR_WHITE  "\e[1;37m"


/** @def TERM_BOLD_BRIGHT_COLOR_BLACK
 *  @brief Bold bright black color in foreground.
 */
#define TERM_BOLD_BRIGHT_COLOR_BLACK  "\e[1;90m"

/** @def TERM_BOLD_BRIGHT_COLOR_RED
 *  @brief Bold bright red color in foreground.
 */
#define TERM_BOLD_BRIGHT_COLOR_RED  "\e[1;91m"

/** @def TERM_BOLD_BRIGHT_COLOR_GREEN
 *  @brief Bold bright green color in foreground.
 */
#define TERM_BOLD_BRIGHT_COLOR_GREEN  "\e[1;92m"

/** @def TERM_BOLD_BRIGHT_COLOR_YELLOW
 *  @brief Bold bright yellow color in foreground.
 */
#define TERM_BOLD_BRIGHT_COLOR_YELLOW  "\e[1;93m"

/** @def TERM_BOLD_BRIGHT_COLOR_BLUE
 *  @brief Bold bright blue color in foreground.
 */
#define TERM_BOLD_BRIGHT_COLOR_BLUE  "\e[1;94m"

/** @def TERM_BOLD_BRIGHT_COLOR_PURPLE
 *  @brief Bold bright purple color in foreground.
 */
#define TERM_BOLD_BRIGHT_COLOR_PURPLE  "\e[1;95m"

/** @def TERM_BOLD_BRIGHT_COLOR_CYAN
 *  @brief Bold bright cyan color in foreground.
 */
#define TERM_BOLD_BRIGHT_COLOR_CYAN  "\e[1;96m"

/** @def TERM_BOLD_BRIGHT_COLOR_WHITE
 *  @brief Bold bright white color in foreground.
 */
#define TERM_BOLD_BRIGHT_COLOR_WHITE  "\e[1;97m"


/** @def TERM_UNDERLINE_COLOR_BLACK
 *  @brief Underline black color in foreground.
 */
#define TERM_UNDERLINE_COLOR_BLACK  "\e[4;30m"

/** @def TERM_UNDERLINE_COLOR_RED
 *  @brief Underline red color in foreground.
 */
#define TERM_UNDERLINE_COLOR_RED  "\e[4;31m"

/** @def TERM_UNDERLINE_COLOR_GREEN
 *  @brief Underline green color in foreground.
 */
#define TERM_UNDERLINE_COLOR_GREEN  "\e[4;32m"

/** @def TERM_UNDERLINE_COLOR_YELLOW
 *  @brief Underline yellow color in foreground.
 */
#define TERM_UNDERLINE_COLOR_YELLOW  "\e[4;33m"

/** @def TERM_UNDERLINE_COLOR_BLUE
 *  @brief Underline blue color in foreground.
 */
#define TERM_UNDERLINE_COLOR_BLUE  "\e[4;34m"

/** @def TERM_UNDERLINE_COLOR_PURPLE
 *  @brief Underline purple color in foreground.
 */
#define TERM_UNDERLINE_COLOR_PURPLE  "\e[4;35m"

/** @def TERM_UNDERLINE_COLOR_CYAN
 *  @brief Underline cyan color in foreground.
 */
#define TERM_UNDERLINE_COLOR_CYAN  "\e[4;36m"

/** @def TERM_UNDERLINE_COLOR_WHITE
 *  @brief Underline white color in foreground.
 */
#define TERM_UNDERLINE_COLOR_WHITE  "\e[4;37m"


/** @def TERM_BACKGROUND_COLOR_BLACK
 *  @brief Regular black color in background.
 */
#define TERM_BACKGROUND_COLOR_BLACK  "\e[40m"

/** @def TERM_BACKGROUND_COLOR_RED
 *  @brief Regular red color in background.
 */
#define TERM_BACKGROUND_COLOR_RED  "\e[41m"

/** @def TERM_BACKGROUND_COLOR_GREEN
 *  @brief Regular green color in background.
 */
#define TERM_BACKGROUND_COLOR_GREEN   "\e[42m"

/** @def TERM_BACKGROUND_COLOR_YELLOW
 *  @brief Regular yellow color in background.
 */
#define TERM_BACKGROUND_COLOR_YELLOW  "\e[43m"

/** @def TERM_BACKGROUND_COLOR_BLUE
 *  @brief Regular blue color in background.
 */
#define TERM_BACKGROUND_COLOR_BLUE "\e[44m"

/** @def TERM_BACKGROUND_COLOR_PURPLE
 *  @brief Regular purple color in background.
 */
#define TERM_BACKGROUND_COLOR_PURPLE  "\e[45m"

/** @def TERM_BACKGROUND_COLOR_CYAN
 *  @brief Regular cyan color in background.
 */
#define TERM_BACKGROUND_COLOR_CYAN  "\e[46m"

/** @def TERM_BACKGROUND_COLOR_WHITE
 *  @brief Regular white color in background.
 */
#define TERM_BACKGROUND_COLOR_WHITE  "\e[47m"


/** @def TERM_BRIGHT_BACKGROUND_COLOR_BLACK
 *  @brief Bright black color in background.
 */
#define TERM_BRIGHT_BACKGROUND_COLOR_BLACK  "\e[100m"

/** @def TERM_BRIGHT_BACKGROUND_COLOR_RED
 *  @brief Bright red color in background.
 */
#define TERM_BRIGHT_BACKGROUND_COLOR_RED  "\e[101m"

/** @def TERM_BRIGHT_BACKGROUND_COLOR_GREEN
 *  @brief Bright green color in background.
 */
#define TERM_BRIGHT_BACKGROUND_COLOR_GREEN  "\e[102m"

/** @def TERM_BRIGHT_BACKGROUND_COLOR_YELLOW
 *  @brief Bright yellow color in background.
 */
#define TERM_BRIGHT_BACKGROUND_COLOR_YELLOW  "\e[103m"

/** @def TERM_BRIGHT_BACKGROUND_COLOR_BLUE
 *  @brief Bright blue color in background.
 */
#define TERM_BRIGHT_BACKGROUND_COLOR_BLUE  "\e[104m"

/** @def TERM_BRIGHT_BACKGROUND_COLOR_PURPLE
 *  @brief Bright purple color in background.
 */
#define TERM_BRIGHT_BACKGROUND_COLOR_PURPLE  "\e[105m"

/** @def TERM_BRIGHT_BACKGROUND_COLOR_CYAN
 *  @brief Bright cyan color in background.
 */
#define TERM_BRIGHT_BACKGROUND_COLOR_CYAN  "\e[106m"

/** @def TERM_BRIGHT_BACKGROUND_COLOR_WHITE
 *  @brief Bright white color in background.
 */
#define TERM_BRIGHT_BACKGROUND_COLOR_WHITE  "\e[107m"

#endif  /* CLIBS_TERM_COLOR */
