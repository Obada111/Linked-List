# Linked List in C++

![Linked List Banner](assets/linked-list-banner.png)

A clean C++ implementation of **Singly Linked List (SLL)** and **Doubly Linked List (DLL)**, built to help you understand linked lists from the ground up with practical operations and clear examples.

## Visual Concept

![Linked List Concept](assets/linked_list_concept.png)

The image above shows the core idea in a very simple way:

* in a **singly linked list**, each node keeps `data` and a pointer to the `next` node
* in a **doubly linked list**, each node keeps `prev`, `data`, and `next`

### Quick idea

```text
SLL:  [data | next] -> [data | next] -> [data | next] -> NULL
DLL:  NULL <- [prev | data | next] <-> [prev | data | next] <-> [prev | data | next] -> NULL
```

## Concept in one minute

Think of a linked list like a chain of boxes.

* every box is a **node**
* each node stores a value
* arrows connect one node to another
* the first node is called the **head**
* the last node points to **NULL**

### Singly vs Doubly

| Type               | Direction | Memory | Best for                             |
| ------------------ | --------- | ------ | ------------------------------------ |
| Singly Linked List | one way   | less   | simple traversal and learning basics |
| Doubly Linked List | two ways  | more   | moving forward and backward easily   |

## Repository Overview

## Repository Overview

This repository includes two separate implementations:

* `Linked list (SLL).cpp` — singly linked list
* `Doubly Linked List (DLL).cpp` — doubly linked list

Each file focuses on learning how linked lists work, how pointers are managed, and how common list operations are implemented manually.

## Why Linked Lists?

Linked lists are a fundamental data structure because they:

* grow dynamically
* do not require contiguous memory
* support efficient insertions and deletions
* are excellent for practicing pointer logic and memory management

## Features

### Singly Linked List

* insert at front and back
* insert at a specific position
* delete from front and back
* remove first occurrence
* remove all occurrences
* search for values
* reverse the list
* print normally and in reverse
* find the maximum value
* clear the whole list

### Doubly Linked List

* forward and backward traversal
* insert and delete from both ends
* erase by position
* remove duplicates
* unique values handling
* append and splice
* merge lists
* rotate left
* sort ascending and descending
* iterator support
* comparison operators

## Project Structure

```text
Linked-List/
├── Linked list (SLL).cpp
├── Doubly Linked List (DLL).cpp
├── assets/
│   └── linked-list-banner.png
└── README.md
```

## Screenshot / Photo

Add your project image inside the `assets` folder and keep the same name below:

```markdown
![Linked List Banner](assets/linked-list-banner.png)
```

You can replace it later with any image you like, such as:

* a diagram of linked lists
* a screenshot of your code
* a clean project cover image

## How to Run

Compile each file separately.

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

## Example Usage

### SLL

```cpp
SinglyLinkedList lst;
lst.push_back(10);
lst.push_back(20);
lst.push_front(5);
lst.insert_at(2, 15);

lst.print();
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
lst.print();
```

## What You Learn From This Project

* how nodes are connected using pointers
* how head and tail pointers are maintained
* how insertion and deletion work in different edge cases
* how to traverse in one direction and two directions
* how to design and use iterators
* how to think about time complexity in list operations

## Notes

* The SLL implementation is great for learning the basics.
* The DLL implementation is more advanced and includes extra utility operations.
* This project is useful for beginners, interview practice, and data structures study.

## Contributing

You can improve this project by adding more operations, cleaner documentation, or extra examples.

## Acknowledgment

Special thanks to **Dr. Zain Salah** for the guidance and support.

## License

You can add a license here if you want to make the repository reusable for others.
