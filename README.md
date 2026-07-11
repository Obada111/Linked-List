# Linked List

Comprehensive C++ implementations of singly linked list (SLL) and doubly linked list (DLL) covering definitions, operations, and algorithms.

Built as a learning resource for data structures and algorithms study.

## Features

### Singly Linked List (SLL)
- Node-based structure with data and next pointer
- Insertion: push_front, push_back, insert_at
- Deletion: pop_front, pop_back, erase_at, remove_first, remove_all
- Search: find, contains
- Utility: reverse, max_value, print, print_reverse
- Head, tail, and size tracking

### Doubly Linked List (DLL) [Template-based]
- Generic type support (template <typename T>)
- Full iterator support (forward, reverse, const)
- Bidirectional node traversal with prev/next pointers
- Insertion: push_front, push_back, insert_at, emplace, insert_before_value, insert_after_value
- Deletion: pop_front, pop_back, erase_at, erase, remove_first, remove_all
- Algorithms: reverse, sort (ascending/descending), remove_duplicates, unique, merge, splice, rotate
- Search: contains, find_first_index, find_last_index, count_occurrences
- Statistics: min, max, sum, average, median
- Utility: is_palindrome, is_sorted, to_vector, get_sublist
- Comparison operators: ==, !=, <, <=, >, >=

## Technologies Used

- C++
- STL
- Object-Oriented Programming
- Templates and Generic Programming

## Installation

### Prerequisites

- C++17 compatible compiler (g++, clang++, MSVC)

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/Obada111/Linked-List.git
   cd Linked-List
   ```

2. Compile:
   ```bash
   g++ -std=c++17 "Linked list (SLL).cpp" -o sll_demo
   g++ -std=c++17 "Doubly Linked List (DLL).cpp" -o dll_demo
   ```

3. Run:
   ```bash
   ./sll_demo
   ./dll_demo
   ```

## Project Structure

```
Linked-List/
  Linked list (SLL).cpp     -- Singly Linked List implementation with demo
  Doubly Linked List (DLL).cpp -- Doubly Linked List template implementation with demo
  .gitignore
  LICENSE
  README.md
```

## Future Improvements

- Add unit tests
- Implement additional algorithms (cycle detection, merge sort)
- Add graphical visualization of linked list operations
- Create separate header files for library use
