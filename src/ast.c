#include "ast.h"

ASTNode *CreateASTNode(ASTNodeType type, void *data) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = type;
    node->data = data;

    return node;
}
