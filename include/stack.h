#ifndef __STACK__
#define __STACK__

#include <stdbool.h>
#include <stdint.h>

typedef struct stack_s* Stack_T;

/**
 * @brief Create a stack object
 * 
 * @param buffer array where data is to be stored 
 * @param capacity length of the buffer passed to the function 
 * @return Stack_T 
 */
Stack_T create_stack(int32_t* buffer, uint32_t capacity);

/**
 * @brief Returns true if there is no space in the stack 
 * 
 * @param stack: Pointer to stack to be checked if it is full
 * @return true 
 * @return false 
 */
bool is_stack_full(Stack_T stack);

/**
 * @brief Function to check if the stack is empty 
 * 
 * @param stack: Pointer to check if the stack is empty 
 * @return true 
 * @return false 
 */
bool is_stack_empty(Stack_T stack);

/**
 * @brief Function to push data onto the stack 
 * 
 * @param stack: Pointer to stack
 * @param item: value to push onto the stack 
 */
void push_stack(Stack_T stack, int32_t item);

/**
 * @brief Function which allows users to pop the last element off the stack
 * 
 * @param stack: Pointer to the stack
 * @return int32_t
 */
int32_t pop_stack(Stack_T stack);

/**
 * @brief Function which returns the last value from the stack, but without removing it.
 * 
 * @param stack: Pointer to stack
 * @return int32_t 
 */
int32_t peek_stack(Stack_T stack);

#endif // __STACK__
