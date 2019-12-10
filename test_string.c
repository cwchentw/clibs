#include "print_function.h"
#include "string.h"

#define TEST(cond) { \
    if (!(cond)) { \
        DEBUG("Wrong test"); \
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

    if (!passed)
        return 1;

    return 0;
}
