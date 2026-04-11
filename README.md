# Linked List in C++

A clean C++ implementation of **Singly Linked List (SLL)** and **Doubly Linked List (DLL)**, built to help you understand linked lists from the ground up with practical operations and clear examples.

---

## Visual Concept — Singly Linked List

![SLL Diagram](sll_diagram.svg)

> The diagram above walks through the five key ideas: node anatomy, how nodes chain together, `push_front`, `remove_first`, and `reverse` — all with the exact pointer logic from the code.

---

## Quick Idea

```
SLL:  [data | next] -> [data | next] -> [data | next] -> NULL

DLL:  NULL <- [prev | data | next] <-> [prev | data | next] <-> [prev | data | next] -> NULL
```

Think of a linked list like a chain of boxes.

- every box is a **node**
- each node stores a value
- arrows connect one node to the next
- the first node is called the **head**
- the last node points to **NULL**

---

## Singly vs Doubly

| Type | Direction | Memory | Best for |
|------|-----------|--------|----------|
| Singly Linked List | one way → | less | simple traversal and learning basics |
| Doubly Linked List | two ways ↔ | more | moving forward and backward easily |

---

## Repository Overview

This repository includes two separate implementations:

- `Linked list (SLL).cpp` — singly linked list
- `Doubly Linked List (DLL).cpp` — doubly linked list

Each file focuses on learning how linked lists work, how pointers are managed, and how common list operations are implemented manually.

---

## Why Linked Lists?

Linked lists are a fundamental data structure because they:

- grow dynamically without pre-allocating memory
- do not require contiguous memory blocks
- support efficient insertions and deletions at both ends
- are excellent for practicing pointer logic and memory management

---

## Features

### Singly Linked List

| Category | Operation | Description |
|----------|-----------|-------------|
| Access | `front()` | Return the first element |
| Access | `back()` | Return the last element |
| Insertion | `push_front(value)` | Insert at the head — O(1) |
| Insertion | `push_back(value)` | Insert at the tail — O(1) |
| Insertion | `insert_at(index, value)` | Insert at a 0-based position — O(n) |
| Deletion | `pop_front()` | Remove the head node — O(1) |
| Deletion | `pop_back()` | Remove the tail node — O(n) |
| Deletion | `erase_at(index)` | Remove node at a position — O(n) |
| Deletion | `remove_first(value)` | Remove first occurrence — O(n) |
| Deletion | `remove_all(value)` | Remove all occurrences, returns count — O(n) |
| Deletion | `clear()` | Remove all nodes — O(n) |
| Search | `contains(value)` | True if value exists — O(n) |
| Algorithm | `reverse()` | Reverse the list in-place — O(n) |
| Algorithm | `max_value()` | Return the maximum value — O(n) |
| Output | `print()` | Print head → tail |
| Output | `print_reverse()` | Print tail → head (recursive) |

### Doubly Linked List

`DoublyLinkedList<T>` is a **generic template class** with STL-style iterators.

**Constructors & Rule-of-Five**
- Default, initializer-list, copy, move constructors and assignment operators

**Iterators**
- `begin()` / `end()` / `cbegin()` / `cend()`
- `rbegin()` / `rend()` / `crbegin()` / `crend()`
- Full bidirectional iterator — works with range-for and `<algorithm>` functions

**Access**
- `front()`, `back()` with const overloads
- `at(index)` with bounds checking
- `operator[]`

**Insertion**
- `push_front` / `push_back` — lvalue and rvalue overloads — O(1)
- `emplace_front` / `emplace_back` — in-place construction
- `insert_at(index, value)` — O(n/2), approaches from nearest end
- `insert_before_value(value, before)` — O(n)
- `insert_after_value(value, after)` — O(n)

**Deletion**
- `pop_front()` / `pop_back()` — O(1)
- `erase_at(index)` — O(n/2)
- `erase(iterator)` — O(1)
- `erase(iterator, iterator)` — range erase
- `remove_first(value)`, `remove_all(value)`, `clear()`

