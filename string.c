#include <string.h>
#include "string.h"

BOOL string_is_equal(char *a, char *b)
{
    if (0 == strcmp(a, b))
        return TRUE;

    return FALSE;
}

BOOL string_starts_with(char *a, char *b)
{
    size_t sz_a = strlen(a);
    size_t sz_b = strlen(b);

    if (sz_a < sz_b)
        return FALSE;

    size_t i = 0;
    while (i < sz_b) {
        if (a[i] != b[i])
            return FALSE;

        i++;
    }

    return TRUE;
}

BOOL string_contains(char *a, char *b)
{
    size_t sz_a = strlen(a);
    size_t sz_b = strlen(b);

    if (sz_a < sz_b)
        return FALSE;

    size_t i = 0;
    while (i + sz_b <= sz_a) {
        size_t _i = i;
        size_t _j = 0;

        BOOL matched = TRUE;
        while (_j < sz_b) {
            if (a[_i] != b[_j]) {
                matched = FALSE;
                break;
            }

            _i++;
            _j++;
        }

        if (matched)
            return TRUE;

        i++;
    }

    return FALSE;
}

BOOL string_is_space_only(char *a)
{
    size_t sz = strlen(a);

    {
        size_t i;
        for (i = 0; i < sz; i++) {
            /* Stop on EOL for Unix. */
            if ('\n' == a[i])
                break;

            /* Stop on EOL for Windows. */
            if ('\r' == a[i]) {
                if (i + 1 < sz && '\n' == a[i+1]) {
                    break;
                }
            }

            if (!(' ' == a[i] || '\t' == a[i]))
                return FALSE;
        }
    }

    return TRUE;
}
