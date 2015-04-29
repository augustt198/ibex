#include "driver.h"
#include "util.h"
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Expected at least one source file\n");
        return -1;
    }

    for (int i = 1; i < argc; i++) {
        printf("Compiling %s\n", argv[i]);
        char* source = file2str(argv[i]);
        compile(source);
    }
}
