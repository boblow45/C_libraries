#ifndef __BIN_SEARCH_TREE__
#define __BIN_SEARCH_TREE__

#include <cstdint>

typedef struct bst_node_s* bst_node_t;

class BST {
private:
	bst_node_t root;

	bst_node_t insert(bst_node_t root, int32_t value);
	bst_node_t findMaxNode(bst_node_t root);
	bst_node_t findMinNode(bst_node_t root);
	bst_node_t makeEmpty(bst_node_t root);
	bst_node_t remove(bst_node_t root, int32_t value);

	bst_node_t find(bst_node_t root, int32_t x);

public:
	/**
	 * @brief Construct a new BST object, with is root node set to NULL
	 * 
	 */
	BST();
	/**
	 * @brief Construct a new BST object and add value to the root node.
	 * 
	 * @param value: value to add to the BST tree at when it is created
	 */
	BST(int32_t value);

	/**
	 * @brief Method is used to insert data into BST data structure
	 * 
	 * @param value: data to be added to the binary search trees 
	 */
	void insert(int32_t value);

	/**
	 * @brief  Method allows users to remove "value" from the BST data structure
	 * 
	 * @param value: value to be removed from the BST 
	 */
	void remove(int32_t value);
	/**
	 * @brief Method allows users to search the BST for the value of intest, but not remove it.
	 * 
	 * 
	 * @param value: value to search for 
	 * @return true 
	 * @return false 
	 */
	bool search(int32_t value);
};

#endif // __BIN_SEARCH_TREE__