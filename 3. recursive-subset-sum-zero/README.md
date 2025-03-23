# Recursive Subset Sum to Zero

This project implements a recursive algorithm in C to solve the **subset sum problem**, specifically to determine if there exists a **non-empty subset** of a given integer array that sums to zero.

## Problem Statement

Given an array of integers, find a non-empty subset whose sum is exactly zero, or report that no such subset exists.

The solution uses a recursive function to explore all possible subsets by either including or excluding each element. It stops when a valid zero-sum subset is found.

## Files

- `main.c` – Demonstrates usage of the recursive function with test data.
- `recursive_subset_sumzero.c` – Contains the core recursive logic.
- `recursive_subset_sumzero.h` – Header file with function declarations.

## Example

Given the input array:

[3, 1, -2, 5, -3]

One valid zero-sum subset is:

[3, -2, -1]

Or, in another case:

[1, -1]

## Notes

- The algorithm uses backtracking to explore all subsets.
- The solution stops at the first valid subset (unless modified to find all).
- Time complexity is exponential: O(2^n), where n is the number of elements.
