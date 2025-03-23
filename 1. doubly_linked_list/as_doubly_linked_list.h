#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// Opaque type declarations (info hiding)
typedef struct List* ListPtr;
typedef struct Node* NodePtr;

// === Core list operations ===
ListPtr DLL_Create();
void DLL_Destroy(ListPtr list);
int DLL_Size(ListPtr list);
int DLL_IsEmpty(ListPtr list);

// === Element access ===
int DLL_GetFirst(ListPtr list);
int DLL_GetLast(ListPtr list);
NodePtr DLL_GetNode(ListPtr list, int value);
int DLL_GetPrev(NodePtr node);
int DLL_GetNext(NodePtr node);

// === Insertion ===
void DLL_AddBefore(ListPtr list, NodePtr node, int value);
void DLL_AddAfter(ListPtr list, NodePtr node, int value);
void DLL_AddFirst(ListPtr list, int value);
void DLL_AddLast(ListPtr list, int value);

// === Deletion ===
void DLL_Remove(ListPtr list, int value);

// === Debug/Utility ===
void DLL_Print(ListPtr list);

#endif // DOUBLY_LINKED_LIST_H
