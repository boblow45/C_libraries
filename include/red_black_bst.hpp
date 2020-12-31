#ifndef __RED_BLACK_BST__
#define __RED_BLACK_BST__

#include <cstdint>
#include <iostream>

enum Color { RED, BLACK };

struct Node {
	uint32_t data;
	Color color;
	Node *left, *right, *parent;

	Node(uint32_t data)
		: data(data)
		, color(Color::BLACK) {
		this->left = this->right = this->parent = this;
	}

	Node()
		: data(0)
		, color(Color::BLACK) {
		this->left = this->right = this->parent = this;
	}
};

class RBTree {
private:
	Node* root;
	Node* nil;
	Node* createNode(const uint32_t& data);
	void rotateRight(Node*&);
	void rotateLeft(Node*&);
	void insertFixViolation(Node*&);

public:
	RBTree();
	void insert(const uint32_t& data);
	void inOrder(void);
	void levelOrder(void);
	bool search(const uint32_t& data);
};

#endif // __RED_BLACK_BST__