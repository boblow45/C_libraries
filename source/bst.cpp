#include "bst.hpp"

#include <cstdint>
#include <iostream>

struct bst_node_s {
	int32_t data;
	struct bst_node_s* left;
	struct bst_node_s* right;
};

BST::BST() {
	this->root = NULL;
}

BST::BST(int32_t value) {
	this->root = new bst_node_s;
	this->root->data = value;
}

void BST::insert(int32_t value) { }