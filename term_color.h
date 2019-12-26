/** @file       term_color.h
 *  @brief      Add colors, either foreground or background, on console environment.
 *  @author     Michael Chen
 *  @copyright  MIT
 *
 * Windows is not supported.
 */
#ifndef CLIBS_TERM_COLOR
#define CLIBS_TERM_COLOR

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
 *  @brief Bold cyan color in foreground.
 */
#define TERM_BOLD_COLOR_WHITE  "\e[1;37m"


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

#endif  /* CLIBS_TERM_COLOR */
