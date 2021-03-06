#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>

char *values[] = {"XXXX", "1234", "abcd", "xjvef", "NDSS"};
#define NUM_VALUES 5

List *create_words()
{
	int i = 0;
	List *words = list_create();

	for(i=0; i<NUM_VALUES; i++) {
		list_push(words, values[i]);
	}

	return words;
}

int is_sorted(List *words)
{
	ListNode *cur = NULL;
	for(cur=words->first; cur!=NULL; cur=cur->next) {
		if(cur->next && strcmp(cur->value, cur->next->value)>0) {
			debug("%s %s", (char *)cur->value, (char *)cur->next->value);
			return 0;
		}
	}

	return 1;
}

char *test_bubble_sort()
{
	List *words = create_words();

	int rc = list_bubble_sort(words, (list_compare)strcmp);
	mu_assert(rc==0, "Bubble sort failed.");
	mu_assert(is_sorted(words), 
		"Words should be sort if already bubble sorted.");

	list_destroy(words);

	words = list_create();
	rc = list_bubble_sort(words, (list_compare)strcmp);
	mu_assert(rc==0, "Bubble sort failed on empty list.");
	mu_assert(is_sorted(words), "Words should be sorted if empty.");

	list_destroy(words);

	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_bubble_sort);

	return NULL;
}

RUN_TESTS(all_tests);