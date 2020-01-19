#if _MSC_VER
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    #include "boolean.h"
#endif
#include "clibs_math.h"
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

    TEST(IS_EQUAL(3.14f, 3.14f, 0.01));
    TEST(IS_EQUAL(3.14159, 3.14159, 0.00001));
    TEST(IS_EQUAL(3.1415927L, 3.1415927L, 0.0000001));
    TEST(!IS_EQUAL(3.14f, 3.15f, 0.005));
    TEST(!IS_EQUAL(3.14159, 3.14160, 0.000005));

    TEST(IS_EQUAL(1.0 / 3.0 + 1.0 / 3.0 + 1.0 / 3.0, 1.0, 0.05));
    TEST(IS_EQUAL(1.0 - 0.3 - 0.5 - 0.2, 0.0, 0.05));

    TEST(IS_EVEN(4));
    TEST(!IS_EVEN(5));

    TEST(!IS_ODD(4));
    TEST(IS_ODD(5));

    {
        unsigned a = 3;
        unsigned b = 4;

        SWAP(a, b);

        TEST(4 == a);
        TEST(3 == b);
    }

    if (!passed)
        return 1;

    return 0;
}
