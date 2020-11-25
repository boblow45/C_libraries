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

void BST::remove(int32_t value) {
	this->root = this->remove(this->root, value);
}

void BST::insert(int32_t value) {

	this->root = this->insert(this->root, value);
}

bool BST::search(int32_t value) {
	// Create a temp varable to store the node to be checked
	bst_node_t t = this->root;
	while(t != NULL) {

		// Return ture if the value is present
		if(t->data == value) {
			return true;
		}
		else if(value > t->data) {
			t = t->right;
		}
		else if(value < t->data) {
			t = t->left;
		}
	}
	// return false if the value is not present in the BST
	return false;
}

bst_node_t BST::findMaxNode(bst_node_t root) {
	if(root == NULL) {
		return NULL;
	}
	else if(root->right == NULL) {
		return root;
	}
	else {
		return this->findMaxNode(root->right);
	}
}
bst_node_t BST::findMinNode(bst_node_t root) {
	if(root == NULL) {
		return NULL;
	}
	else if(root->left == NULL) {
		return root;
	}
	else {
		return this->findMinNode(root->left);
	}
}

bst_node_t BST::insert(bst_node_t node, int32_t value) {

	// If the node passed to the function is NULL, a place to insert the value has been found
	if(node == NULL) {
		node = new bst_node_s;
		node->data = value;
		node->left = node->right = NULL;
	}
	// If the value is greater than the value of the current node, then it will go on the right node
	else if(value > node->data) {
		node->right = this->insert(node->right, value);
	}
	// If the value is less than the value of the current node then it will go on the left
	else if(value < node->data) {
		node->left = this->insert(node->left, value);
	}
	return node;
}

bst_node_t BST::remove(bst_node_t node, int32_t value) {

	bst_node_t temp;

	// -------------------------------------- Search for node -------------------------------
	// The value is not present in the BST
	if(node == NULL) {
		return NULL;
	}
	// if value is less than the current nodes value, then the node to be remove is in the left leaf node of the current node
	else if(value < node->data) {
		node->left = this->remove(node->left, value);
	}
	// if value is greater than the current nodes value, then the node to be remove is in the right leaf node of the current node
	else if(value > node->data) {
		node->right = this->remove(node->right, value);
	}

	// -------------------------------------- Removal ----------------------------------------
	// If the node which is to be removed has two non NULL leaf nodes
	else if(node->left && node->right) {
		// Find the next successor. The next successors value will replace the value of the node
		temp = this->findMinNode(node->right);
		// Set the value of the current node to that of the successor
		node->data = temp->data;
		// remove the successor node from the BST as it has replaced the current node.
		node->right = this->remove(node->right, node->data);
	}
	// If the node to be removed does not have two valid leaf nodes
	else {
		temp = node;
		// if the left node is NULL, set the current node to the right node
		if(node->left == NULL) {
			node = node->right;
		}
		// if the right node is NULL, set the current node to the left node
		else if(node->right == NULL) {
			node = node->left;
		}

		// remove the current node with the value which was selected to be removed
		delete temp;
	}

	return node;
}
