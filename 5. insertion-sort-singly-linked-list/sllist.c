// sllist.c
#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

List* SLL_Create() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void SLL_AddLast(List* list, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void SLL_Print(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void SLL_Destroy(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

List* SLL_InsertionSort(List* original) {
    List* sorted = SLL_Create();
    Node* current = original->head;

    while (current != NULL) {
        Node* next = current->next;
        Node* sorted_prev = NULL;
        Node* sorted_curr = sorted->head;

        while (sorted_curr != NULL && current->value > sorted_curr->value) {
            sorted_prev = sorted_curr;
            sorted_curr = sorted_curr->next;
        }

        if (sorted_prev == NULL) {
            current->next = sorted->head;
            sorted->head = current;
        } else {
            current->next = sorted_curr;
            sorted_prev->next = current;
        }

        current = next;
    }

    return sorted;
}
