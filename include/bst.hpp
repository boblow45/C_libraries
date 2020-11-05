#ifndef __BIN_SEARCH_TREE__
#define __BIN_SEARCH_TREE__

#include <cstdint>

typedef struct bst_node_s* bst_node_t;

class BST {
private:
	bst_node_t root;

	bst_node_t insert(bst_node_t root, int32_t value);
	bst_node_t findMax(bst_node_t root);
	bst_node_t findMin(bst_node_t root);
	bst_node_t makeEmpty(bst_node_t root);
	bst_node_t remove(bst_node_t root, int32_t value);

	bst_node_t find(bst_node_t root, int32_t x);

public:
	BST();
	BST(int32_t value);
	void insert(int32_t value);
	void remove(int32_t value);
};

#endif // __BIN_SEARCH_TREE__