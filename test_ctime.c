#include <time.h>

#if _MSC_VER
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    #include "boolean.h"
#endif
#include "clibs_time.h"
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

    {
        struct tm t = date_create(2020, 1, 6);

        TEST(2020 - 1900 == t.tm_year);
        TEST(1 - 1 == t.tm_mon);
        TEST(6 == t.tm_mday);
        TEST(9 == t.tm_hour);
        TEST(0 == t.tm_min);
        TEST(0 == t.tm_sec);
    }

    if (!passed)
        return 1;

    return 0;
}
