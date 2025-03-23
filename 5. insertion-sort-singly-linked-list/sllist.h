#ifndef SLLIST_H
#define SLLIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* SLL_Create();
void SLL_AddLast(List* list, int value);
void SLL_Print(List* list);
void SLL_Destroy(List* list);
List* SLL_InsertionSort(List* original);

#endif // SLLIST_H
