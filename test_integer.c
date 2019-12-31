#if _MSC_VER
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    #include "boolean.h"
#endif
#include "integer.h"
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

#ifdef INT8_IS_DEFINED
    TEST(1 == sizeof(int8_t));
    TEST(1 == sizeof(uint8_t));
#endif

#ifdef INT16_IS_DEFINED
    TEST(2 == sizeof(int16_t));
    TEST(2 == sizeof(uint16_t));
#endif

#ifdef INT32_IS_DEFINED
    TEST(4 == sizeof(int32_t));
    TEST(4 == sizeof(uint32_t));
#endif

#ifdef INT64_IS_DEFINED
    TEST(8 == sizeof(int64_t));
    TEST(8 == sizeof(uint64_t));
#endif

    if (!passed)
        return 1;

    return 0;
}