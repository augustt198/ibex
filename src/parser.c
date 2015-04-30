#include "parser.h"

int getIndentationLevel(char *line) {
    int len = strlen(line);

    int i = 0;
    for (; i < len && line[i] == ' '; i++);

    return i;
}

// TODO fix ugly pos pointer
ASTNode *CreateUnprocessedBody(char **lines, int len,
    int *pos, int lvl) {

    Body *body = malloc(sizeof(Body));

    body->processed = false;
    body->children  = malloc(sizeof(list_t));
    list_init(body->children);
    list_attributes_copy(body->children, list_meter_pointer, 0);

    ASTNode *node = CreateASTNode(BODY_NODE, body);

    while (*pos < len) {
        int indent = getIndentationLevel(lines[*pos]);
        if (indent == lvl) {
            Line *line = malloc(sizeof(line));
            line->line = lines[*pos];
            ASTNode *linenode = CreateASTNode(LINE_NODE, line);

            list_append(body->children, linenode);
            *pos += 1;

        } else if (indent == lvl + 4) {
            ASTNode *subnode = CreateUnprocessedBody(
                lines, len, pos, indent
            );

            list_append(body->children, subnode);
        } else {
            break;
        }
    }

    return node;
}
