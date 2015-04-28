#include "driver.h"

void compile(char *source) {
    Lexer *lex = LexerNew(source, strlen(source));

    for (;;) {
        Token *tok = LexerNext(lex);
        printf("%d", tok->type);
        if (tok->content != NULL) {
            printf(", %s\n", tok->content);
        } else {
            printf("\n");
        }
        if (tok->type == TOK_EOF) {
            break;
        }
    }
}
