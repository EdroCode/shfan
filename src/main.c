#include <stdio.h>
#include "parser/parser.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: compress <filename>\n");
        return 1;
    }



    const char *filename = argv[1];

    get_file(filename);

    // printf("Done");
    return 0;
}