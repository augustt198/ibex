#include "util.h"

char *file2str(FILE *file) {
    fseek(file, 0, SEEK_END);
    int length = ftell(file);

    rewind(file);

    char *buffer = malloc(length + 1);
    buffer[length] = '\0';
    if (buffer) {
        fread(buffer, length, 1, file);
    }

    return buffer;
}

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

sds sdscatc(sds s, char chr) {
    char str[2];
    str[0] = chr;

    return sdscatlen(s, str, 1);
}

int fcountlines(FILE *file) {
    char *line = NULL;
    size_t linecap = 0;
    int lines = 0;

    while (getline(&line, &linecap, file) != -1)
        lines++;

    rewind(file);

    return lines;
}

 void fsplitlines(char **lines, FILE *file) {
     char *line     = NULL;
     size_t linecap = 0;
     int i          = 0;
     int len;

     while ((len = getline(&line, &linecap, file)) != -1) {
         lines[i] = malloc(len);
         strncpy(lines[i], line, len - 1);
         i++;
     }

     rewind(file);
}
