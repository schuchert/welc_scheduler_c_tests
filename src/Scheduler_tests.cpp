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
	linked_list *found;

	TEST_SETUP() {
		d = Date_create();
		e = event_create(d, Time2PM);
		s = Scheduler_create();
		Scheduler_add_event(s, e);
		found = linked_list_create();
	}

	TEST_TEARDOWN() {
		Scheduler_delete(s);
		Date_release(d);
		linked_list_destroy(found);
	}

};

TEST(Scheduler_tests, find_added_event) {
	Scheduler_all_events_on(s, *d, found);
	int size = linked_list_size(found);
	CHECK(1 == size);
}

TEST(Scheduler_tests, find_event_broken) {
	Date d2;
	Date_to_now(&d2);
	Scheduler_all_events_on(s, d2, found);
	int size = linked_list_size(found);
	CHECK(1 == size);
}
