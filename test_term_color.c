#include <curses.h>
#include "print.h"
#include "term_color.h"

int main(void)
{
    #define TARGET_STRING  "Hello World"

    PUTS("%s%s%s%s",
        TERM_COLOR_BLACK,
        TERM_BACKGROUND_COLOR_BLACK,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_RED,
        TERM_BACKGROUND_COLOR_BLACK,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_GREEN,
        TERM_BACKGROUND_COLOR_BLACK,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_YELLOW,
        TERM_BACKGROUND_COLOR_BLACK,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_BLUE,
        TERM_BACKGROUND_COLOR_BLACK,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_PURPLE,
        TERM_BACKGROUND_COLOR_BLACK,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_CYAN,
        TERM_BACKGROUND_COLOR_BLACK,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_WHITE,
        TERM_BACKGROUND_COLOR_BLACK,
        TARGET_STRING,
        TERM_COLOR_RESET);
    
    PUTS("%s%s%s%s",
        TERM_COLOR_BLACK,
        TERM_BACKGROUND_COLOR_RED,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_RED,
        TERM_BACKGROUND_COLOR_RED,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_GREEN,
        TERM_BACKGROUND_COLOR_RED,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_YELLOW,
        TERM_BACKGROUND_COLOR_RED,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_BLUE,
        TERM_BACKGROUND_COLOR_RED,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_PURPLE,
        TERM_BACKGROUND_COLOR_RED,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_CYAN,
        TERM_BACKGROUND_COLOR_RED,
        TARGET_STRING,
        TERM_COLOR_RESET);
    PUTS("%s%s%s%s",
        TERM_COLOR_WHITE,
        TERM_BACKGROUND_COLOR_RED,
        TARGET_STRING,
        TERM_COLOR_RESET);

    return 0;
}
