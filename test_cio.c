#include <stdio.h>
#include <stdlib.h>
#include "cio.h"
#include "print.h"

int main(void)
{
    {
        FILE *fp;
    #if _MSC_VER
        if (0 != fopen_s(&fp, "cio.h", "r")) {
            PUTERR("Failed to read file");
            return 1;
        }
    #else
        fp = fopen("cio.h", "r");
    #endif
        if (!fp) {
            PUTERR("Failed to get stream object");
            return 1;
        }

        char *buffer = stream_read_all(fp);
        if (!buffer) {
            fclose(fp);
            return 1;
        }

        PUTS("%s", buffer);

        free(buffer);

        fclose(fp);
    }

    return 0;
}