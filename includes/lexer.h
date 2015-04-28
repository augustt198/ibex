#include "sds.h"
#include <stdlib.h>
#include <string.h>
#include "util.h"

typedef enum TokenType {
    TOK_IDENT,
    TOK_STRING,
    TOK_NUMBER,
    TOK_L_PAREN,
    TOK_R_PAREN,
    TOK_ADD,
    TOK_SUB,
    TOK_MUL,
    TOK_DIV,
    TOK_REM,
    TOK_EOF
} TokenType;

typedef struct {
    char *content;
    int  len;
    int  type;
} Token;

Token* TokenNew(char *content, TokenType type);

typedef struct {
    char *source;
    int  len;
    int  position;
} Lexer;

Lexer *LexerNew(char *source, int len);
char LexerReadChar(Lexer *lex);
char LexerPeekChar(Lexer *lex);
Token *LexerNext(Lexer *lex);
