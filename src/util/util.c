#include "util.h"

char *file2str(char *name) {
    FILE *file = fopen(name, "r");

    if (file) {
        fseek(file, 0, SEEK_END);
        int length = ftell(file);
        rewind(file);
        char *buffer = malloc(length + 1);
        buffer[length] = '\0';
        if (buffer) {
            fread(buffer, length, 1, file);
        }
        fclose(file);
        return buffer;
    }

    return NULL;
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
