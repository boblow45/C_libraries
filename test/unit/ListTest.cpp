extern "C"
{
#include "./../../include/c_interfaces/list.h"
#include <stddef.h>
#include <stdint.h>
}

#include <gtest/gtest.h>

TEST(ListTests, Create) {
	List_T* ls;
	uint32_t data = 42;
	ls = List_create(&data);

	uint32_t* cap_data;
	ls = List_pop(ls, (void**)(&cap_data));

	EXPECT_EQ(data, *cap_data);
	EXPECT_TRUE(ls == NULL);
}

TEST(ListTests, Push) {
	List_T* ls;
	uint32_t data = 42;
	ls = List_create(&data);

	uint32_t exp_data = 13;
	ls = List_push(ls, &exp_data);

	uint32_t* cap_data;
	ls = List_pop(ls, (void**)(&cap_data));

	EXPECT_EQ(exp_data, *cap_data);
	EXPECT_TRUE(ls != NULL);
}

TEST(ListTests, Append) {

	uint32_t data1 = 42;
	List_T* ls1 = List_create(&data1);

	uint32_t data2 = 13;
	List_T* ls2 = List_create(&data2);

	List_T* append_lst = List_append(ls1, ls2);

	uint32_t* cap_data;
	List_T* ls = List_pop(append_lst, (void**)(&cap_data));
	EXPECT_EQ(42, *cap_data);
	ls = List_pop(ls, (void**)(&cap_data));
	EXPECT_EQ(13, *cap_data);
	EXPECT_TRUE(ls == NULL);
}

TEST(ListTests, Copy) {

	uint32_t data1 = 42;
	List_T* ls1 = List_create(&data1);

	List_T* lst_cpy;
	lst_cpy = List_copy(ls1);

	uint32_t* cap;
	lst_cpy = List_pop(lst_cpy, (void**)(&cap));
	EXPECT_EQ(data1, *cap);
	EXPECT_TRUE(lst_cpy == NULL);
}

TEST(ListTests, Reverse) {

	uint32_t data = 42;
	List_T* ls;
	ls = List_create(&data);

	uint32_t data2 = 13;
	ls = List_push(ls, &data2);

	List_T* rev_lst;
	rev_lst = List_reverse(ls);

	uint32_t* rt_data;

	rev_lst = List_pop(rev_lst, (void**)(&rt_data));
	EXPECT_EQ(42, *rt_data);

	rev_lst = List_pop(rev_lst, (void**)(&rt_data));
	EXPECT_EQ(13, *rt_data);
}

TEST(ListTests, Length) {

	uint32_t data1 = 42;
	List_T* ls1 = List_create(&data1);

	EXPECT_EQ(1, List_length(ls1));

	ls1 = List_push(ls1, &data1);
	EXPECT_EQ(2, List_length(ls1));
}

TEST(ListTests, ToArray) {

	uint32_t data[] = {13, 42};
	List_T* ls1 = List_create(data);
	ls1 = List_push(ls1, &data[1]);

	uint32_t sentinel = 0;
	void** ls_to_array;
	ls_to_array = List_toArray(ls1, &sentinel);

	uint8_t list_len = sizeof(data) / sizeof(data[0]);
	for(uint8_t i = 0; i < list_len; i++) {
		EXPECT_EQ(data[list_len - 1 - i], *(uint32_t*)ls_to_array[i]);
	}
}