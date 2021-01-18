#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "except.h"
#define T Except_T

Except_Frame *Except_stack = NULL;

void Except_raise(const T *e, const char * file, uint32_t line){
    Except_Frame *p = Except_stack;

    assert(e);
    if(p == NULL){
        fprintf(stderr, "Uncaught exception");
        if (e->reason)
            fprintf(stderr, " at 0x%p", e->reason);
        else
            fprintf(stderr, " at 0x%p", e);
        if (file && line >0)
            fprintf(stderr," raised at %s:%d\n", file, line);
        fprintf(stderr, "abouting...\n"); 
        fflush(stderr);
        abort();
    }

    p->exception = e;
    p->file = file;
    p->line = line; 
    Except_stack = Except_stack->prev;
    longjmp(p->env, Except_raised); 
}
