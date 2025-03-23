#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct List {
    struct Node* head;
    struct Node* tail;
    int size;
}

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
}

ListPtr DLL_Create() {

    ListPtr list = malloc(sizeof(struct List));
    if (list == NULL) return NULL; // caller must check

    //initialization
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}


void DLL_Destroy(ListPtr list) {
    NodePtr temp;

    while (list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }

    free(list); // free the list struct itself
}

int DLL_Size(ListPtr list) {
    NodePtr temp = list->head;
    int size=0;

    while (temp!=NULL) {
        size++;
        temp = temp->next;
    }

    return size;
}

int DLL_IsEmpty(ListPtr list) {
    return list->head == NULL ? 1 : 0;
}

// === Insertion ===

void DLL_AddFirst(ListPtr list, int value) {
    NodePtr temp = malloc(sizeof(struct Node));
    if (temp == NULL) return;

    temp->value = value;
    temp->next = list->head;
    temp->prev = NULL;

    if (list->head != NULL)
        list->head->prev = temp;
    else
        list->tail = temp;

    list->head = temp;
    list->size++;
}


void DLL_AddLast(ListPtr list, int value) {
    NodePtr temp = malloc(sizeof(struct Node));
    if (temp == NULL) return;

    temp->value = value;
    temp->next = NULL;
    temp->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = temp;
    else
        list->head = temp;

    list->tail = temp;
    list->size++;
}


void DLL_AddAfter(ListPtr list, NodePtr node, int value) {
    if (list == NULL || node == NULL) return;

    NodePtr newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->value = value;
    newNode->prev = node;
    newNode->next = node->next;

    // Have to check if node is the last node / tail
    if (node->next != NULL) {
        node->next->prev = newNode;
    } else {
        // Node was the tail — update tail pointer
        list->tail = newNode;
    }

    node->next = newNode;
    list->size++;
}

void DLL_AddBefore(ListPtr list, NodePtr node, int value) {
    if (list == NULL || node == NULL) return;

    NodePtr newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    newNode->value = value;
    newNode->next = node;
    newNode->prev = node->prev;

    if (node->prev != NULL) {
        node->prev->next = newNode;
    } else {
        // Node was the head, so update list->head
        list->head = newNode;
    }

    node->prev = newNode;
    list->size++;
}

int DLL_GetFirst(ListPtr list) {
    if (list == NULL || list->head == NULL) return -1;
    return list->head->value;
}

int DLL_GetLast(ListPtr list) {
    if (list == NULL || list->tail == NULL) return -1;
    return list->tail->value;
}

NodePtr DLL_GetNode(ListPtr list, int value) {
    if (list == NULL || list->head == NULL) return NULL;

    NodePtr temp = list->head;
    while (temp != NULL && temp->value != value) {
        temp = temp->next;
    }

    return temp; // NULL if not found, valid pointer otherwise
}

int DLL_GetPrev(NodePtr node) {
    if (node == NULL || node->prev == NULL) return -1;
    return node->prev->value;
}

int DLL_GetNext(NodePtr node) {
    if (node == NULL || node->next == NULL) return -1;
    return node->next->value;
}

void DLL_Remove(ListPtr list, int value) {
    if (list == NULL || list->head == NULL) return;

    NodePtr temp = list->head;

    while (temp != NULL) {
        if (temp->value == value) {
            NodePtr toDelete = temp;

            // Move temp forward before deletion
            temp = temp->next;

            // Re-link previous node
            if (toDelete->prev != NULL)
                toDelete->prev->next = toDelete->next;
            else
                list->head = toDelete->next;

            // Re-link next node
            if (toDelete->next != NULL)
                toDelete->next->prev = toDelete->prev;
            else
                list->tail = toDelete->prev;

            free(toDelete);
            list->size--;
        } else {
            temp = temp->next;
        }
    }
}


void DLL_Print(ListPtr list) {
    if (list == NULL) {
        printf("List is NULL.\n");
        return;
    }

    NodePtr temp = list->head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


