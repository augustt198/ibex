#include "util.h"
#include "simclist.h"

typedef enum ASTNodeType {
    BODY_NODE, LINE_NODE
} ASTNodeType;

typedef struct {
    ASTNodeType type;
    void *data;
} ASTNode;

ASTNode *CreateASTNode(ASTNodeType type, void *data);

typedef struct {
    bool processed;
    list_t *children;
} Body;

typedef struct {
    char *line;
} Line;
