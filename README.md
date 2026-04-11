# Linked List in C++

A clean C++ implementation of **Singly Linked List (SLL)** and **Doubly Linked List (DLL)**, built to help you understand linked lists from the ground up with practical operations and clear examples.

---

## Visual Concept — Singly Linked List

![SLL Diagram](<svg viewBox="0 0 860 620" xmlns="http://www.w3.org/2000/svg" font-family="'Segoe UI', Arial, sans-serif">

  <!-- Background -->
  <rect width="860" height="620" rx="16" fill="#0f1117"/>

  <!-- ══════════════════════════════════════════════════════
       TITLE
  ══════════════════════════════════════════════════════ -->
  <text x="430" y="42" text-anchor="middle" font-size="22" font-weight="700" fill="#e2e8f0" letter-spacing="1">Singly Linked List — Visual Guide</text>
  <line x1="60" y1="54" x2="800" y2="54" stroke="#2d3748" stroke-width="1.5"/>

  <!-- ══════════════════════════════════════════════════════
       SECTION 1 — ANATOMY OF A NODE
  ══════════════════════════════════════════════════════ -->
  <text x="60" y="82" font-size="13" font-weight="600" fill="#63b3ed">① Node anatomy</text>

  <!-- node box -->
  <rect x="200" y="92" width="100" height="44" rx="6" fill="#1a202c" stroke="#4299e1" stroke-width="1.8"/>
  <line x1="260" y1="92" x2="260" y2="136" stroke="#4299e1" stroke-width="1.5"/>
  <text x="230" y="119" text-anchor="middle" font-size="15" font-weight="700" fill="#90cdf4">42</text>
  <text x="280" y="112" text-anchor="middle" font-size="10" fill="#68d391">next</text>
  <text x="280" y="124" text-anchor="middle" font-size="10" fill="#68d391">●</text>

  <!-- labels -->
  <text x="230" y="150" text-anchor="middle" font-size="10" fill="#718096">data</text>
  <text x="280" y="150" text-anchor="middle" font-size="10" fill="#718096">pointer</text>

  <!-- struct code -->
  <rect x="340" y="88" width="220" height="56" rx="6" fill="#171923" stroke="#2d3748" stroke-width="1"/>
  <text x="352" y="104" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">struct</text>
  <text x="388" y="104" font-size="10" fill="#63b3ed" font-family="Consolas, monospace">Node {</text>
  <text x="362" y="118" font-size="10" fill="#68d391" font-family="Consolas, monospace">int   data;</text>
  <text x="362" y="132" font-size="10" fill="#68d391" font-family="Consolas, monospace">Node* next;</text>
  <text x="352" y="138" font-size="10" fill="#63b3ed" font-family="Consolas, monospace">};</text>

  <!-- ══════════════════════════════════════════════════════
       SECTION 2 — FULL LIST CHAIN
  ══════════════════════════════════════════════════════ -->
  <text x="60" y="178" font-size="13" font-weight="600" fill="#63b3ed">② How nodes form a chain</text>

  <!-- head label -->
  <text x="104" y="212" text-anchor="middle" font-size="11" fill="#f6ad55" font-weight="600">head</text>
  <line x1="104" y1="215" x2="104" y2="228" stroke="#f6ad55" stroke-width="1.5" marker-end="url(#arrowOrange)"/>

  <!-- node 1 -->
  <rect x="66" y="230" width="90" height="44" rx="6" fill="#1a202c" stroke="#4299e1" stroke-width="1.8"/>
  <line x1="116" y1="230" x2="116" y2="274" stroke="#4299e1" stroke-width="1.5"/>
  <text x="91" y="257" text-anchor="middle" font-size="16" font-weight="700" fill="#90cdf4">5</text>
  <text x="134" y="253" text-anchor="middle" font-size="10" fill="#68d391">●</text>
  <!-- arrow -->
  <line x1="156" y1="252" x2="188" y2="252" stroke="#68d391" stroke-width="2" marker-end="url(#arrowGreen)"/>

  <!-- node 2 -->
  <rect x="190" y="230" width="90" height="44" rx="6" fill="#1a202c" stroke="#4299e1" stroke-width="1.8"/>
  <line x1="240" y1="230" x2="240" y2="274" stroke="#4299e1" stroke-width="1.5"/>
  <text x="215" y="257" text-anchor="middle" font-size="16" font-weight="700" fill="#90cdf4">10</text>
  <text x="258" y="253" text-anchor="middle" font-size="10" fill="#68d391">●</text>
  <line x1="280" y1="252" x2="312" y2="252" stroke="#68d391" stroke-width="2" marker-end="url(#arrowGreen)"/>

  <!-- node 3 -->
  <rect x="314" y="230" width="90" height="44" rx="6" fill="#1a202c" stroke="#4299e1" stroke-width="1.8"/>
  <line x1="364" y1="230" x2="364" y2="274" stroke="#4299e1" stroke-width="1.5"/>
  <text x="339" y="257" text-anchor="middle" font-size="16" font-weight="700" fill="#90cdf4">20</text>
  <text x="382" y="253" text-anchor="middle" font-size="10" fill="#68d391">●</text>
  <line x1="404" y1="252" x2="436" y2="252" stroke="#68d391" stroke-width="2" marker-end="url(#arrowGreen)"/>

  <!-- node 4 -->
  <rect x="438" y="230" width="90" height="44" rx="6" fill="#1a202c" stroke="#4299e1" stroke-width="1.8"/>
  <line x1="488" y1="230" x2="488" y2="274" stroke="#4299e1" stroke-width="1.5"/>
  <text x="463" y="257" text-anchor="middle" font-size="16" font-weight="700" fill="#90cdf4">30</text>
  <text x="506" y="253" text-anchor="middle" font-size="10" fill="#e53e3e">NULL</text>
  <!-- NULL cross -->
  <line x1="524" y1="246" x2="536" y2="258" stroke="#e53e3e" stroke-width="1.8"/>
  <line x1="536" y1="246" x2="524" y2="258" stroke="#e53e3e" stroke-width="1.8"/>

  <!-- tail label -->
  <text x="483" y="296" text-anchor="middle" font-size="11" fill="#f6ad55" font-weight="600">tail</text>
  <line x1="483" y1="280" x2="483" y2="293" stroke="#f6ad55" stroke-width="1.5"/>

  <!-- index labels -->
  <text x="111" y="284" text-anchor="middle" font-size="9" fill="#718096">[0]</text>
  <text x="235" y="284" text-anchor="middle" font-size="9" fill="#718096">[1]</text>
  <text x="359" y="284" text-anchor="middle" font-size="9" fill="#718096">[2]</text>
  <text x="483" y="284" text-anchor="middle" font-size="9" fill="#718096">[3]</text>

  <!-- ══════════════════════════════════════════════════════
       SECTION 3 — PUSH_FRONT
  ══════════════════════════════════════════════════════ -->
  <line x1="60" y1="308" x2="800" y2="308" stroke="#2d3748" stroke-width="1"/>
  <text x="60" y="328" font-size="13" font-weight="600" fill="#63b3ed">③ push_front(1)  — O(1)</text>

  <!-- new node -->
  <rect x="66" y="336" width="90" height="44" rx="6" fill="#22543d" stroke="#68d391" stroke-width="2" stroke-dasharray="5,3"/>
  <line x1="116" y1="336" x2="116" y2="380" stroke="#68d391" stroke-width="1.5"/>
  <text x="91" y="363" text-anchor="middle" font-size="16" font-weight="700" fill="#9ae6b4">1</text>
  <text x="134" y="359" text-anchor="middle" font-size="10" fill="#68d391">●</text>
  <text x="91" y="390" text-anchor="middle" font-size="9" fill="#68d391">NEW</text>

  <!-- arrow to old head -->
  <line x1="156" y1="358" x2="210" y2="358" stroke="#68d391" stroke-width="2" stroke-dasharray="5,3" marker-end="url(#arrowGreen)"/>

  <!-- old head -->
  <rect x="212" y="336" width="90" height="44" rx="6" fill="#1a202c" stroke="#4299e1" stroke-width="1.8"/>
  <line x1="262" y1="336" x2="262" y2="380" stroke="#4299e1" stroke-width="1.5"/>
  <text x="237" y="363" text-anchor="middle" font-size="16" font-weight="700" fill="#90cdf4">5</text>
  <text x="280" y="359" text-anchor="middle" font-size="10" fill="#68d391">●</text>
  <text x="310" y="363" font-size="10" fill="#718096">→ ...</text>

  <!-- head arrow update -->
  <text x="500" y="348" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">node-&gt;next = head;</text>
  <text x="500" y="364" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">head = node;</text>
  <text x="500" y="380" font-size="10" fill="#718096">head pointer moves to new node</text>

  <!-- ══════════════════════════════════════════════════════
       SECTION 4 — REMOVE / DELETE
  ══════════════════════════════════════════════════════ -->
  <line x1="60" y1="408" x2="800" y2="408" stroke="#2d3748" stroke-width="1"/>
  <text x="60" y="428" font-size="13" font-weight="600" fill="#63b3ed">④ remove_first(20)  — O(n)</text>

  <!-- traverse label -->
  <text x="66" y="448" font-size="10" fill="#718096">traverse until prev.next.data == 20</text>

  <!-- node A -->
  <rect x="66" y="455" width="80" height="40" rx="6" fill="#1a202c" stroke="#4299e1" stroke-width="1.8"/>
  <line x1="106" y1="455" x2="106" y2="495" stroke="#4299e1" stroke-width="1.5"/>
  <text x="86" y="480" text-anchor="middle" font-size="14" font-weight="700" fill="#90cdf4">5</text>
  <text x="120" y="477" text-anchor="middle" font-size="10" fill="#68d391">●</text>

  <!-- arrow -->
  <line x1="146" y1="475" x2="170" y2="475" stroke="#68d391" stroke-width="2" marker-end="url(#arrowGreen)"/>

  <!-- node B  (prev) -->
  <rect x="172" y="455" width="80" height="40" rx="6" fill="#1a202c" stroke="#f6ad55" stroke-width="2"/>
  <line x1="212" y1="455" x2="212" y2="495" stroke="#f6ad55" stroke-width="1.5"/>
  <text x="192" y="480" text-anchor="middle" font-size="14" font-weight="700" fill="#90cdf4">10</text>
  <text x="226" y="477" text-anchor="middle" font-size="10" fill="#68d391">●</text>
  <text x="212" y="508" text-anchor="middle" font-size="9" fill="#f6ad55">prev</text>

  <!-- arrow to target -->
  <line x1="252" y1="475" x2="276" y2="475" stroke="#68d391" stroke-width="2" marker-end="url(#arrowGreen)"/>

  <!-- node C (target — 20) -->
  <rect x="278" y="455" width="80" height="40" rx="6" fill="#742a2a" stroke="#e53e3e" stroke-width="2"/>
  <line x1="318" y1="455" x2="318" y2="495" stroke="#e53e3e" stroke-width="1.5"/>
  <text x="298" y="480" text-anchor="middle" font-size="14" font-weight="700" fill="#fc8181">20</text>
  <text x="332" y="477" text-anchor="middle" font-size="10" fill="#68d391">●</text>
  <text x="298" y="508" text-anchor="middle" font-size="9" fill="#e53e3e">DELETE</text>

  <!-- arrow from target to next -->
  <line x1="358" y1="475" x2="382" y2="475" stroke="#68d391" stroke-width="2" marker-end="url(#arrowGreen)"/>

  <!-- node D -->
  <rect x="384" y="455" width="80" height="40" rx="6" fill="#1a202c" stroke="#4299e1" stroke-width="1.8"/>
  <line x1="424" y1="455" x2="424" y2="495" stroke="#4299e1" stroke-width="1.5"/>
  <text x="404" y="480" text-anchor="middle" font-size="14" font-weight="700" fill="#90cdf4">30</text>
  <text x="438" y="477" text-anchor="middle" font-size="10" fill="#e53e3e">NULL</text>

  <!-- bypass arrow -->
  <path d="M 252 467 Q 298 440 382 467" stroke="#68d391" stroke-width="2" fill="none" stroke-dasharray="5,3" marker-end="url(#arrowGreen)"/>
  <text x="298" y="444" text-anchor="middle" font-size="9" fill="#9ae6b4">prev→next = cur→next</text>

  <!-- code -->
  <text x="500" y="465" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">prev-&gt;next = cur-&gt;next;</text>
  <text x="500" y="480" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">delete cur;</text>
  <text x="500" y="496" font-size="10" fill="#718096">node is unlinked, then freed</text>

  <!-- ══════════════════════════════════════════════════════
       SECTION 5 — REVERSE
  ══════════════════════════════════════════════════════ -->
  <line x1="60" y1="524" x2="800" y2="524" stroke="#2d3748" stroke-width="1"/>
  <text x="60" y="544" font-size="13" font-weight="600" fill="#63b3ed">⑤ reverse()  — O(n), in-place pointer flip</text>

  <!-- before -->
  <text x="66" y="562" font-size="10" fill="#718096">Before:</text>
  <text x="108" y="562" font-size="10" fill="#90cdf4">5 → 10 → 20 → NULL</text>
  <!-- after -->
  <text x="66" y="582" font-size="10" fill="#718096">After: </text>
  <text x="108" y="582" font-size="10" fill="#9ae6b4">20 → 10 → 5 → NULL</text>

  <!-- code explanation -->
  <text x="340" y="556" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">prev = NULL; cur = head;</text>
  <text x="340" y="570" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">while (cur) {</text>
  <text x="356" y="584" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">next=cur-&gt;next; cur-&gt;next=prev;</text>
  <text x="356" y="598" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">prev=cur; cur=next; }</text>
  <text x="340" y="612" font-size="10" fill="#9f7aea" font-family="Consolas, monospace">head = prev;</text>

  <!-- complexity table -->
  <rect x="620" y="536" width="220" height="70" rx="6" fill="#171923" stroke="#2d3748"/>
  <text x="730" y="552" text-anchor="middle" font-size="10" font-weight="600" fill="#e2e8f0">Complexity Quick Ref</text>
  <text x="630" y="566" font-size="9" fill="#68d391">push_front / push_back</text><text x="828" y="566" text-anchor="end" font-size="9" fill="#faf089">O(1)</text>
  <text x="630" y="579" font-size="9" fill="#68d391">insert_at / erase_at</text>     <text x="828" y="579" text-anchor="end" font-size="9" fill="#faf089">O(n)</text>
  <text x="630" y="592" font-size="9" fill="#68d391">remove_first / contains</text>  <text x="828" y="592" text-anchor="end" font-size="9" fill="#faf089">O(n)</text>
  <text x="630" y="605" font-size="9" fill="#68d391">reverse / max_value</text>      <text x="828" y="605" text-anchor="end" font-size="9" fill="#faf089">O(n)</text>

  <!-- ══════════════════════════════════════════════════════
       ARROW MARKERS
  ══════════════════════════════════════════════════════ -->
  <defs>
    <marker id="arrowGreen" markerWidth="8" markerHeight="8" refX="6" refY="3" orient="auto">
      <path d="M0,0 L0,6 L8,3 z" fill="#68d391"/>
    </marker>
    <marker id="arrowOrange" markerWidth="8" markerHeight="8" refX="6" refY="3" orient="auto">
      <path d="M0,0 L0,6 L8,3 z" fill="#f6ad55"/>
    </marker>
  </defs>

</svg>)

> The diagram above walks through five key ideas: node anatomy, how nodes chain together, `push_front`, `remove_first`, and `reverse` — all with the exact pointer logic from the code.

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

lst.print();             // [ 5 10 15 20 ]
lst.reverse();
lst.print();             // [ 20 15 10 5 ]
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
> He is the professor who taught us Data Structures and guided us through understanding these concepts from the ground up.
> This project would not exist without his clear teaching and continued support. 🙏
