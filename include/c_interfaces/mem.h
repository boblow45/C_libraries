#ifndef MEM_INCLUDED
#define MEM_INCLUDED
#include <stdint.h>

#include "except.h"

extern const Except_T Mem_Failed;
extern void* Mem_alloc(uint32_t nbytes, const char* file, uint32_t line);
extern void* Mem_calloc(uint32_t count, uint32_t nbytes, const char* file, uint32_t line);
extern void Mem_free(void* ptr, const char* file, uint32_t line);
extern void* Mem_resize(void* ptr, uint32_t nbytes, const char* file, uint32_t line);

#define ALLOC(nbytes) Mem_alloc((nbytes), __FILE__, __LINE__)
#define CALLOC(count, nbytes) Mem_calloc((count), (nbytes), __FILE__, __LINE__)
#define NEW(p) ((p) = ALLOC((uint32_t)sizeof *(p)))
#define NEWO(p) ((p) = CALLOC(1, (uint32_t)sizeof *(p)))
#define FREE(ptr) ((void)(Mem_free((ptr), __FILE__, __LINE__), (ptr) = 0))
#define RESIZE(ptr, nbytes) ((ptr) = Mem_resize((ptr), (nbytes), __FILE__, __LINE__))
#endif