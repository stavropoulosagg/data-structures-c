#include <limits.h> // for INT_MIN

int FindMax(NodePtr node) {
    // If the list is empty, return the smallest possible number
    if (node == NULL)
        return INT_MIN;

    
    int maxInRest = FindMax(node->next); // recursive step

    if (node->value > maxInRest)
        return node->value;
    else
        return maxInRest;
}
