#include <stdio.h>

#if _WIN32
    #define END_OF_LINE  "\r\n"
#elif __unix__ || __unix || unix || __APPLE__
    #define END_OF_LINE  "\n"
#else
    #error "Unsupported"
#endif

#define SIZE_OF_CHAR  8
#define HEADER_FILE "_sizeof_data_type.h"

int main(void)
{
    FILE *fp = fopen(HEADER_FILE, "w");

    if (!fp) {
        fprintf(stderr, "Failed to open file to write%s", END_OF_LINE);
        return 1;
    }

    fprintf(fp, "#ifndef _SIZE_OF_DATA_TYPE_H%s", END_OF_LINE);
    fprintf(fp, "#define _SIZE_OF_DATA_TYPE_H%s", END_OF_LINE);
    fprintf(fp, "%s", END_OF_LINE);

    fprintf(fp, "#define _SIZEOF_CHAR  %lu%s",
        SIZE_OF_CHAR * sizeof(char), END_OF_LINE);
    fprintf(fp, "#define _SIZEOF_SHORT  %lu%s",
        SIZE_OF_CHAR * sizeof(short), END_OF_LINE);
    fprintf(fp, "#define _SIZEOF_INT  %lu%s",
        SIZE_OF_CHAR * sizeof(int), END_OF_LINE);
    fprintf(fp, "#define _SIZEOF_LONG  %lu%s",
        SIZE_OF_CHAR * sizeof(long), END_OF_LINE);
#if __STDC_VERSION__ >= 199901L || _MSC_VER || __GNUC__ || __clang__
    fprintf(fp, "#define _SIZEOF_LONG_LONG  %lu%s",
        SIZE_OF_CHAR * sizeof(long long), END_OF_LINE);
#endif

    fprintf(fp, "%s", END_OF_LINE);
    fprintf(fp, "#endif  /* _SIZE_OF_DATA_TYPE_H */%s", END_OF_LINE);
    fprintf(fp, "%s", END_OF_LINE);

    fclose(fp);

    return 0;
}
