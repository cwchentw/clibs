#include <stdio.h>

#define SIZE_OF_CHAR  8
#define HEADER_FILE "_sizeof_data_type.h"

int main(void)
{
    FILE *fp = fopen(HEADER_FILE, "w");

    if (!fp) {
        fprintf(stderr, "Failed to open file to write\n");
        return 1;
    }

    fprintf(fp, "#ifndef _SIZE_OF_DATA_TYPE_H\n");
    fprintf(fp, "#define _SIZE_OF_DATA_TYPE_H\n");
    fprintf(fp, "\n");

    fprintf(fp, "#define _SIZEOF_CHAR  %lu\n",
        SIZE_OF_CHAR * sizeof(char));
    fprintf(fp, "#define _SIZEOF_SHORT  %lu\n",
        SIZE_OF_CHAR * sizeof(short));
    fprintf(fp, "#define _SIZEOF_INT  %lu\n",
        SIZE_OF_CHAR * sizeof(int));
    fprintf(fp, "#define _SIZEOF_LONG  %lu\n",
        SIZE_OF_CHAR * sizeof(long));
#if __STDC_VERSION__ >= 199901L || _MSC_VER || __GNUC__ || __clang__
    fprintf(fp, "#define _SIZEOF_LONG_LONG  %lu\n",
        SIZE_OF_CHAR * sizeof(long long));
#endif

    fprintf(fp, "\n");
    fprintf(fp, "#endif  /* _SIZE_OF_DATA_TYPE_H */\n");

    fclose(fp);

    return 0;
}
