#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cio.h"

#ifndef END_OF_LINE
    #define END_OF_LINE  "\n"
#endif

#ifndef PUTERR
    #define PUTERR(format, ...) { \
        fprintf(stderr, \
            format "%s", ##__VA_ARGS__, \
            END_OF_LINE); \
    }
#endif

char * stream_read_all(FILE *fp)
{
    char *buffer = NULL;
    char *more_buffer = NULL;
    char *line = NULL;
    char *more_line = NULL;

    /* Allocate memory for buffer. */
    size_t buffer_size = 1024;  /* Arbitrary size. */
    buffer = (char *) malloc(buffer_size * sizeof(char));
    if (!buffer) {
        PUTERR("Failed to allocate memory for C string");
        PUTERR("Check available system memory");
        return NULL;
    }

    buffer[0] = '\0';

    /* Allocate memory for line. */
    size_t line_size = 150;  /* Arbitrary size. */
    line = (char *) malloc(line_size * sizeof(char));
    if (!line) {
        PUTERR("Failed to allocate memory for C string");
        PUTERR("Check available system memory");
        goto ERROR_CIO_READ_ALL;
    }

    line[0] = '\0';

    /* Read file stream line by line. */
    size_t length = 0;
    while (fgets(line, line_size, fp)) {
        size_t sz = strlen(line);
        if (line_size == sz) {
            /* Reallocate the line. */
            if ('\n' != line[sz-1]) {
                /* Reallocate the buffer. */
                if (length + sz >= buffer_size) {
                    while (length + sz >= buffer_size)
                        buffer_size <<= 1;

                    more_buffer = \
                        realloc(buffer, buffer_size);
                    if (!more_buffer) {
                        goto ERROR_CIO_READ_ALL;
                    }

                    buffer = more_buffer;
                }

                strcpy(buffer+length, line);

                length += sz;
                buffer[length] = '\0';

                line_size <<= 1;

                more_line = \
                    realloc(line, line_size);
                if (!more_line) {
                    goto ERROR_CIO_READ_ALL;
                }

                line = more_line;
            }
            else {
                goto LOAD_LINE;
            }
        }
        else {
    LOAD_LINE:
            /* Reallocate buffer. */
            if (length + sz >= buffer_size) {
                while (length + sz >= buffer_size)
                    buffer_size <<= 1;

                more_buffer = \
                    realloc(buffer, buffer_size);
                if (!more_buffer) {
                    goto ERROR_CIO_READ_ALL;
                }

                buffer = more_buffer;
            }

            /* Copy line to buffer. */
            strcpy(buffer+length, line);

            length += sz;
            buffer[length] = '\0';
        }
    }

    free(line);

    return buffer;

ERROR_CIO_READ_ALL:
    if (line)
        free(line);

    if (buffer)
        free(buffer);

    return NULL;
}
