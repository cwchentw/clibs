#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstring.h"

#ifndef END_OF_LINE
    #define END_OF_LINE  "\n"
#endif

#ifndef DEBUG_INFO
    #define DEBUG_INFO(format, ...) { \
        fprintf(stderr, "(%s:%d) " format "%s", \
            __FILE__, __LINE__, ##__VA_ARGS__, END_OF_LINE); \
    }
#endif

BOOL string_starts_with(const char *a, const char *b)
{
    size_t i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i])
            return FALSE;

        i++;
    }

    return TRUE;
}

BOOL string_contains(const char *a, const char *b)
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

BOOL string_is_space_only(const char *s)
{
    size_t sz = strlen(s);

    {
        size_t i;
        for (i = 0; i < sz; i++) {
            /* Stop on EOL for Unix. */
            if ('\n' == s[i])
                break;

            /* Stop on EOL for Windows. */
            if ('\r' == s[i]) {
                if (i + 1 < sz && '\n' == s[i+1]) {
                    break;
                }
            }

            if (!(' ' == s[i] || '\t' == s[i]))
                return FALSE;
        }
    }

    return TRUE;
}

char * string_allocate_char(const char c)
{
    size_t sz = 2;  /* char + '\0' */

    char *out = (char *) malloc(sz * sizeof(char));
    if (!out) {
        DEBUG_INFO("Failed to allocate memory for C string");
        DEBUG_INFO("Check available system memory");
        return out;
    }

    out[0] = c;
    out[1] = '\0';

    return out;
}

char * string_allocate(const char *s)
{
    size_t sz = strlen(s) + 1;  /* strlen(s) + '\0' */

    char *out = (char *) malloc(sz * sizeof(char));
    if (!out) {
        DEBUG_INFO("Failed to allocate memory for C string");
        DEBUG_INFO("Check available system memory");
        return out;
    }

    out[0] = '\0';

    {
        size_t i;
        for (i = 0; i < sz - 1; i++)
            out[i] = s[i];
    }
    out[sz-1] = '\0';  /* Trailing zero. */

    return out;
}

char * string_allocate_substring(const char *s, size_t from, size_t to)
{
    assert(from <= to);

    size_t len = strlen(s);
    assert(to <= len);

    size_t sz = to - from + 1 + 1;

    char *out = (char *) malloc(sz * sizeof(char));
    if (!out) {
        DEBUG_INFO("Failed to allocate memory for C string");
        DEBUG_INFO("Check available system memory");
        return out;
    }

    out[0] = '\0';

    {
        size_t i;
        for (i = from; i <= to; i++)
            out[i-from] = s[i];
    }

    out[sz-1] = '\0';  /* Trailing zero. */

    return out;
}

char * string_concat(const char *a, const char *b)
{
    assert(a);
    assert(b);

    size_t sz_a = strlen(a);
    size_t sz_b = strlen(b);

    size_t sz = sz_a + sz_b + 1 /* Trailing zero. */;

    char *out = (char *) malloc(sz * sizeof(char));
    if (!out) {
        DEBUG_INFO("Failed to allocate memory for C string");
        DEBUG_INFO("Check available system memory");
        return out;
    }

    {
        size_t i;
        for (i = 0; i < sz_a; ++i)
            out[i] = a[i];
    }

    {
        size_t i;
        for (i = 0; i < sz_b; ++i)
            out[i+sz_a] = b[i];
    }

    out[sz-1] = '\0'; /* Trailing zero. */

    return out;
}

FILE * string_to_stream(char *s)
{
#ifdef _MSC_VER
    FILE *fp = NULL;

    if (!tmpfile_s(&fp)) {
        DEBUG_INFO("Failed to create temp file");
        return fp;
    }
#else
    FILE *fp = tmpfile();
#endif
    if (!fp) {
        DEBUG_INFO("Failed to create file stream");
        DEBUG_INFO("Check available system memory");
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
