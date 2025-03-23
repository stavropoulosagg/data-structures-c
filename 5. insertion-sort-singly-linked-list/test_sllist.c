#include "acutest.h"
#include "sllist.h"

void test_insertion_sort_basic() {
    List* list = SLL_Create();
    SLL_AddLast(list, 5);
    SLL_AddLast(list, 1);
    SLL_AddLast(list, 4);
    SLL_AddLast(list, 2);
    SLL_AddLast(list, 3);

    List* sorted = SLL_InsertionSort(list);

    Node* node = sorted->head;
    int expected[] = {1, 2, 3, 4, 5};
    int i = 0;
    while (node != NULL) {
        TEST_CHECK(node->value == expected[i]);
        node = node->next;
        i++;
    }

    SLL_Destroy(sorted);
    free(list); // list is empty shell now
}

TEST_LIST = {
    {"Insertion Sort Basic", test_insertion_sort_basic},
    {NULL, NULL}
};
