#include <CppUTest/TestHarness.h>

#include "linked_list.h"

TEST_GROUP(linked_list) {
	linked_list *list;
	void setup() {
		list = linked_list_create();
	}

	void teardown() {
		linked_list_destroy(list);
	}
};


TEST(linked_list, initial_size_is_0) {
	CHECK(0 == linked_list_size(list));
}

TEST(linked_list, adding_increments_size) {
	linked_list_add(list, (char*)"");
	CHECK(1 == linked_list_size(list));
}

TEST(linked_list, can_iterate_over_list) {
	linked_list_add(list, (char*)"hello");
	linked_list_add(list, (char*)"world");
	list_iterator *iter = linked_list_begin(list);
	CHECK(linked_list_has_next(iter));
	CHECK_EQUAL_C_STRING("hello", (const char*)linked_list_next(iter));
	CHECK_EQUAL_C_STRING("world", (const char*)linked_list_next(iter));
	CHECK(0 == linked_list_has_next(iter));
}
