#include "parser.h"
#include <stdio.h>

unsigned char *read_file(const char *filename, size_t *size) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror(filename);
        return NULL;
    }

    unsigned char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        printf("Read %zu bytes\n", bytes_read);
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return NULL;
    }

    *size = bytes_read;
    // Need to alocate memory for the cfile contents
    // printf("%s", buffer);

    fclose(file);
    return NULL;
}