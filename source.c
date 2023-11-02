#include <errno.h>
#include "shell.h"
#include "source.h"
//return last character we've retrieved from input
void unget_char(struct source_s *src){
    if(src->curpos < 0){
        return;
    }
    src->curpos--;
}
//return the next character of input and updates the source pointer
char next_char(struct source_s *src){
    if(!src || !src->buffer){
        errno = ENODATA;
        return ERRCHAR;
    }
    char c1 = 0;
    if (src->curpos == INIT_SRC_POS){
        src ->curpos = -1;
    }
    else{
        c1 = src->buffer[src->curpos];
    }
    if (++src->curpos >= src->bufsize){
        src->curpos = src->bufsize;
        return EOF;
    }
    return src->buffer[src->curpos];
}
//return next character of input but doesn't update the source pointer
char peek_char(struct source_s *src){
    if(!src || !src->buffer){
        errno = ENODATA;
        return ERRCHAR;
    }
    long pos = src->curpos;
    if (pos == INIT_SRC_POS){
        pos++;
    }
    pos++;
    if (pos >= src->bufsize){
        return EOF;
    }
    return src->buffer[pos];
}
//skip all whitespace characters
void skip_white_spaces(struct source_s *src){
    char c;
    if (!src || !src->buffer){
        return;
    }
    while(((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t')){
        next_char(src);
    }
}