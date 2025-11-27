# 🔗 Doubly Linked List (DLL): The Complete Guide

<div align="center">
  <img src="https://img.shields.io/badge/Data_Structure-Doubly_Linked_List-blue?style=for-the-badge&logo=code" alt="Data Structure">
  <img src="https://img.shields.io/badge/Complexity-O(1)_Operations-brightgreen?style=for-the-badge" alt="Complexity">
  <img src="https://img.shields.io/badge/Category-Algorithms-purple?style=for-the-badge" alt="Category">
  <img src="https://img.shields.io/badge/Level-Intermediate-orange?style=for-the-badge" alt="Level">
</div>

<div align="center">
  <img width="800" src="https://i.imgur.com/4q2aVdN.png" alt="Doubly Linked List Visualization">
</div>

> **💡 Important Note:** This guide is about **Doubly Linked List (DLL)** — a fundamental data structure in computer science, *not* Dynamic Link Library.

---

## 🌟 Table of Contents

- [🔍 What is a Doubly Linked List?](#-what-is-a-doubly-linked-list)
- [🧩 Structure & Components](#-structure--components)
- [⚡ Key Operations](#-key-operations)
- [⏱️ Time Complexity Analysis](#-time-complexity-analysis)
- [🧾 Code Implementations](#-code-implementations)
- [🆚 Comparison with Other Data Structures](#-comparison-with-other-data-structures)
- [🛠️ Practical Applications](#-practical-applications)
- [🔧 Best Practices](#-best-practices)
- [🚀 Advanced Operations](#-advanced-operations)
- [📚 Further Reading](#-further-reading)

---

## 🔍 What is a Doubly Linked List?

A **Doubly Linked List (DLL)** is a linear data structure where each element (node) contains three parts: data, a pointer to the next node, and a pointer to the previous node.

### ✨ Key Characteristics:
- Each node has **two pointers**: `next` and `prev`
- Can be traversed in **both directions** (forward and backward)
- Requires **more memory** per node compared to singly linked lists
- Allows **efficient insertion and deletion** at both ends
- No need to traverse from the beginning to reach previous elements

### 🆚 Doubly vs Singly Linked List

| **Feature** | **Singly Linked List** | **Doubly Linked List** |
|------------|----------------------|----------------------|
| **Node Structure** | Data + Next pointer | Data + Next + Previous pointers |
| **Traversal Direction** | Forward only | Forward and backward |
| **Memory Usage** | Less (one pointer per node) | More (two pointers per node) |
| **Insertion at Beginning** | O(1) | O(1) |
| **Insertion at End** | O(n) | O(1) with tail pointer |
| **Deletion of Node** | Requires previous node | Can delete with only current node |
| **Reverse Traversal** | Not possible | Possible |

---
┌─────────┐ ┌─────────┐ ┌─────────┐
│ prev │ │ prev │ │ prev │
│ pointer │◄───┤ pointer │◄───┤ pointer │
├─────────┤ ├─────────┤ ├─────────┤
│ Data │ │ Data │ │ Data │
├─────────┤ ├─────────┤ ├─────────┤
│ next │───►│ next │───►│ next │
│ pointer │ │ pointer │ │ pointer │
└─────────┘ └─────────┘ └─────────┘


## 🧩 Structure & Components

### 📦 Node Structure

Each node consists of:
1. **Data field**: Stores the actual value
2. **Next pointer**: References the next node in the sequence
3. **Previous pointer**: References the previous node in the sequence

### 🏗️ Complete List Structure

```c
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

The list is maintained with:

Head pointer: Points to the first node
Tail pointer (optional): Points to the last node for O(1) end operations

⚡ Key Operations
➕ Insertion Operations
1. Insert at Beginning
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    
    if (head != NULL)
        head->prev = newNode;
    
    return newNode; // New head
}

2. Insert at End

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    
    Node* current = head;
    while (current->next != NULL)
        current = current->next;
    
    current->next = newNode;
    newNode->prev = current;
    return head;
}
3. Insert After a Node
void insertAfter(Node* prevNode, int value) {
    if (prevNode == NULL) return;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;
    
    prevNode->next = newNode;
}
➖ Deletion Operations
1. Delete from Beginning
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) return NULL;
    
    Node* temp = head;
    head = head->next;
    
    if (head != NULL)
        head->prev = NULL;
    
    free(temp);
    return head;
}


