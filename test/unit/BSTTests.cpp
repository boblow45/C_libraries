#include "./../../include/bst.hpp"

#include <gtest/gtest.h>

TEST(BSTTests, Create) {

	BST bst;
	EXPECT_EQ(1, 1);
}

TEST(BSTTests, Insert) {

	BST b(6);
	EXPECT_EQ(true, b.search(6));
	EXPECT_EQ(false, b.search(5));
	EXPECT_EQ(false, b.search(7));
	b.insert(5);
	EXPECT_EQ(true, b.search(5));
	EXPECT_EQ(false, b.search(7));
	b.insert(7);
	EXPECT_EQ(true, b.search(5));
	EXPECT_EQ(true, b.search(7));
}

TEST(BSTTests, remove) {

	BST b(13);

	int32_t insert_data[] = {42, 7, 3, 10, 11};

	for(int32_t i : insert_data) {
		b.insert(i);
		EXPECT_EQ(true, b.search(i));
	}

	b.remove(7);
	EXPECT_EQ(false, b.search(7));
	int32_t data_after_remove[] = {42, 3, 10, 11};
	for(int32_t i : insert_data) {
		b.insert(i);
		EXPECT_EQ(true, b.search(i));
	}
}
