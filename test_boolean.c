#if _MSC_VER
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    #include "boolean.h"
#endif
#include "print.h"

#define TEST(cond) { \
    if (!(cond)) { \
        DEBUG_INFO("Wrong boolean relation"); \
        passed = FALSE; \
    } \
}

int main(void)
{
    BOOL passed = TRUE;

    /* Test AND */
    TEST((TRUE && TRUE) == TRUE);
    TEST((TRUE && FALSE) == FALSE);
    TEST((FALSE && TRUE) == FALSE);
    TEST((FALSE && FALSE) == FALSE);

    /* Test OR */
    TEST((TRUE || TRUE) == TRUE);
    TEST((TRUE || FALSE) == TRUE);
    TEST((FALSE || TRUE) == TRUE);
    TEST((FALSE || FALSE) == FALSE);

    /* Test NOT */
    TEST((!TRUE) == FALSE);
    TEST((!FALSE) == TRUE);

    if (!passed)
        return 1;

    return 0;
}
