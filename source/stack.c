
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "stack.h"

struct stack_s {
	int32_t* buffer;
	uint32_t capacity;
	uint32_t num_items;
};

Stack_T create_stack(int32_t* buffer, uint32_t capacity) {
	Stack_T stack = (Stack_T)malloc(sizeof(struct stack_s));
	stack->buffer = buffer;
	stack->capacity = capacity;
	stack->num_items = 0;
	return stack;
}

bool is_stack_full(Stack_T stack) {
	return stack->capacity == stack->num_items;
}

bool is_stack_empty(Stack_T stack) {
	return stack->num_items == 0;
}

void push_stack(Stack_T stack, int32_t item) {
	if(is_stack_full(stack)) {
		return;
	}
	stack->buffer[stack->num_items++] = item;
}

int32_t pop_stack(Stack_T stack) {
	if(is_stack_empty(stack)) {
		return -1;
	}
	return stack->buffer[--stack->num_items];
}

int32_t peek_stack(Stack_T stack) {
	if(is_stack_empty(stack)) {
		return -1;
	}
	return stack->buffer[stack->num_items - 1];
}