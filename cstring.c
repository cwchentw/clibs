#include <stdio.h>
#include <string.h>
#include "cstring.h"

#ifndef END_OF_LINE
    #if _WIN32
        #define END_OF_LINE  "\r\n"
    #elif __unix__ || __APPLE__
        #define END_OF_LINE  "\n"
    #else
        #error "Unsupported"
    #endif
#endif

#ifndef PUTERR
    #define PUTERR(format, ...) { \
        fprintf(stderr, format "%s", ##__VA_ARGS__, END_OF_LINE); \
    }
#endif

BOOL string_is_equal(char *a, char *b)
{
    if (0 == strcmp(a, b))
        return TRUE;

    return FALSE;
}

BOOL string_starts_with(char *a, char *b)
{
    size_t i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i])
            return FALSE;

        i++;
    }

    return TRUE;
}

BOOL string_contains(char *a, char *b)
{
    size_t i = 0;
    while (a[i]) {
        size_t _i = i;
        size_t _j = 0;

        BOOL matched = TRUE;
        while (b[_j]) {
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

FILE * string_to_stream(char *s)
{
    FILE *fp = tmpfile();
    if (!fp) {
        PUTERR("Failed to allocate memory for file stream");
        PUTERR("Check available system memory");
        return fp;
    }

    size_t i = 0;
    while (s[i]) {
        fputc(s[i], fp);
        i++;
    }

    /* Set the file pointer at the beginning of the stream. */
    rewind(fp);

    return fp;
}
