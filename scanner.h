#ifndef SCANNER_H
#define SCANNER_H

struct  token_s
{
    /* data */
    struct source_s *src; //source of input
    int text_len;
    char *text;
};

extern struct token_s eof_token;

struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);

#endif