# Linked List in C++

> A clean, well-documented C++ implementation of **Singly Linked List (SLL)** and **Doubly Linked List (DLL)** — built from scratch to help you truly understand how linked lists work at the pointer level.

---

## Visual Concept

```
Singly Linked List (SLL)

  head                                  tail
   │                                     │
   ▼                                     ▼
 ┌──────────┐   ┌──────────┐   ┌──────────┐
 │  5 │  ●──┼──▶│ 10 │  ●──┼──▶│ 20 │ NULL│
 └──────────┘   └──────────┘   └──────────┘


Doubly Linked List (DLL)

  head                                          tail
   │                                             │
   ▼                                             ▼
 ┌────────────┐     ┌────────────┐     ┌────────────┐
 │NULL│ 5 │ ●─┼────▶│ ●│ 10 │ ●─┼────▶│ ●│ 20 │NULL│
 └────────────┘ ◀───┼─────────── ◀───┼────────────┘
```

---

## Table of Contents

- [Why Linked Lists?](#why-linked-lists)
- [Singly vs Doubly](#singly-vs-doubly)
- [Repository Overview](#repository-overview)
- [Singly Linked List — Features](#singly-linked-list--features)
- [Doubly Linked List — Features](#doubly-linked-list--features)
- [Time Complexity](#time-complexity)
- [Project Structure](#project-structure)
- [How to Build & Run](#how-to-build--run)
- [Example Usage](#example-usage)
- [What You Learn From This Project](#what-you-learn-from-this-project)
- [Notes](#notes)
- [Acknowledgment](#acknowledgment)

---

## Why Linked Lists?

Arrays allocate one big block of memory up front. Linked lists are different — every node lives wherever the allocator finds space, and a pointer stitches the chain together. That gives you:

- **Dynamic size** — grow and shrink at runtime with no reallocation
- **Non-contiguous memory** — no giant block required
- **O(1) insertion / deletion at the ends** — just rewire a couple of pointers
- **Pointer practice** — nothing sharpens your mental model of memory like building one by hand

---

## Singly vs Doubly

| Feature              | Singly Linked List      | Doubly Linked List              |
|----------------------|-------------------------|---------------------------------|
| Pointer per node     | `next` only             | `prev` + `next`                 |
| Memory per node      | less                    | more (one extra pointer)        |
| Traversal direction  | forward only            | forward **and** backward        |
| `pop_back` cost      | O(n)                    | O(1)                            |
| Best for             | simple chains, stacks   | queues, deques, bidirectional   |
| Iterator type        | forward iterator        | bidirectional iterator          |

---

## Repository Overview

```
Linked-List/
├── Linked list (SLL).cpp          ← Singly Linked List
├── Doubly Linked List (DLL).cpp   ← Doubly Linked List (template, full STL-style)
└── README.md
```

Both files are self-contained — each one compiles and runs on its own.

---

## Singly Linked List — Features

**Access**
- `front()` — first element (throws if empty)
- `back()` — last element (throws if empty)

**Insertion**
- `push_front(value)` — O(1)
- `push_back(value)` — O(1) via tail pointer
- `insert_at(index, value)` — O(n), throws on bad index

**Deletion**
- `pop_front()` — O(1)
- `pop_back()` — O(n)
- `erase_at(index)` — O(n)
- `remove_first(value)` — O(n), returns `bool`
- `remove_all(value)` — O(n), returns count of removed nodes
- `clear()` — O(n)

**Algorithms**
- `reverse()` — in-place, O(n)
- `max_value()` — O(n)

**Search**
- `contains(value)` — O(n)

**Output**
- `print()` — head → tail
- `print_reverse()` — tail → head (recursive)

---

## Doubly Linked List — Features

`DoublyLinkedList<T>` is a **generic template class** modelled after `std::list`.

**Construction**
- Default, initializer-list, copy, move constructors and assignment operators
- Full Rule-of-Five compliance

**Iterators**
- `begin()` / `end()` / `cbegin()` / `cend()`
- `rbegin()` / `rend()` / `crbegin()` / `crend()`
- Works with range-for, `std::sort`, `std::find`, `std::equal`, etc.

**Access**
- `front()`, `back()` — const and non-const overloads
- `at(index)` — bounds-checked
- `operator[]` — unchecked

**Insertion**
- `push_front` / `push_back` (lvalue + rvalue overloads) — O(1)
- `emplace_front` / `emplace_back` — in-place construction
- `insert_at(index, value)` — O(n/2)
- `insert_before_value(value, before)` — O(n)
- `insert_after_value(value, after)` — O(n)

**Deletion**
- `pop_front()` / `pop_back()` — O(1)
- `erase_at(index)` — O(n/2)
- `erase(iterator)` — O(1)
- `erase(iterator, iterator)` — range erase
- `remove_first(value)` — O(n)
- `remove_all(value)` — O(n)
- `clear()` — O(n)

**Algorithms**
- `reverse()` — in-place, O(n)
- `sort_ascending()` / `sort_descending()` — O(n log n)
- `remove_duplicates()` — O(n²)
- `unique()` — removes consecutive duplicates, O(n)
- `rotate_left(k)` / `rotate_right(k)`
- `swap_nodes(idx1, idx2)`
- `replace_all(old_val, new_val)`
- `merge(other)` — merges two sorted lists in O(n+m)

**Splice**
- `append(other)` — deep copy append
- `splice(pos, other)` — move all of other into this before pos
- `splice(pos, other, first, last)` — move a sub-range

**Queries**
- `contains(value)` — O(n)
- `find_first_index(value)` / `find_last_index(value)` — returns 0-based index or -1
- `count_occurrences(value)` — O(n)
- `max_value()` / `min_value()` — O(n)
- `sum()` / `average()` / `median()`
- `is_palindrome()` — O(n)
- `is_sorted_ascending()` / `is_sorted_descending()` — O(n)
- `get_sublist(start, end)` — returns a new list

**Conversion**
- `to_vector()` — copy all elements into a `std::vector<T>`

**Comparison Operators**
- `==`, `!=`, `<`, `<=`, `>`, `>=` — all defined as free functions

---

## Time Complexity

| Operation              | SLL    | DLL    |
|------------------------|--------|--------|
| `push_front`           | O(1)   | O(1)   |
| `push_back`            | O(1)   | O(1)   |
| `pop_front`            | O(1)   | O(1)   |
| `pop_back`             | O(n)   | O(1)   |
| `insert_at(i)`         | O(n)   | O(n/2) |
| `erase_at(i)`          | O(n)   | O(n/2) |
| `find / contains`      | O(n)   | O(n)   |
| `reverse`              | O(n)   | O(n)   |
| `sort`                 | —      | O(n log n) |
| `remove_duplicates`    | —      | O(n²)  |

---

## Project Structure

```
Linked-List/
├── Linked list (SLL).cpp          ← ~200 lines, integer-only, learning-focused
├── Doubly Linked List (DLL).cpp   ← ~500 lines, generic template, STL-style
└── README.md
```

---

## How to Build & Run

You need **g++ with C++17 support** (GCC 7+, Clang 5+, MSVC 2017+).

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
lst.insert_at(2, 15);     // 5 → 10 → 15 → 20

lst.print();              // [ 5 10 15 20 ]
lst.reverse();
lst.print();              // [ 20 15 10 5 ]

lst.remove_first(15);
cout << lst.max_value();  // 20
```

### DLL

```cpp
DoublyLinkedList<int> lst = {3, 1, 4, 1, 5, 9, 2, 6};

lst.sort_ascending();
lst.print_forward();      // [ 1 1 2 3 4 5 6 9 ]
lst.unique();             // remove consecutive duplicates
lst.print_forward();      // [ 1 2 3 4 5 6 9 ]

cout << lst.sum();        // 30
cout << lst.average();    // 4.28571

// Range-for works with all standard algorithms
for (auto& x : lst) x *= 2;

DoublyLinkedList<int> a = {1, 3, 5};
DoublyLinkedList<int> b = {2, 4, 6};
a.merge(b);               // {1, 2, 3, 4, 5, 6}  — b is now empty
```

---

## What You Learn From This Project

Working through both files teaches you:

- How to allocate and de-allocate nodes manually with `new` / `delete`
- How `head` and `tail` pointers are maintained across every operation
- Why insertion at the front is O(1) but insertion in the middle is O(n)
- How `prev` pointers enable O(1) `pop_back` in a DLL vs O(n) in an SLL
- How to write a bidirectional iterator that works with range-for and STL algorithms
- How move semantics (`T&&`) avoid unnecessary copies
- How to implement `splice` and `merge` by rewiring pointers rather than copying data
- How template classes let you write one data structure that works for any type

---

## Notes

- The **SLL** is intentionally simple — it is the right starting point for anyone new to linked lists or pointers.
- The **DLL** is more advanced. It mirrors the interface of `std::list` and is a good reference for interview practice or data-structures coursework.
- Both files are standalone: no external libraries beyond the standard C++ library are required.

---

## Acknowledgment

Special thanks to **Dr. Zain Salah** for the guidance and support throughout this project.

---

## License

This repository is open for personal study, learning, and interview preparation.
Feel free to fork and extend it.
