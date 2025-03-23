#include <stdio.h>
#include "sllist.h"

int main() {
    List* list = SLL_Create();
    SLL_AddLast(list, 4);
    SLL_AddLast(list, 2);
    SLL_AddLast(list, 5);
    SLL_AddLast(list, 1);
    SLL_AddLast(list, 3);

    printf("Original list: \n");
    SLL_Print(list);

    List* sorted = SLL_InsertionSort(list);
    printf("Sorted list: \n");
    SLL_Print(sorted);

    SLL_Destroy(sorted);
    free(list); // We already moved the nodes, just free the empty shell

    return 0;
}
