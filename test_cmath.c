#include "boolean.h"
#include "cmath.h"
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

    TEST(MAX(3, 5) == 5);
    TEST(MAX(4.0, 1.0) == 4.0);

    TEST(MIN(3, 5) == 3);
    TEST(MIN(4.0, 1.0) == 1.0);

    TEST(ABS(3.0) == 3.0);
    TEST(ABS(-3.0) == 3.0);

    if (!passed)
        return 1;

    return 0;
}
