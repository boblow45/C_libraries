#ifndef __LINK_LIST__
#define __LINK_LIST__

#include <stdint.h>

typedef struct node_s* node_t;

/**
 * @brief Create a linked list 
 * 
 * @param val: value to put in the first node
 * @return node_t: pointer to linked list
 */
node_t create(int32_t val);

/**
 * @brief Function to push value onto the linked list
 * 
 * @param head: head of the linked list
 * @param val: Value to add to the linked list
 */
void push(node_t* head, int32_t val);

/**
 * @brief Function to pop the head element of the linked list
 * 
 * @param head: linked list to pop value off of
 * @return int32_t: popped value
 */
int32_t pop(node_t* head);

/**
 * @brief Function to remove the last value from the linked list 
 * 
 * @param head: linked list to remove the value from 
 * @return int32_t: removed value
 */
int32_t remove_last(node_t head);

/**
 * @brief Remove a value linked list by its index
 * 
 * @param head: linked list to remove value from
 * @param n: index of the value to remove 
 * @return int32_t: value of the index removed 
 */
int32_t remove_by_index(node_t* head, uint32_t n);

/**
 * @brief Remove a node from the linked list based on value
 * 
 * @param head: linked list to remove value from
 * @param val: value to remove.
 */
void remove_by_value(node_t* head, uint32_t val);

#endif // __LINK_LIST__