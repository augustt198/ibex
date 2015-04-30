#include <stdlib.h>
#include <string.h>
#include "simclist.h"
#include "ast.h"

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

ASTNode *CreateUnprocessedBody(char **lines, int len,
    int *pos, int lvl);
