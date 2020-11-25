extern "C"
{
#include "./../../include/sorting_alg.h"
#include <stdint.h>
}

#include <cstring>
#include <iostream>

#include <gtest/gtest.h>

TEST(SortingAlgTests, qsort) {

	int32_t data[] = {1, 3, 2, 5};

	int32_t expected_result[] = {1, 2, 3, 5};
	quick_sort(data, 0, sizeof(data) / sizeof(data[0]) - 1);

	EXPECT_TRUE(0 == std::memcmp(expected_result, data, sizeof(data)));
}

TEST(SortingAlgTests, mergeSort) {

	int32_t data[] = {1, 3, 2, 5};

	int32_t expected_result[] = {1, 2, 3, 5};
	merge_sort(data, 0, sizeof(data) / sizeof(data[0]) - 1);

	EXPECT_TRUE(0 == std::memcmp(expected_result, data, sizeof(data)));
}

int32_t cmpfunc(const void* a, const void* b) //what is it returning?
{

	int val1 = *(int*)a;
	int val2 = *(int*)b;

	return (val1 - val2);
}

TEST(SortingAlgTests, QuickSort) {

	int32_t data[] = {5, 2, 1, 13, 3, 4};
	int32_t expected_result[] = {1, 2, 3, 4, 5, 13};
	quickSort(data, sizeof(data) / sizeof(data[0]), sizeof(data[0]), cmpfunc);
	EXPECT_TRUE(0 == std::memcmp(expected_result, data, sizeof(data)));

	int32_t data1[] = {2, 1};
	int32_t expected_result1[] = {1, 2};
	quickSort(data1, sizeof(data1) / sizeof(data1[0]), sizeof(data1[0]), cmpfunc);
	EXPECT_TRUE(0 == std::memcmp(expected_result1, data1, sizeof(data1)));

	int32_t data2[] = {3, 2, 1};
	int32_t expected_result2[] = {1, 2, 3};
	quickSort(data2, sizeof(data2) / sizeof(data2[0]), sizeof(data2[0]), cmpfunc);
	EXPECT_TRUE(0 == std::memcmp(expected_result2, data2, sizeof(data2)));
}
