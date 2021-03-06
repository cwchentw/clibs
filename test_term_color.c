#include "print.h"
#include "term_color.h"

int main(void)
{
    #define TARGET_STRING  "*Color*"

    term_color_t regular_colors[] = {
        TERM_COLOR_BLACK,
        TERM_COLOR_RED,
        TERM_COLOR_GREEN,
        TERM_COLOR_YELLOW,
        TERM_COLOR_BLUE,
        TERM_COLOR_PURPLE,
        TERM_COLOR_CYAN,
        TERM_COLOR_WHITE
    };

    term_color_t bright_colors[] = {
        TERM_BRIGHT_COLOR_BLACK,
        TERM_BRIGHT_COLOR_RED,
        TERM_BRIGHT_COLOR_GREEN,
        TERM_BRIGHT_COLOR_YELLOW,
        TERM_BRIGHT_COLOR_BLUE,
        TERM_BRIGHT_COLOR_PURPLE,
        TERM_BRIGHT_COLOR_CYAN,
        TERM_BRIGHT_COLOR_WHITE
    };

    term_color_t bold_colors[] = {
        TERM_BOLD_COLOR_BLACK,
        TERM_BOLD_COLOR_RED,
        TERM_BOLD_COLOR_GREEN,
        TERM_BOLD_COLOR_YELLOW,
        TERM_BOLD_COLOR_BLUE,
        TERM_BOLD_COLOR_PURPLE,
        TERM_BOLD_COLOR_CYAN,
        TERM_BOLD_COLOR_WHITE
    };

    term_color_t bold_bright_colors[] = {
        TERM_BOLD_BRIGHT_COLOR_BLACK,
        TERM_BOLD_BRIGHT_COLOR_RED,
        TERM_BOLD_BRIGHT_COLOR_GREEN,
        TERM_BOLD_BRIGHT_COLOR_YELLOW,
        TERM_BOLD_BRIGHT_COLOR_BLUE,
        TERM_BOLD_BRIGHT_COLOR_PURPLE,
        TERM_BOLD_BRIGHT_COLOR_CYAN,
        TERM_BOLD_BRIGHT_COLOR_WHITE
    };

    term_color_t underline_colors[] = {
        TERM_UNDERLINE_COLOR_BLACK,
        TERM_UNDERLINE_COLOR_RED,
        TERM_UNDERLINE_COLOR_GREEN,
        TERM_UNDERLINE_COLOR_YELLOW,
        TERM_UNDERLINE_COLOR_BLUE,
        TERM_UNDERLINE_COLOR_PURPLE,
        TERM_UNDERLINE_COLOR_CYAN,
        TERM_UNDERLINE_COLOR_WHITE
    };

    term_color_t background_colors[] = {
        TERM_BACKGROUND_COLOR_BLACK,
        TERM_BACKGROUND_COLOR_RED,
        TERM_BACKGROUND_COLOR_GREEN,
        TERM_BACKGROUND_COLOR_YELLOW,
        TERM_BACKGROUND_COLOR_BLUE,
        TERM_BACKGROUND_COLOR_PURPLE,
        TERM_BACKGROUND_COLOR_CYAN,
        TERM_BACKGROUND_COLOR_WHITE
    };

    term_color_t bright_background_colors[] = {
        TERM_BRIGHT_BACKGROUND_COLOR_BLACK,
        TERM_BRIGHT_BACKGROUND_COLOR_RED,
        TERM_BRIGHT_BACKGROUND_COLOR_GREEN,
        TERM_BRIGHT_BACKGROUND_COLOR_YELLOW,
        TERM_BRIGHT_BACKGROUND_COLOR_BLUE,
        TERM_BRIGHT_BACKGROUND_COLOR_PURPLE,
        TERM_BRIGHT_BACKGROUND_COLOR_CYAN,
        TERM_BRIGHT_BACKGROUND_COLOR_WHITE
    };

    /* Regular color on regular background color. */
    {
        size_t i;
        for (i = 0;
             i < sizeof(background_colors) / sizeof(term_color_t);
             i++)
        {
            {
                size_t j;
                for (j = 0;
                     j < sizeof(regular_colors) / sizeof(term_color_t);
                     j++)
                {
                    PRINT("%s%s%s%s",
                        regular_colors[j],
                        background_colors[i],
                        TARGET_STRING,
                        TERM_COLOR_RESET);
                }
            }
            PUTS("");
        }
    }

    PUTS("");

    /* Bright color on bright background color. */
    {
        size_t i;
        for (i = 0;
             i < sizeof(bright_background_colors) / sizeof(term_color_t);
             i++)
        {
            {
                size_t j;
                for (j = 0;
                     j < sizeof(bright_colors) / sizeof(term_color_t);
                     j++)
                {
                    PRINT("%s%s%s%s",
                        bright_colors[j],
                        bright_background_colors[i],
                        TARGET_STRING,
                        TERM_COLOR_RESET);
                }
                PUTS("");
            }
        }
    }

    PUTS("");

    /* Bold color on regular background color. */
    {
        size_t i;
        for (i = 0;
             i < sizeof(background_colors) / sizeof(term_color_t);
             i++)
        {
            {
                size_t j;
                for (j = 0;
                     j < sizeof(bold_colors) / sizeof(term_color_t);
                     j++)
                {
                    PRINT("%s%s%s%s",
                        bold_colors[j],
                        background_colors[i],
                        TARGET_STRING,
                        TERM_COLOR_RESET);
                }
                PUTS("");
            }
        }
    }

    PUTS("");

    /* Bold bright color on bright background color. */
    {
        size_t i;
        for (i = 0;
             i < sizeof(bright_background_colors) / sizeof(term_color_t);
             i++)
        {
            {
                size_t j;
                for (j = 0;
                     j < sizeof(bold_bright_colors) / sizeof(term_color_t);
                     j++)
                {
                    PRINT("%s%s%s%s",
                        bold_bright_colors[j],
                        bright_background_colors[i],
                        TARGET_STRING,
                        TERM_COLOR_RESET);
                }
                PUTS("");
            }
        }
    }

    PUTS("");

    /* Underline color on regular background color. */
    {
        size_t i;
        for (i = 0;
             i < sizeof(background_colors) / sizeof(term_color_t);
             i++)
        {
            {
                size_t j;
                for (j = 0;
                     j < sizeof(underline_colors) / sizeof(term_color_t);
                     j++)
                {
                    PRINT("%s%s%s%s",
                        underline_colors[j],
                        background_colors[i],
                        TARGET_STRING,
                        TERM_COLOR_RESET);
                }
                PUTS("");
            }
        }
    }

    return 0;
}
