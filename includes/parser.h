#include <stdlib.h>
#include <string.h>
#include "simclist.h"

enum BlockEntryType {
    BLOCK,
    LINE
};

typedef struct {
    enum BlockEntryType type;
    union {
        struct { list_t *block; };
        struct { char *line; };
    };
} BlockEntry;

list_t *Blockify(char** lines, int len, int *pos, int lvl);
