#include "boolean.h"
#include "print.h"  /* For DEBUG_INFO */

/* Simple test macro with debug info */
#define TEST(cond) \
    do { \
        if (!(cond)) { \
            DEBUG_INFO("Boolean test failed: " #cond); \
            passed = FALSE; \
        } \
    } while (0)

int main(void)
{
    BOOL passed = TRUE;

    /* --- AND logic --- */
    TEST((TRUE && TRUE) == TRUE);
    TEST((TRUE && FALSE) == FALSE);
    TEST((FALSE && TRUE) == FALSE);
    TEST((FALSE && FALSE) == FALSE);

    /* --- OR logic --- */
    TEST((TRUE || TRUE) == TRUE);
    TEST((TRUE || FALSE) == TRUE);
    TEST((FALSE || TRUE) == TRUE);
    TEST((FALSE || FALSE) == FALSE);

    /* --- NOT logic --- */
    TEST((!TRUE) == FALSE);
    TEST((!FALSE) == TRUE);

    return passed ? 0 : 1;
}
