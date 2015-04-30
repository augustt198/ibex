#include "driver.h"

void printBlock(list_t *block) {
    printf(">>> BLOCK START\n");

    list_iterator_start(block);
    while (list_iterator_hasnext(block)) {
        BlockEntry *entry = list_iterator_next(block);
        if (entry->type == LINE) {
            printf("%s\n", entry->line);
        } else {
            printBlock(entry->block);
        }
    }

    printf("<<< BLOCK END\n");
}

void compile(char *filename) {
    FILE *file    = fopen(filename, "r");

    int linecount = fcountlines(file);
    char *lines[linecount];
    fsplitlines(lines, file);
    fclose(file);

    int pos = 0;
    list_t *block = Blockify(lines, linecount, &pos, 0);

    printf("%s block structure:\n", filename);
    printBlock(block);
}
