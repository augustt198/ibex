#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sds.h"

char *file2str(char *name);

bool isAlpha(char c);
bool isDigit(char c);

sds sdscatc(sds s, char chr);