#include <stdlib.h>
#include <string.h>
#include "cstring.h"
#include "print.h"

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
        char c = 'c';

        char *out = string_allocate_char(c);
        if (!out)
            goto ERROR_CSTRING;

        TEST(string_is_equal(out, "c"));

        free(out);
    }

    {
        char s[] = "The quick brown fox jumps over the lazy dog";

        char *out = string_allocate_substring(s, 0, 2);
        if (!out)
            goto ERROR_CSTRING;

        TEST(string_is_equal(out, "The"));

        free(out);
    }

    {
        char s[] = "The quick brown fox jumps over the lazy dog";

        char *out = string_allocate_substring(s, 10, 14);
        if (!out)
            goto ERROR_CSTRING;

        TEST(string_is_equal(out, "brown"));

        free(out);
    }

    {
        char s[] = "The quick brown fox jumps over the lazy dog";

        char *out = string_allocate_substring(s, strlen(s) - 3, strlen(s));
        if (!out)
            goto ERROR_CSTRING;

        TEST(string_is_equal(out, "dog"));

        free(out);
    }

    {
        char *out = string_allocate("Hello World");
        if (!out) {
            free(out);
            goto ERROR_CSTRING;
        }

        TEST(string_is_equal(out, "Hello World"));

        free(out);
    }

/*-------1---------2---------3---------4---------5---------6---------7---------8---------9*/
/*3456789012345678901234567890123456789012345678901234567890123456789012345678901234567890*/
    {
        char s[] = \
"C is a general-purpose, procedural computer programming language " END_OF_LINE
"supporting structured programming, lexical variable scope, and " END_OF_LINE
"recursion, while a static type system prevents unintended operations." END_OF_LINE;

        FILE *fp = string_to_stream(s);
        if (!fp)
            goto ERROR_CSTRING;

        do {
            char c = fgetc(fp);

            if (feof(fp))
                break;

            printf("%c", c);
        } while (1);

        fclose(fp);
    }

    if (!passed)
        goto ERROR_CSTRING;

    return 0;

ERROR_CSTRING:
    return 1;
}
