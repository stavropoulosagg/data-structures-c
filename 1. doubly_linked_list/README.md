# Doubly Linked List (ADT in C)

This project implements an **Abstract Data Type (ADT)** for a **Doubly Linked List** in the C programming language using modular design and proper information hiding.

Each node contains:
- A value (integer)
- A pointer to the **next** node
- A pointer to the **previous** node

The implementation supports sentinel nodes (head and tail) and is designed for maximum flexibility and minimum worst-case time complexity.

## Implemented Operations

- `Create()` – Initialize an empty list
- `Size()` – Return the number of elements
- `IsEmpty()` – Check if the list is empty
- `GetFirst()` – Return the value of the first node
- `GetLast()` – Return the value of the last node
- `GetNode(i)` – Return a pointer to the first node containing value `i`
- `GetPrev(node)` – Return the value of the node before `node`
- `GetNext(node)` – Return the value of the node after `node`
- `AddFirst(i)` – Insert value `i` at the beginning
- `AddLast(i)` – Insert value `i` at the end
- `AddBefore(node, i)` – Insert value `i` before `node`
- `AddAfter(node, i)` – Insert value `i` after `node`
- `Remove(i)` – Remove all nodes containing value `i`
- `Print()` – Print the entire list

## Time Complexity (Worst Case)

| Operation      | Time Complexity |
|----------------|-----------------|
| Create         | O(1)            |
| Size           | O(n) or O(1)\*  |
| IsEmpty        | O(1)            |
| GetFirst/Last  | O(1)            |
| GetNode        | O(n)            |
| AddFirst/Last  | O(1)            |
| AddBefore/After| O(1)            |
| Remove         | O(n)            |
| Print          | O(n)            |

\* If list size is tracked in a field, `Size()` becomes O(1)

## Testing

Unit tests are written using the **Acutest** framework in `test_dllist.c`.

---

Let me know if you'd like a Greek version too, or one for the PDF with complexity analysis!
