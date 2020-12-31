#include "./../../include/red_black_bst.hpp"

#include <gtest/gtest.h>

TEST(RBBSTTests, Create) {

	RBTree rbtree;
}

TEST(RBBSTTests, Insert) {

	RBTree rbtree;
	rbtree.insert(1);
	rbtree.insert(2);
	rbtree.insert(3);
	rbtree.insert(4);
	rbtree.insert(5);

	EXPECT_TRUE(rbtree.search(2));
	EXPECT_TRUE(rbtree.search(1));
	EXPECT_TRUE(rbtree.search(3));
	EXPECT_FALSE(rbtree.search(42));
}
