#include "lexer.h"

Token *TokenNew(char *content, TokenType type) {
    Token *tok   = malloc(sizeof(Token));
    tok->content = content;
    if (content != NULL) {
        tok->len = strlen(content);
    }
    tok->type    = type;

    return tok;
}

Lexer *LexerNew(char *source, int len) {
    Lexer *lex    = malloc(sizeof(Lexer));
    lex->source   = source;
    lex->len      = len;
    lex->position = 0;
    
    return lex;
}

char LexerReadChar(Lexer *lex) {
    char c = lex->source[lex->position];
    lex->position++;
    return c;
}

char LexerPeekChar(Lexer *lex) {
    return lex->source[lex->position];
}

Token *lexerNextStringTok(Lexer *lex);
Token *lexerNextIdentTok(Lexer *lex, char first);
Token *lexerNextNumberTok(Lexer *lex, char first);

Token *LexerNext(Lexer *lex) {
    for(;;) {
        if (lex->position >= lex->len) {
            return TokenNew(NULL, TOK_EOF);
        }

        char c = LexerReadChar(lex);
        switch (c) {
            case '(':
                return TokenNew(NULL, TOK_L_PAREN);
            case ')':
                return TokenNew(NULL, TOK_R_PAREN);
            case '+':
                return TokenNew(NULL, TOK_ADD);
            case '-':
                return TokenNew(NULL, TOK_SUB);
            case '*':
                return TokenNew(NULL, TOK_MUL);
            case '/':
                return TokenNew(NULL, TOK_DIV);
            case '%':
                return TokenNew(NULL, TOK_REM);
            case '"':
                return lexerNextStringTok(lex);
            default:
                if (isAlpha(c) || c == '_') {
                    return lexerNextIdentTok(lex, c);
                } else if (isDigit(c)) {
                    return lexerNextNumberTok(lex, c);
                } else {
                    if (c == ' ' || c == '\n' || c == '\t') {
                        continue;
                    } else {
                        printf("Unknown char: %c\n", c);
                        abort();
                    }
                }
        }
    }
}

Token *lexerNextStringTok(Lexer *lex) {
    sds string = sdsempty();
    for(;;) {
        char c = LexerReadChar(lex);
        if (c == '"') {
            break;
        } else {
            string = sdscatc(string, c);
        }
    }

    return TokenNew(string, TOK_STRING);
}

Token *lexerNextIdentTok(Lexer *lex, char chr) {
    sds string = sdsempty();
    string = sdscatc(string, chr);
    for (;;) {
        char c = LexerPeekChar(lex);
        if (isAlpha(c) || isDigit(c) || c == '_') {
            string = sdscatc(string, c);
            LexerReadChar(lex);
        } else {
            break;
        }
    }

    return TokenNew(string, TOK_IDENT);
}

Token *lexerNextNumberTok(Lexer *lex, char first) {
    sds string = sdscatc(sdsempty(), first);
    for (;;) {
        char c = LexerPeekChar(lex);
        if (isDigit(c)) {
            string = sdscatc(string, c);
            LexerReadChar(lex);
        } else {
            break;
        }
    }

    return TokenNew(string, TOK_NUMBER);
}
