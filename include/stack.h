#ifndef __STACK__
#define __STACK__

#include <stdbool.h>
#include <stdint.h>

typedef struct stack_s* Stack_T;

Stack_T create_stack(int32_t* buffer, uint32_t capacity);
bool is_stack_full(Stack_T stack);
bool is_stack_empty(Stack_T stack);
void push_stack(Stack_T stack, int32_t item);
int32_t pop_stack(Stack_T stack);
int32_t peek_stack(Stack_T stack);

#endif // __STACK__
