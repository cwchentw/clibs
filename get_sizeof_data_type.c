/*
 * @file    get_sizeof_data_type.c
 * @brief   Generate _sizeof_data_type.h for use with C89-compatible integer.h
 *
 * This program creates a header file with macros defining the sizes
 * of fundamental C data types in bits. It is intended to be used when
 * <stdint.h> is not available, such as in C89 environments.
 */

#include <stdio.h>
#include <limits.h>  /* CHAR_BIT */

#define HEADER_FILE "_sizeof_data_type.h"

int main(void)
{
    FILE *fp = fopen(HEADER_FILE, "w");

    if (!fp) {
        fprintf(stderr, "Error: Failed to open %s for writing.\n", HEADER_FILE);
        return 1;
    }

    /* Header guard start */
    fprintf(fp, "#ifndef SIZEOF_DATA_TYPE_H\n");
    fprintf(fp, "#define SIZEOF_DATA_TYPE_H\n\n");

    /* Output sizes in bits */
    fprintf(fp, "#define _SIZEOF_CHAR       %lu\n",
            (unsigned long)(CHAR_BIT * sizeof(char)));
    fprintf(fp, "#define _SIZEOF_SHORT      %lu\n",
            (unsigned long)(CHAR_BIT * sizeof(short)));
    fprintf(fp, "#define _SIZEOF_INT        %lu\n",
            (unsigned long)(CHAR_BIT * sizeof(int)));
    fprintf(fp, "#define _SIZEOF_LONG       %lu\n",
            (unsigned long)(CHAR_BIT * sizeof(long)));
    fprintf(fp, "#define _SIZEOF_VOID_P     %lu\n",
            (unsigned long)(CHAR_BIT * sizeof(void *)));

    /*
     * Conditionally include long long size if supported.
     * This covers:
     * - C99 and later
     * - MSVC
     * - GCC / Clang extensions in pre-C99 mode
     */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
    defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__)
    fprintf(fp, "#define _SIZEOF_LONG_LONG  %lu\n",
            (unsigned long)(CHAR_BIT * sizeof(long long)));
#endif

    /* Header guard end */
    fprintf(fp, "\n#endif  /* SIZEOF_DATA_TYPE_H */\n");

    if (ferror(fp)) {
        fprintf(stderr,
                "Error: Write failure occurred while generating %s.\n",
                HEADER_FILE);
        fclose(fp);
        return 2;
    }

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error: Failed to close %s.\n", HEADER_FILE);
        return 2;
    }

    printf("Header file '%s' successfully generated.\n", HEADER_FILE);
    return 0;
}