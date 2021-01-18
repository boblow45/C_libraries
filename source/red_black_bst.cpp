#include "red_black_bst.hpp"

#include <cstdint>
#include <iostream>

RBTree::RBTree() {
	this->nil = new Node();
	this->nil->color = Color::BLACK;
	this->nil->left = this->nil;
	this->nil->right = this->nil;
	this->nil->parent = this->nil;
	this->root = this->nil;
}

Node* RBTree::createNode(const uint32_t& data) {
	Node* z = new Node(data);
	z->parent = this->nil;
	z->left = this->nil;
	z->right = this->nil;
	z->color = Color::RED;

	return z;
}

void RBTree::insert(const uint32_t& data) {

	Node* z = this->createNode(data);
	Node* y = this->nil;
	Node* x = this->root;

	while(x != this->nil) {
		y = x;
		if(z->data < x->data) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->parent = y;

	if(y == this->nil) {
		this->root = z;
	}

	else if(z->data < y->data) {
		y->left = z;
	}
	else {
		y->right = z;
	}

	this->insertFixViolation(z);
}

bool RBTree::search(const uint32_t& data) {

	Node* x = this->root;
	while(x != this->nil) {
		if(data < x->data) {
			x = x->left;
		}
		else if(data > x->data) {
			x = x->right;
		}
		else {
			return true;
		}
	}
	return false;
}

void RBTree::rotateRight(Node*& y) {
	/*
        <y>          <x>
       /  \  	    /  \
      <x> c   -->  a   <y>
     /  \ 		      /  \
    a    b           b    c
   */

	Node* x = y->left;
	y->left = x->right;

	if(x->right != this->nil) {
		x->right->parent = y;
	}

	x->parent = y->parent;

	if(y->parent == this->nil) {
		this->root = x;
	}
	else if(y == y->parent->left) {
		y->parent->left = x;
	}
	else {
		y->parent->right = x;
	}

	x->right = y;
	y->parent = x;
}

void RBTree::rotateLeft(Node*& x) {
	/*
      <x>              <y>
     /  \  	          /  \
    a  <y>   -->    <x>   c
      /  \	       /  \
     b   c        a    b
   */
	Node* y = x->right;
	x->right = y->left;

	if(y->left != this->nil) {
		y->left->parent = x;
	}

	y->parent = x->parent;

	if(x->parent == this->nil) {
		this->root = y;
	}
	else if(x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void RBTree::insertFixViolation(Node*& z) {
	Node* y;
	while(z->parent->color == Color::RED) {
		if(z->parent == z->parent->parent->left) {
			y = z->parent->parent->right;
			if(y->color == Color::RED) {
				y->color = Color::BLACK;
				z->parent->color = Color::BLACK;
				z->parent->parent->color = Color::RED;
				z = z->parent->parent;
			}
			else {

				if(z == z->parent->right) {
					z = z->parent;
					this->rotateLeft(z);
				}

				z->parent->color = Color::BLACK;
				z->parent->parent->color = Color::RED;
				this->rotateRight(z->parent->parent);
			}
		}
		else {
			y = z->parent->parent->left;
			if(y->color == Color::RED) {
				y->color = Color::BLACK;
				z->parent->color = Color::BLACK;
				z->parent->parent->color = Color::RED;
				z = z->parent->parent;
			}
			else {
				if(z == z->parent->left) {
					z = z->parent;
					this->rotateRight(z);
				}

				z->parent->color = Color::BLACK;
				z->parent->parent->color = Color::RED;
				this->rotateLeft(z->parent->parent);
			}
		}
	}
	this->root->color = Color::BLACK;
}
