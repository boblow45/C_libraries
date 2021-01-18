#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "except.h"
#include "mem.h"

void * Mem_alloc(uint32_t nbytes, const char * file, uint32_t line){
    void * ptr;
    assert(nbytes > 0);
    ptr = malloc(nbytes);
    if (ptr == NULL){
        if (file == NULL){
            RAISE(Mem_Failed);
            }
        else{
            Except_raise(&Mem_Failed, file, line);
        }
        
    }

    return ptr;
}

void * Mem_calloc(uint32_t count, uint32_t nbytes, const char * file, uint32_t line){
    void * ptr;

    assert(count > 0);
    assert(nbytes > 0);
    ptr = calloc(count, nbytes);
    if (ptr == NULL){
        if (file == NULL){
            RAISE(Mem_Failed);
            }
        else{
            Except_raise(&Mem_Failed, file, line);
        }
    }
    return ptr;
}

void Mem_free(void * ptr, const char * file, uint32_t line){
    if(ptr){
        free(ptr);
    }
}

void * Mem_resize(void* ptr, uint32_t nbytes, const char * file, uint32_t line){

    assert(ptr);
    assert(nbytes > 0);
    ptr = realloc(ptr, nbytes);
    if(ptr == NULL){
        if (file == NULL){
            RAISE(Mem_Failed);
            }
        else{
            Except_raise(&Mem_Failed, file, line);
        }
    }
    return ptr;
}


const Except_T Mem_Failed = {"Allocation Failed"}; 