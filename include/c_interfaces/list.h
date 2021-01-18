#ifndef LIST_INCLUDED
#define LIST_INCLUDED

#include <stdint.h>

#define T struct List_T*

extern T List_create(void* x);
extern T List_append(T list, T tail);
extern T List_copy(T list);
extern T List_list(void* x, ...);
extern T List_pop(T list, void** x);
extern T List_push(T list, void* x);
extern T List_reverse(T list);
extern uint32_t List_length(T list);
extern void List_free(T* list);
extern void List_map(T list, void apply(void** x, void* cl), void* cl);
extern void** List_toArray(T list, void* end);

#undef T
#endif