#include <CppUTest/TestHarness.h>

#include <stdlib.h>
#include "Scheduler.h"
#include "linked_list.h"

#include "Date.h"
#include "Event.h"
#include "DayTime.h"

TEST_GROUP(Scheduler_tests) {
	Date *d;
	Event *e;
	Scheduler *s;

	TEST_SETUP() {
		d = Date_create();
		e = event_create(d, Time2PM);
		s = Scheduler_create();
		Scheduler_add_event(s, e);
	}

	TEST_TEARDOWN() {
		Scheduler_delete(s);
		Date_release(d);
	}

};

TEST(Scheduler_tests, find_added_event) {
	linked_list *found = linked_list_create();
	Scheduler_all_events_on(s, *d, found);
	int size = linked_list_size(found);
	linked_list_destroy(found);
	CHECK(1 == size);
}

TEST(Scheduler_tests, find_event_broken) {
	Date d2;
	Date_to_now(&d2);
	linked_list *found = linked_list_create();
	Scheduler_all_events_on(s, d2, found);
	int size = linked_list_size(found);
	linked_list_destroy(found);
	CHECK(1 == size);
}

