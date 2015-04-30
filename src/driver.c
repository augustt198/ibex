#include "driver.h"

void compile(char *filename) {
    FILE *file    = fopen(filename, "r");

    int linecount = fcountlines(file);
    char *lines[linecount];
    fsplitlines(lines, file);
    fclose(file);

    int pos = 0;
    ASTNode *block = CreateUnprocessedBody(lines, linecount, &pos, 0);
}
