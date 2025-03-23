#include <stdio.h>
#include <stdbool.h>
#include "recursive_subset_sumzero.h"

#define MAX_SIZE 100  // Max subset size

bool subset_sum_all(int arr[], int n, int index, int sum, bool used,
                    int subset[], int subsetSize) {
    bool found = false;

    // Valid subset found
    if (sum == 0 && used) {
        printf("Subset with sum 0: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        found = true;
    }

    if (index == n) {
        return found;
    }

    // Include current element
    subset[subsetSize] = arr[index];
    if (subset_sum_all(arr, n, index + 1, sum + arr[index], true, subset, subsetSize + 1)) {
        found = true;
    }

    // Exclude current element
    if (subset_sum_all(arr, n, index + 1, sum, used, subset, subsetSize)) {
        found = true;
    }

    return found;
}

void find_all_zero_sum_subsets(int arr[], int n) {
    int subset[MAX_SIZE];
    bool found = subset_sum_all(arr, n, 0, 0, false, subset, 0);

    if (!found) {
        printf("No non-empty subset with sum 0 found.\n");
    }
}
