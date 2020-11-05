
#include "./../../include/hashmap.hpp"

#include <gtest/gtest.h>

TEST(HashMapTests, Create) {

	HashMap<int, int> h_map;
	EXPECT_EQ(1, 1);
}

TEST(HashMapTests, GetSize) {

	HashMap<int, int> h_map;
	EXPECT_EQ(0, h_map.getSize());
}

TEST(HashMapTests, Insert) {

	HashMap<int, int>* h_map = new HashMap<int, int>;
	h_map->insertNode(1, 1);
	EXPECT_EQ(1, h_map->getSize());
	h_map->insertNode(21, 1);
	EXPECT_EQ(2, h_map->getSize());
}

TEST(HashMapTests, Delete) {

	HashMap<int, int>* h_map = new HashMap<int, int>;
	h_map->insertNode(1, 42);
	EXPECT_EQ(1, h_map->getSize());
	int val = h_map->deleteNode(1);
	EXPECT_EQ(42, val);
	EXPECT_EQ(0, h_map->getSize());
}

TEST(HashMapTests, Get) {

	HashMap<int, int>* h_map = new HashMap<int, int>;
	h_map->insertNode(1, 42);
	EXPECT_EQ(42, h_map->get(1));
	EXPECT_EQ(1, h_map->getSize());
}
