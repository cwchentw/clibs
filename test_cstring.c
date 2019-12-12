#include <stdlib.h>
#include "print_function.h"
#include "cstring.h"

#define TEST(cond) { \
    if (!(cond)) { \
        DEBUG_INFO("Wrong test"); \
        passed = FALSE; \
    } \
}

int main(void)
{
    BOOL passed = TRUE;

    TEST(string_is_equal("apple", "apple"));
    TEST(!string_is_equal("apple", "banana"));
    TEST(string_starts_with("Hello World", "Hello"));
    TEST(!string_starts_with("Hello World", "World"));
    TEST(string_contains(
        "The quick brown fox jumps over the lazy dog", "dog"));
    TEST(!string_contains(
        "The quick brown fox jumps over the lazy dog", "black"));
    TEST(string_is_space_only(" \t\r\n"));
    TEST(!string_is_space_only(" !\n"));

    {
        char *out = string_allocate("Hello World");
        if (!out) {
            free(out);
            goto ERROR;
        }

        TEST(string_is_equal(out, "Hello World"));

        free(out);
    }

/*-------1---------2---------3---------4---------5---------6---------7---------8---------9*/
/*3456789012345678901234567890123456789012345678901234567890123456789012345678901234567890*/
    char s[] = "C is a general-purpose, procedural computer programming language " END_OF_LINE
               "supporting structured programming, lexical variable scope, and " END_OF_LINE
               "recursion, while a static type system prevents unintended operations." END_OF_LINE;

    FILE *fp = string_to_stream(s);
    if (!fp)
        goto ERROR;

    do {
        char c = fgetc(fp);

        if (feof(fp))
            break;

        printf("%c", c);
    } while (1);

    if (!passed)
        goto ERROR;

    fclose(fp);

    return 0;

ERROR:
    if (fp)
        fclose(fp);

    return 1;
}
