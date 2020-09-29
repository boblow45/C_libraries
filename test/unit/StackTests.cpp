extern "C"
{
#include "stack.h"
#include <stdint.h>
}

#include <gtest/gtest.h>

TEST(StackTests, push_stack) {

	int32_t buffer[4];
	Stack_T stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));

	push_stack(stack, 42);

	push_stack(stack, 43);
	EXPECT_EQ(43, pop_stack(stack));
	EXPECT_EQ(42, pop_stack(stack));
}

TEST(StackTests, pop_stack) {

	int32_t buffer[4];
	Stack_T stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));

	EXPECT_EQ(-1, pop_stack(stack));

	push_stack(stack, 42);

	EXPECT_EQ(42, pop_stack(stack));
}

TEST(StackTests, peek_stack) {

	int32_t buffer[4];
	Stack_T stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));

	EXPECT_EQ(-1, peek_stack(stack));

	push_stack(stack, 42);

	EXPECT_EQ(42, peek_stack(stack));
}

TEST(StackTests, is_full) {

	int32_t buffer[2];
	Stack_T stack = create_stack(buffer, sizeof(buffer) / sizeof(buffer[0]));

	EXPECT_EQ(true, is_stack_empty(stack));
	EXPECT_EQ(false, is_stack_full(stack));

	push_stack(stack, 42);
	EXPECT_EQ(false, is_stack_empty(stack));
	EXPECT_EQ(false, is_stack_full(stack));

	push_stack(stack, 43);
	EXPECT_EQ(false, is_stack_empty(stack));
	EXPECT_EQ(true, is_stack_full(stack));
}