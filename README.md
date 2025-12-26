# 🔗 Linked List Complete Guide - Singly & Doubly Linked Lists

[![C++](https://img.shields.io/badge/C%2B%2B-17%2B-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)]()
[![Data Structures](https://img.shields.io/badge/Algorithms-SLL%20%7C%20DLL-orange.svg)]()

> 🎯 **The Most Complete Linked List Implementation with Visual Explanations, Real Examples, and Everything You Need to Learn**
>
> Master **Singly Linked Lists (SLL)** and **Doubly Linked Lists (DLL)** with detailed diagrams, code, and explanations

---

## 📚 Table of Contents

- [Overview](#-overview)
- [Singly Linked List (SLL)](#-singly-linked-list-sll)
- [Doubly Linked List (DLL)](#-doubly-linked-list-dll)
- [Complete Comparison](#-complete-comparison)
- [All Operations with Code](#-all-operations-with-code)
- [Real-World Use Cases](#-real-world-use-cases)
- [Interview Questions](#-interview-questions)
- [Video Tutorials](#-video-tutorials)
- [Installation & Usage](#-installation--usage)
- [Resources](#-resources)

---

## 🎯 Overview

### The Problem with Arrays

Arrays store data in **contiguous memory**, which creates problems:

```
❌ ARRAY PROBLEMS:

Array: [5] [10] [15] [20] [25]
Index:  0   1    2    3    4

Insert 7 at index 1:
- Shift all elements: [5] [7] [10] [15] [20] [25]
- Time: O(n) - Very Slow!

Delete element at index 1:
- Shift all elements back
- Time: O(n) - Very Slow!

Memory: Contiguous (fixed), Wasteful if not full
```

### The Solution: Linked Lists

Linked lists use **pointers to connect nodes**, solving array problems:

```
✅ LINKED LIST BENEFITS:

Dynamic nodes connected by pointers
Insert 7 between 5 and 10:
- Just change pointers
- Time: O(1) - Very Fast!

Delete element:
- Just reroute pointers
- Time: O(1) - Very Fast!

Memory: Non-contiguous, uses exactly what's needed
```

---

## 🔗 Singly Linked List (SLL)

### What is Singly Linked List?

A **Singly Linked List** is a linear data structure where:
- Each node contains **data** and **one pointer** to the next node
- You can only traverse in **one direction** (forward)
- Like a **train with cars** connected forward only

### Visual Structure

```
═══════════════════════════════════════════════════════
                 SINGLY LINKED LIST
═══════════════════════════════════════════════════════

            HEAD
             ↓
        ┌─────────┐    ┌─────────┐    ┌─────────┐
        │ Data: 5 │    │Data: 10 │    │Data: 15 │
        │ Next: ──┼──→ │ Next: ──┼──→ │ Next: NULL
        └─────────┘    └─────────┘    └─────────┘
         Node 1         Node 2         Node 3

Visual: 5 → 10 → 15 → NULL

Each Node contains:
┌──────────────┐
│ Data  │ Next │  (2 parts)
└──────────────┘

═══════════════════════════════════════════════════════
```

### SLL Node Structure (Code)

```cpp
template <typename T>
struct Node {
    T data;           // Store data
    Node* next;       // Pointer to next node
    
    Node(T value) : data(value), next(nullptr) {}
};
```

### SLL Class Structure

```cpp
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    
public:
    SinglyLinkedList() : head(nullptr) {}
    
    // Operations
    void insert_at_head(T value);
    void insert_at_tail(T value);
    void insert_at_position(T value, int position);
    void delete_node(T value);
    void display();
    bool search(T value);
    int length();
};
```

---

## 📊 SLL Operations with Detailed Explanations

### 1️⃣ INSERT AT HEAD (Beginning)

**Visual Step-by-Step:**

```
BEFORE:
    HEAD
     ↓
   [5] → [10] → [15] → NULL


Step 1: Create new node
         ┌─────┐
         │ 2   │
         │NULL │
         └─────┘

Step 2: Point new node to current head
         ┌─────┐
         │ 2   │──┐
         │  ──→│──┤
         └─────┘  │
                  ↓
                [5] → [10] → [15] → NULL

Step 3: Move HEAD to new node
    HEAD
     ↓
   [2] → [5] → [10] → [15] → NULL

RESULT: 2 → 5 → 10 → 15 → NULL ✓
```

**Code:**
```cpp
void insert_at_head(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;          // Point to current head
    head = newNode;                 // New node becomes head
}
```

**Time Complexity:** O(1) - Constant time ⚡ FASTEST!
**Space Complexity:** O(1)

---

### 2️⃣ INSERT AT TAIL (End)

**Visual Step-by-Step:**

```
BEFORE:
    HEAD
     ↓
   [5] → [10] → [15] → NULL

Step 1: Create new node
         ┌─────┐
         │ 20  │
         │NULL │
         └─────┘

Step 2: Traverse to last node
    HEAD
     ↓
   [5] → [10] → [15] → NULL
                  ↑ Last node

Step 3: Connect last node to new node
   [5] → [10] → [15] → [20] → NULL
                           ↑
                       New tail

RESULT: 5 → 10 → 15 → 20 → NULL ✓
```

**Code:**
```cpp
void insert_at_tail(T value) {
    Node<T>* newNode = new Node<T>(value);
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;  // Move to next
    }
    current->next = newNode;      // Connect to new node
}
```

**Time Complexity:** O(n) - Must traverse entire list
**Space Complexity:** O(1)

---

### 3️⃣ INSERT AT POSITION (Middle)

**Visual Step-by-Step:**

```
BEFORE (Insert 7 at position 1):
    HEAD
     ↓
   [5] → [10] → [15] → NULL
   pos 0  pos 1  pos 2

Step 1: Find position
   [5] → [10] → [15] → NULL
   ↑ Current position (pos 0)

Step 2: Create new node and connect
   ┌─────┐
   │ 7   │
   └─────┘

   [5] → [7] → [10] → [15] → NULL
             ↑
         Newly inserted

RESULT: 5 → 7 → 10 → 15 → NULL ✓
```

**Code:**
```cpp
void insert_at_position(T value, int pos) {
    if (pos == 0) {
        insert_at_head(value);
        return;
    }
    
    Node<T>* current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; i++) {
        current = current->next;
    }
    
    if (current == nullptr) return;
    
    Node<T>* newNode = new Node<T>(value);
    newNode->next = current->next;
    current->next = newNode;
}
```

**Time Complexity:** O(n) - Must traverse to position
**Space Complexity:** O(1)

---

### 4️⃣ DELETE NODE

**Visual Step-by-Step:**

```
BEFORE (Delete node with value 10):
    HEAD
     ↓
   [5] → [10] → [15] → NULL
         ↑ Delete this

Step 1: Find node before deletion point
   [5] → [10] → [15] → NULL
   ↑ This node

Step 2: Store next pointer of node to delete
   [10]'s next = [15]

Step 3: Reroute pointer
   [5] → [15] → NULL
            ↑ Skipped [10]

Step 4: Delete node
   [5] → [15] → NULL
   
RESULT: 5 → 15 → NULL ✓ Node 10 removed!
```

**Code:**
```cpp
void delete_node(T value) {
    if (head == nullptr) return;
    
    // If head node
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    // If middle/end node
    Node<T>* current = head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}
```

**Time Complexity:** O(n) - Must find node first
**Space Complexity:** O(1)

---

### 5️⃣ SEARCH / FIND

**Visual Step-by-Step:**

```
SEARCH for value 15:

    HEAD
     ↓
   [5] → [10] → [15] → NULL
   ↓       ↓       ↓
   15?    15?    15? → YES! Found at position 2
   No     No
```

**Code:**
```cpp
bool search(T value) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;  // Found!
        }
        current = current->next;
    }
    return false;  // Not found
}

int search_position(T value) {
    Node<T>* current = head;
    int pos = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;  // Not found
}
```

**Time Complexity:** O(n) - May search entire list
**Space Complexity:** O(1)

---

### 6️⃣ DISPLAY / TRAVERSE

**Visual:**

```
TRAVERSE from HEAD to NULL:

    HEAD
     ↓
   [5] → [10] → [15] → NULL
   ↓      ↓      ↓      ↓
   5      10     15    STOP

Output: 5 → 10 → 15 → NULL
```

**Code:**
```cpp
void display() {
    Node<T>* current = head;
    cout << "List: ";
    while (current != nullptr) {
        cout << current->data << " → ";
        current = current->next;
    }
    cout << "NULL\n";
}

int length() {
    int count = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
```

**Time Complexity:** O(n) - Visit each node
**Space Complexity:** O(1)

---

### 7️⃣ REVERSE LINKED LIST

**Visual Step-by-Step:**

```
ORIGINAL:
   HEAD
    ↓
   [5] → [10] → [15] → NULL

Step 1: Reverse pointer of first node
   NULL ← [5]  [10] → [15] → NULL

Step 2: Reverse pointer of second node
   NULL ← [5] ← [10]  [15] → NULL

Step 3: Reverse pointer of third node
   NULL ← [5] ← [10] ← [15]

Step 4: Update HEAD to new start
                        HEAD
                         ↓
   NULL ← [5] ← [10] ← [15]

RESULT: 15 → 10 → 5 → NULL ✓
```

**Code:**
```cpp
void reverse() {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;        // Save next
        current->next = prev;        // Reverse pointer
        prev = current;              // Move prev forward
        current = next;              // Move current forward
    }
    
    head = prev;  // Update head
}
```

**Time Complexity:** O(n) - Visit each node once
**Space Complexity:** O(1) - No extra space

---

## SLL Time Complexity Summary

```
╔════════════════════════════════════════════╗
║  SINGLY LINKED LIST - Time Complexity      ║
╠════════════════════════════════════════════╣
║ Operation           │ Time      │ Notes    ║
╠─────────────────────┼───────────┼──────────╣
║ Insert at Head      │ O(1) ⚡   │ FASTEST  ║
║ Insert at Tail      │ O(n)      │          ║
║ Insert at Position  │ O(n)      │          ║
║ Delete from Head    │ O(1) ⚡   │ FASTEST  ║
║ Delete from Middle  │ O(n)      │          ║
║ Search              │ O(n)      │          ║
║ Access by Index     │ O(n)      │          ║
║ Display All         │ O(n)      │          ║
║ Reverse             │ O(n)      │          ║
╚════════════════════════════════════════════╝
```

---

## 🔗 Doubly Linked List (DLL)

### What is Doubly Linked List?

A **Doubly Linked List** is a linear data structure where:
- Each node contains **data**, **prev pointer**, and **next pointer**
- You can traverse in **both directions** (forward AND backward)
- Like a **train where you can move couplers both ways**

### Visual Structure

```
═══════════════════════════════════════════════════════
               DOUBLY LINKED LIST
═══════════════════════════════════════════════════════

Bidirectional Navigation:

    HEAD                                          TAIL
     ↓                                             ↓
┌─────────────┐  ┌──────────────┐  ┌──────────────┐
│ NULL ← ●    │  │ ● ← Data: 10 │  │ ● ← NULL     │
│ Data: 5     │  │ Data pointer │  │ Data: 15     │
│ ● →  ────┼──→ │ ● →  ───────┼──→ │ ● → NULL     │
└─────────────┘  └──────────────┘  └──────────────┘
 Node 1           Node 2            Node 3

FORWARD: 5 → 10 → 15 → NULL
BACKWARD: 15 ← 10 ← 5 ← NULL

Each Node contains:
┌─────────────────────┐
│ Prev | Data | Next  │  (3 parts)
└─────────────────────┘

═══════════════════════════════════════════════════════
```

### DLL Node Structure (Code)

```cpp
template <typename T>
struct Node {
    T data;
    Node* prev;        // Pointer to PREVIOUS node (NEW!)
    Node* next;        // Pointer to NEXT node
    
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};
```

### DLL Class Structure

```cpp
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;     // Tail pointer (NEW!)
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    // Operations
    void insert_at_head(T value);
    void insert_at_tail(T value);
    void delete_from_head();
    void delete_from_tail();
    void display_forward();
    void display_backward();
    bool search(T value);
};
```

---

## 📊 DLL Operations with Detailed Explanations

### 1️⃣ INSERT AT HEAD (DLL)

**Visual Step-by-Step:**

```
BEFORE:
    HEAD
     ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL

Step 1: Create new node
       ┌──────────┐
       │NULL │2│X │
       └──────────┘

Step 2: Connect to current head
       ┌──────────┐
       │NULL │2│●│──┐
       └──────────┘  │
                     ↓
                  NULL ← [5] ↔ [10] ↔ [15] → NULL

Step 3: Update head's prev
                ↑
       NULL ← [2] ↔ [5] ↔ [10] ↔ [15] → NULL

Step 4: Move HEAD
    HEAD
     ↓
   NULL ← [2] ↔ [5] ↔ [10] ↔ [15] → NULL

RESULT: 2 ↔ 5 ↔ 10 ↔ 15 ✓
```

**Code:**
```cpp
void insert_at_head(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    
    if (head != nullptr) {
        head->prev = newNode;
    }
    
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}
```

**Time Complexity:** O(1) ⚡ - Constant time
**Space Complexity:** O(1)

---

### 2️⃣ INSERT AT TAIL (DLL)

**Visual Step-by-Step:**

```
BEFORE:
                                    TAIL
                                     ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL

Step 1: Create new node
         ┌──────────┐
         │X│20│NULL │
         └──────────┘

Step 2: Connect old tail to new node
         ↑
   NULL ← [5] ↔ [10] ↔ [15] ↔ [20] → NULL

Step 3: Update new node's prev
         ↑
   NULL ← [5] ↔ [10] ↔ [15] ↔ [20] → NULL

Step 4: Move TAIL
                                        TAIL
                                         ↓
   NULL ← [5] ↔ [10] ↔ [15] ↔ [20] → NULL

RESULT: 5 ↔ 10 ↔ 15 ↔ 20 ✓
```

**Code:**
```cpp
void insert_at_tail(T value) {
    Node<T>* newNode = new Node<T>(value);
    
    if (tail == nullptr) {
        head = tail = newNode;
        return;
    }
    
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}
```

**Time Complexity:** O(1) ⚡ - Constant time (BIG advantage over SLL!)
**Space Complexity:** O(1)

---

### 3️⃣ DELETE FROM HEAD (DLL)

**Visual Step-by-Step:**

```
BEFORE:
    HEAD
     ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL

Step 1: Save old head
    HEAD
     ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL
         ↑ To delete

Step 2: Move head to next
              HEAD
               ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL

Step 3: Set new head's prev to NULL
    HEAD
     ↓
   NULL ← [10] ↔ [15] → NULL

Step 4: Delete old node
   [5] node deleted

RESULT: 10 ↔ 15 → NULL ✓
```

**Code:**
```cpp
void delete_from_head() {
    if (head == nullptr) return;
    
    Node<T>* temp = head;
    head = head->next;
    
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    
    delete temp;
}
```

**Time Complexity:** O(1) ⚡ - Constant time
**Space Complexity:** O(1)

---

### 4️⃣ DELETE FROM TAIL (DLL)

**Visual Step-by-Step:**

```
BEFORE:
                                    TAIL
                                     ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL

Step 1: Save old tail
                                    TAIL
                                     ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL
                          ↑ To delete

Step 2: Move tail to prev
                                TAIL
                                 ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL

Step 3: Set new tail's next to NULL
                                TAIL
                                 ↓
   NULL ← [5] ↔ [10] → NULL

Step 4: Delete old node
   [15] node deleted

RESULT: 5 ↔ 10 → NULL ✓
```

**Code:**
```cpp
void delete_from_tail() {
    if (tail == nullptr) return;
    
    Node<T>* temp = tail;
    tail = tail->prev;
    
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    
    delete temp;
}
```

**Time Complexity:** O(1) ⚡ - Constant time
**Space Complexity:** O(1)

---

### 5️⃣ BIDIRECTIONAL TRAVERSAL (DLL)

**Forward Traversal:**

```
    HEAD
     ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL

Start at HEAD, follow next pointers:
5 → 10 → 15 → NULL

Output: 5 → 10 → 15 → NULL
```

**Backward Traversal:**

```
                                    TAIL
                                     ↓
   NULL ← [5] ↔ [10] ↔ [15] → NULL

Start at TAIL, follow prev pointers:
15 → 10 → 5 → NULL

Output: 15 → 10 → 5 → NULL
```

**Code:**
```cpp
void display_forward() {
    Node<T>* current = head;
    cout << "Forward: ";
    while (current != nullptr) {
        cout << current->data << " → ";
        current = current->next;
    }
    cout << "NULL\n";
}

void display_backward() {
    Node<T>* current = tail;
    cout << "Backward: ";
    while (current != nullptr) {
        cout << current->data << " → ";
        current = current->prev;
    }
    cout << "NULL\n";
}
```

**Time Complexity:** O(n) - Visit each node
**Space Complexity:** O(1)

---

## DLL Time Complexity Summary

```
╔════════════════════════════════════════════╗
║ DOUBLY LINKED LIST - Time Complexity       ║
╠════════════════════════════════════════════╣
║ Operation           │ Time      │ Notes    ║
╠─────────────────────┼───────────┼──────────╣
║ Insert at Head      │ O(1) ⚡   │ FASTEST  ║
║ Insert at Tail      │ O(1) ⚡   │ FASTEST  ║
║ Delete from Head    │ O(1) ⚡   │ FASTEST  ║
║ Delete from Tail    │ O(1) ⚡   │ FASTEST  ║
║ Search              │ O(n)      │          ║
║ Access by Index     │ O(n)      │          ║
║ Traverse Forward    │ O(n)      │          ║
║ Traverse Backward   │ O(n) ✓    │ NEW!     ║
╚════════════════════════════════════════════╝
```

---

## 📊 Complete Comparison: SLL vs DLL

```
╔════════════════════════════════════════════════════════════════════╗
║             SINGLY LINKED LIST vs DOUBLY LINKED LIST               ║
╠════════════════════════════════════════════════════════════════════╣
║ Feature              │ SLL               │ DLL                    ║
╠──────────────────────┼───────────────────┼────────────────────────╣
║ Node Structure       │ Data | Next       │ Prev | Data | Next     ║
║ Pointers per Node    │ 1                 │ 2                      ║
║ Memory per Node      │ Less              │ More (+1 pointer)      ║
║ Traversal Direction  │ Forward only      │ Both directions ✓      ║
║ Insert at Head       │ O(1)              │ O(1)                   ║
║ Insert at Tail       │ O(n)              │ O(1) ✓ BETTER          ║
║ Delete from Head     │ O(1)              │ O(1)                   ║
║ Delete from Tail     │ O(n)              │ O(1) ✓ BETTER          ║
║ Backward Traversal   │ ✗ Not possible    │ ✓ Possible             ║
║ Code Complexity      │ Simpler           │ More complex           ║
║ Best for Stack       │ Good              │ Good                   ║
║ Best for Queue       │ Good              │ Better ✓               ║
║ Best for Deque       │ ✗ Not ideal       │ ✓ Perfect              ║
║ Best for LRU Cache   │ ✗ Not ideal       │ ✓ Perfect              ║
║ Cache Efficiency     │ Better            │ Slightly less          ║
║ CPU Cache Misses     │ Fewer             │ More pointers to load  ║
╚════════════════════════════════════════════════════════════════════╝
```

---

## 💡 Real-World Use Cases

### Singly Linked List (SLL)

```
1. 🔄 UNDO/REDO Stack (Undo Only)
   ┌──────────────┐   ┌──────────────┐   ┌──────────────┐
   │ Action 1     │→  │ Action 2     │→  │ Action 3     │
   └──────────────┘   └──────────────┘   └──────────────┘
   Type text        Delete 5 chars      Format text
   
   Can only undo: 3 → 2 → 1 (go backward manually)

2. 📚 Polynomial Representation
   5x² + 3x + 2
   ┌──────────────┐   ┌──────────────┐   ┌──────────────┐
   │ Coef: 5      │→  │ Coef: 3      │→  │ Coef: 2      │
   │ Power: 2     │   │ Power: 1     │   │ Power: 0     │
   └──────────────┘   └──────────────┘   └──────────────┘

3. 🏪 Shopping Cart (Simple List)
   Item 1 → Item 2 → Item 3 → Checkout

4. 📝 To-Do List (Sequential Tasks)
   Task 1 → Task 2 → Task 3 → Done
```

### Doubly Linked List (DLL)

```
1. 🌐 BROWSER NAVIGATION (Back/Forward)
   ┌──────────────┐
   │ Google Page  │ ← You are here
   └──────────────┘
   ↑                ↓
┌──────────────┐ ┌──────────────┐
│ Facebook     │ │ GitHub       │
│[BACK]        │ │ [FORWARD]    │
└──────────────┘ └──────────────┘
↑                                ↓
Can go BOTH ways: Back ↔ Forward

2. 🎵 MUSIC PLAYLIST (Previous/Next)
   ┌──────────────────────────────┐
   │ Now Playing: Song 2           │
   │ ⏮ PREV    0:45/3:00   NEXT ⏭ │
   └──────────────────────────────┘
   ↑                              ↓
┌──────────────┐             ┌──────────────┐
│ Song 1       │             │ Song 3       │
│ Previous     │             │ Next         │
└──────────────┘             └──────────────┘

3. 💾 LRU CACHE (Least Recently Used)
   Most Recently Used → ... → Least Recently Used
   ┌──────┐   ┌──────┐   ┌──────┐   ┌──────┐
   │Page1 │↔ │Page2 │↔ │Page3 │↔ │Page4 │
   └──────┘   └──────┘   └──────┘   └──────┘
   REMOVE THIS FIRST when cache is full
   
   Access Page3? Move to front:
   ┌──────┐   ┌──────┐   ┌──────┐   ┌──────┐
   │Page3 │↔ │Page1 │↔ │Page2 │↔ │Page4 │
   └──────┘   └──────┘   └──────┘   └──────┘

4. 🚂 RAILWAY SYSTEM (Bidirectional)
   [Engine] ↔ [Car1] ↔ [Car2] ↔ [Car3]
   
   Can couple/uncouple from BOTH directions
   Can move engines in both directions

5. 📋 TEXT EDITOR (Undo/Redo Both Ways)
   Can undo → then redo
   ┌──────────────┐   ┌──────────────┐   ┌──────────────┐
   │ Version 1    │↔ │ Version 2    │↔ │ Version 3    │
   │ (Undo)       │   │ (Current)    │   │ (Redo)       │
   └──────────────┘   └──────────────┘   └──────────────┘

6. 📱 PHOTO GALLERY (Previous/Next)
   Can swipe ← LEFT and RIGHT →
   Like browser navigation but for photos
```

---

## 🎓 Interview Questions

### Easy Level

**1. Reverse a Singly Linked List**
```
Input:  1 → 2 → 3 → NULL
Output: 3 → 2 → 1 → NULL

Solution: Reverse all pointers
Time: O(n), Space: O(1)
```

**2. Find Middle of Linked List**
```
Input:  1 → 2 → 3 → 4 → 5 → NULL
Output: 3 (middle node)

Solution: Slow & Fast pointer
- Slow moves 1 step
- Fast moves 2 steps
- When Fast reaches end, Slow is at middle
Time: O(n), Space: O(1)
```

**3. Detect Cycle in Linked List**
```
Input:  1 → 2 → 3 → 4 ↺ (points back to 2)
Output: true (cycle detected)

Solution: Floyd's Cycle Detection (Tortoise & Hare)
Time: O(n), Space: O(1)
```

### Medium Level

**4. Merge Two Sorted Linked Lists**
```
Input:  1 → 3 → 5 → NULL
        2 → 4 → 6 → NULL
Output: 1 → 2 → 3 → 4 → 5 → 6 → NULL

Solution: Compare nodes, merge
Time: O(n+m), Space: O(1)
```

**5. Remove Nth Node From End**
```
Input:  1 → 2 → 3 → 4 → 5 → NULL, N=2
Output: 1 → 2 → 3 → 5 → NULL (removed 4)

Solution: Two pointers, gap of N
Time: O(n), Space: O(1)
```

**6. LRU Cache Implementation**
```
Cache with fixed size, evict least recently used
Solution: DLL + HashMap
Get: O(1), Put: O(1)
```

### Hard Level

**7. Copy List with Random Pointer**
```
Complex linked list with random pointers
Solution: Hash Map or Node Connection trick
Time: O(n), Space: O(n)
```

**8. Reverse Nodes in K-Group**
```
Input:  1 → 2 → 3 → 4 → 5 → NULL, K=2
Output: 2 → 1 → 4 → 3 → 5 → NULL

Solution: Group reversal
Time: O(n), Space: O(1)
```

**9. Flatten Multilevel Doubly Linked List**
```
Complex structure with child pointers
Time: O(n), Space: O(1) or O(h)
```

---

## 📺 Video Tutorials

### YouTube Links for Learning

| Topic | Link | Duration |
|-------|------|----------|
| **SLL Basics** | [Watch](https://www.youtube.com/results?search_query=singly+linked+list+tutorial) | 15-20 min |
| **DLL Tutorial** | [Watch](https://www.youtube.com/results?search_query=doubly+linked+list+tutorial) | 15-20 min |
| **Linked List Problems** | [Watch](https://www.youtube.com/results?search_query=linked+list+interview+questions) | 30-40 min |
| **Complete DSA Course** | [Watch](https://www.youtube.com/results?search_query=data+structures+and+algorithms+course) | 10-20 hours |

### Interactive Learning Platforms

| Platform | URL | Features |
|----------|-----|----------|
| **VisuAlgo** | https://visualgo.net/en/list | Step-by-step animations |
| **GeeksforGeeks** | https://www.geeksforgeeks.org/data-structures/linked-list/ | Detailed explanations + code |
| **LeetCode** | https://leetcode.com/tag/linked-list/ | Practice problems |
| **HackerRank** | https://www.hackerrank.com/domains/data-structures | Coding challenges |
| **Codeforces** | https://codeforces.com/ | Competitive programming |

### Recommended Videos to Watch

```
📺 ESSENTIAL VIEWING LIST:

1. Linked List Fundamentals (10 min)
   - What is a node?
   - How pointers work
   - Memory allocation
   - Why use linked lists?

2. Singly Linked List Operations (25 min)
   - Insert at head O(1)
   - Insert at tail O(n)
   - Insert at position O(n)
   - Delete operations O(n)
   - Search O(n)
   - Display/Traversal O(n)

3. Doubly Linked List Operations (25 min)
   - Insert at head O(1)
   - Insert at tail O(1) ← Better!
   - Delete from head O(1) ← Better!
   - Delete from tail O(1) ← Better!
   - Bidirectional traversal O(n)
   - Comparison with SLL

4. Classic Problems (40 min)
   - Reverse linked list
   - Detect cycle (Floyd's algorithm)
   - Find middle node
   - Merge sorted lists
   - Remove Nth node from end

5. Interview Preparation (50 min)
   - LeetCode easy problems
   - Medium difficulty problems
   - Hard problems with explanations
   - Common mistakes to avoid
```

---

## 💻 Installation & Usage

### Clone Repository

```bash
git clone https://github.com/Obada111/linked-list.git
cd linked-list
```

### Compile SLL

```bash
g++ -std=c++17 srcSinglyLinkedList.cpp -o sll
./sll
```

### Compile DLL

```bash
g++ -std=c++17 srcDoublyLinkedList.cpp -o dll
./dll
```

### Compile All

```bash
g++ -std=c++17 srcSinglyLinkedList.cpp srcDoublyLinkedList.cpp srcmain.cpp -o run
./run
```

---

## 💡 Complete Code Examples

### SLL Example Program

```cpp
#include "srcSinglyLinkedList.cpp"

int main() {
    SinglyLinkedList<int> list;
    
    // Insert operations
    cout << "=== SINGLY LINKED LIST DEMO ===\n\n";
    
    // Insert at head
    list.insert_at_head(10);
    list.insert_at_head(5);
    cout << "After inserting 10, 5 at head:\n";
    list.display();  // 5 → 10 → NULL
    
    // Insert at tail
    list.insert_at_tail(15);
    list.insert_at_tail(20);
    cout << "\nAfter inserting 15, 20 at tail:\n";
    list.display();  // 5 → 10 → 15 → 20 → NULL
    
    // Insert at position
    list.insert_at_position(7, 1);
    cout << "\nAfter inserting 7 at position 1:\n";
    list.display();  // 5 → 7 → 10 → 15 → 20 → NULL
    
    // Search
    cout << "\nSearch for 10: " << (list.search(10) ? "Found" : "Not Found") << "\n";
    cout << "Search for 100: " << (list.search(100) ? "Found" : "Not Found") << "\n";
    
    // Length
    cout << "\nLength: " << list.length() << "\n";
    
    // Delete
    list.delete_node(7);
    cout << "\nAfter deleting 7:\n";
    list.display();  // 5 → 10 → 15 → 20 → NULL
    
    // Reverse
    list.reverse();
    cout << "\nAfter reversing:\n";
    list.display();  // 20 → 15 → 10 → 5 → NULL
    
    return 0;
}
```

### DLL Example Program

```cpp
#include "srcDoublyLinkedList.cpp"

int main() {
    DoublyLinkedList<int> list;
    
    cout << "=== DOUBLY LINKED LIST DEMO ===\n\n";
    
    // Insert at head and tail (both O(1)!)
    list.insert_at_head(10);
    list.insert_at_tail(20);
    list.insert_at_tail(30);
    list.insert_at_head(5);
    
    cout << "After insertions:\n";
    list.display_forward();   // 5 → 10 → 20 → 30 → NULL
    list.display_backward();  // 30 → 20 → 10 → 5 → NULL
    
    // Search
    cout << "\nSearch for 20: " << (list.search(20) ? "Found" : "Not Found") << "\n";
    
    // Delete from both ends (O(1)!)
    list.delete_from_head();
    list.delete_from_tail();
    
    cout << "\nAfter delete from head and tail:\n";
    list.display_forward();   // 10 → 20 → NULL
    list.display_backward();  // 20 → 10 → NULL
    
    return 0;
}
```

---

## 📊 Complexity Cheat Sheet

```
╔════════════════════════════════════════════════════════╗
║          LINKED LIST OPERATIONS - QUICK REFERENCE      ║
╠════════════════════════════════════════════════════════╣

                    SLL        │    DLL
                ────────────────┼───────────────
Insert Head      O(1) ⚡       │    O(1) ⚡
Insert Tail      O(n)          │    O(1) ⚡⚡ BETTER
Delete Head      O(1) ⚡       │    O(1) ⚡
Delete Tail      O(n)          │    O(1) ⚡⚡ BETTER
Search           O(n)          │    O(n)
Access Index     O(n)          │    O(n)
Traverse Fwd     O(n)          │    O(n)
Traverse Bwd     IMPOSSIBLE    │    O(n) ✓ NEW!

╠════════════════════════════════════════════════════════╣
║ MEMORY COMPARISON                                      ║
╠════════════════════════════════════════════════════════╣

SLL (3 nodes):
[Data|Next] → [Data|Next] → [Data|NULL]
  8 bytes      8 bytes      8 bytes
  Total: 24 bytes

DLL (3 nodes):
[Prev|Data|Next] → [Prev|Data|Next] → [Prev|Data|NULL]
   12 bytes         12 bytes          12 bytes
   Total: 36 bytes (50% more, but more flexible!)

╚════════════════════════════════════════════════════════╝
```

---

## 🎯 Key Takeaways

### SLL Best For:
```
✓ Simple sequential access
✓ Stack implementation
✓ When memory is critical
✓ When you only need forward traversal
✓ Simple-to-understand code

Use: When speed at head is crucial, don't need tail access
```

### DLL Best For:
```
✓ Deque (double-ended queue) implementation
✓ LRU Cache
✓ Browser history (back/forward)
✓ Music playlist (previous/next)
✓ Text editor (undo/redo)

Use: When you need fast access at BOTH ends
```

### Golden Rules to Remember:

```
1. SLL Insert/Delete at HEAD = O(1) ⚡
2. SLL Insert/Delete at TAIL = O(n) ❌
3. DLL Insert/Delete at HEAD = O(1) ⚡
4. DLL Insert/Delete at TAIL = O(1) ⚡⚡
5. Both can SEARCH = O(n)
6. Both can ACCESS by index = O(n)
7. DLL has BACKWARD traversal ✓
8. SLL is SIMPLER code
9. DLL uses MORE memory (1 extra pointer)
10. DLL is MORE FLEXIBLE ✓
```

---

## 🤝 Contributing

Contributions welcome! Please:

1. Fork the repository
2. Create a feature branch
3. Add improvements or fixes
4. Submit a pull request

---

## 📚 Additional Resources

### Books
- "Introduction to Algorithms" - CLRS
- "Data Structures Using C++" - Seymour Lipschutz
- "Algorithm Design Manual" - Steven Skiena

### Online Courses
- Coursera Data Structures
- Udemy DSA Courses
- MIT OpenCourseWare

### Practice Platforms
- [LeetCode](https://leetcode.com/tag/linked-list/)
- [HackerRank](https://www.hackerrank.com/domains/data-structures)
- [CodeForces](https://codeforces.com/)
- [GeeksforGeeks](https://www.geeksforgeeks.org/data-structures/linked-list/)

---

## 📞 Contact & Support

- 📧 **Email:** [jobaobada8@gmail.com]
- 💬 **GitHub Issues:** [Report Issues](https://github.com/Obada111/linked-list/issues)
- 💭 **Discussions:** [GitHub Discussions](https://github.com/Obada111/linked-list/discussions)

---

## 📄 License

MIT License - Free to use and modify

---

<div align="center">

## ⭐ If This Helped You, Please Star!

**[⭐ STAR THIS REPOSITORY ⭐](https://github.com/Obada111/linked-list)**

---

### 🏆 Master Linked Lists → Master Data Structures → Master Programming!

**Complete | Professional | Ready to Use**

[⬆ Back to Top](#-linked-list-complete-guide---singly--doubly-linked-lists)

</div>
