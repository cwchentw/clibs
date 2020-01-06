#include <stdio.h>
#include <stdlib.h>
#include "cio.h"
#include "print.h"

int main(void)
{
    {
        FILE *fp = fopen("cio.h", "r");
        if (!fp) {
            PUTERR("Failed to read file");
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