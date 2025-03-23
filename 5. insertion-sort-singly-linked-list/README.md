# Insertion Sort on a Singly Linked List

This project implements the **Insertion Sort** algorithm to sort a **singly linked list** of integers in ascending order using C.

## Problem Statement

The traditional insertion sort algorithm works on arrays by iterating through each element and inserting it into its correct position in the already-sorted left portion. This project adapts that logic for a **singly linked list**.

The approach involves:
- Iterating over each node in the original list
- Creating a new sorted list by inserting each node into its proper position
- Re-linking nodes without creating new memory (in-place node movement)

## Files

- `sllist.h` – Type definitions and function declarations for singly linked list
- `sllist.c` – Core implementation including the insertion sort logic
- `main_sllist.c` – Demonstration program
- `test_sllist.c` – Unit tests using Acutest
- `acutest.h` – Lightweight test framework header

## Key Functions

- `SLL_InsertSorted()` – Inserts a node into the correct position in a sorted list
- `SLL_Sort()` – Performs the full insertion sort algorithm
- `SLL_AddLast()`, `SLL_Print()`, `SLL_Destroy()` – Utility operations

## Example

Before sorting:

12 → 5 → 8 → 1 → 9

After sorting:

1 → 5 → 8 → 9 → 12

## Compilation & Usage

To compile and run the demo:

gcc main_sllist.c sllist.c -o sort_list
./sort_list

To run the unit tests:

gcc test_sllist.c sllist.c -o test_sllist
./test_sllist
