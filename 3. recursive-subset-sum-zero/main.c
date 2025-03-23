#include <stdio.h>
#include "recursive_subset_sumzero.h"

int main() {
    int arr[] = {3, -2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    find_all_zero_sum_subsets(arr, n);

    return 0;
}
