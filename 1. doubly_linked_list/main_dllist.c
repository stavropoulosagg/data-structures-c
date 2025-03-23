#include <stdio.h>
#include "as_doubly_linked_list.h"

int main() {
    ListPtr list = DLL_Create();

    DLL_AddLast(list, 10);
    DLL_AddLast(list, 20);
    DLL_AddFirst(list, 5);
    DLL_AddFirst(list, 2);

    printf("List contents: ");
    DLL_Print(list);

    printf("Size: %d\n", DLL_Size(list));
    printf("Is empty? %d\n", DLL_IsEmpty(list));

    printf("First: %d\n", DLL_GetFirst(list));
    printf("Last: %d\n", DLL_GetLast(list));

    NodePtr node = DLL_GetNode(list, 10);
    if (node != NULL) {
        printf("Node with value 10 found. Adding 9 before and 11 after it.\n");
        DLL_AddBefore(list, node, 9);
        DLL_AddAfter(list, node, 11);
    }

    DLL_Print(list);

    printf("Removing all nodes with value 20...\n");
    DLL_Remove(list, 20);
    DLL_Print(list);

    DLL_Destroy(list);
    return 0;
}

/*
Expected Output:
---------------------
List contents: 2 5 10 20 
Size: 4
Is empty? 0
First: 2
Last: 20
Node with value 10 found. Adding 9 before and 11 after it.
2 5 9 10 11 20 
Removing all nodes with value 20...
2 5 9 10 11 
*/