**Algorithms**
- `reverse()` — in-place O(n)
- `sort_ascending()` / `sort_descending()` — O(n log n)
- `remove_duplicates()` — O(n²)
- `unique()` — removes consecutive duplicates, O(n)
- `rotate_left(k)` / `rotate_right(k)`
- `swap_nodes(idx1, idx2)`
- `replace_all(old_val, new_val)`
- `merge(other)` — merges two sorted lists, O(n + m)

**Splice**
- `append(other)` — deep copy append
- `splice(pos, other)` — move all nodes of `other` before `pos`

**Queries**
- `contains(value)`, `find_first_index(value)`, `find_last_index(value)`, `count_occurrences(value)`
- `max_value()`, `min_value()`, `sum()`, `average()`, `median()`
- `is_palindrome()`, `is_sorted_ascending()`, `is_sorted_descending()`
- `get_sublist(start, end)`

**Conversion & Comparison**
- `to_vector()` — copy into `std::vector<T>`
- `==`, `!=`, `<`, `<=`, `>`, `>=` — lexicographic comparison

---

## Time Complexity

| Operation | SLL | DLL |
|-----------|-----|-----|
| `push_front` | O(1) | O(1) |
| `push_back` | O(1) | O(1) |
| `pop_front` | O(1) | O(1) |
| `pop_back` | O(n) | O(1) |
| `insert_at(i)` | O(n) | O(n/2) |
| `erase_at(i)` | O(n) | O(n/2) |
| `contains` / `find` | O(n) | O(n) |
| `reverse` | O(n) | O(n) |
| `sort` | — | O(n log n) |
| `remove_duplicates` | — | O(n²) |

---

## Project Structure

```
Linked-List/
├── Linked list (SLL).cpp          ← Singly Linked List
├── Doubly Linked List (DLL).cpp   ← Doubly Linked List (template, STL-style)
├── sll_diagram.svg                ← Visual guide to SLL concepts
└── README.md
```

---

## How to Run

Compile each file separately. Requires **C++17** (GCC 7+, Clang 5+, or MSVC 2017+).

### Singly Linked List

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o sll "Linked list (SLL).cpp"
./sll
```

### Doubly Linked List

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o dll "Doubly Linked List (DLL).cpp"
./dll
```

---

## Example Usage

### SLL

```cpp
SinglyLinkedList lst;
lst.push_back(10);
lst.push_back(20);
lst.push_front(5);
lst.insert_at(2, 15);   // 5 → 10 → 15 → 20

lst.print();            // [ 5 10 15 20 ]
lst.reverse();
lst.print();            // [ 20 15 10 5 ]
cout << lst.max_value(); // 20
```

### DLL

```cpp
DoublyLinkedList<int> lst;
lst.push_back(10);
lst.push_back(20);
lst.push_front(5);
lst.insert_at(2, 15);

lst.reverse();
lst.sort_ascending();
lst.print_detailed();

// Range-for works out of the box
for (auto& x : lst) x *= 2;
```

---

## What You Learn From This Project

- How nodes are connected using pointers
- How `head` and `tail` pointers are maintained across every operation
- How insertion and deletion handle edge cases (empty list, front, back, middle)
- How traversal works in one direction and two directions
- How to design and use bidirectional iterators
- How move semantics avoid unnecessary copies in modern C++
- How to think about time complexity in linked list operations

---

## Notes

- The **SLL** implementation is the right starting point — simple, clean, integer-only.
- The **DLL** implementation is more advanced and mirrors `std::list` — good for interview practice and data structures study.
- Both files are self-contained with no external dependencies beyond the standard library.

---

## Contributing

You can improve this project by adding more operations, extra examples, or more detailed inline comments.

---

## Acknowledgment

> Special thanks to **Dr. Zain Salah** — the code in this repository is based on material from his lectures and slides.
> He is the doctor who taught us Data Structures and guided us through understanding these concepts from the ground up.
> This project would not exist without his clear teaching and continued support. 🙏
