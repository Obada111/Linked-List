#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <memory>
#include <type_traits>
#include <iterator>
using namespace std ;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
        Node(T&& value) : data(move(value)), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    size_t sz;

    Node* getNodeAt(size_t index) {
        if (index >= sz) return nullptr;
        Node* cur;
        if (index < sz / 2) {
            cur = head;
            for (size_t i = 0; i < index; ++i) cur = cur->next;
        } else {
            cur = tail;
            for (size_t i = sz - 1; i > index; --i) cur = cur->prev;
        }
        return cur;
    }

    const Node* getNodeAt(size_t index) const {
        if (index >= sz) return nullptr;
        const Node* cur;
        if (index < sz / 2) {
            cur = head;
            for (size_t i = 0; i < index; ++i) cur = cur->next;
        } else {
            cur = tail;
            for (size_t i = sz - 1; i > index; --i) cur = cur->prev;
        }
        return cur;
    }

    void printHelper(Node* cur, const string& sep = " ") const {
        while (cur) {
            cout << cur->data << sep;
            cur = cur->next;
        }
    }

    void printReverseHelper(Node* cur, const string& sep = " ") const {
        while (cur) {
            cout << cur->data << sep;
            cur = cur->prev;
        }
    }

public:
    template <bool IsConst>
    class IteratorImpl {
        using NodePtr = typename conditional<IsConst, const Node*, Node*>::type;
        using Ref = typename conditional<IsConst, const T&, T&>::type;
        using Ptr = typename conditional<IsConst, const T*, T*>::type;

    public:
        using iterator_category = bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = Ptr;
        using reference = Ref;

        IteratorImpl(NodePtr node) : current(node) {}

        reference operator*() const { return current->data; }
        pointer operator->() const { return &(current->data); }

        IteratorImpl& operator++() {
            current = current->next;
            return *this;
        }

        IteratorImpl operator++(int) {
            IteratorImpl tmp = *this;
            ++(*this);
            return tmp;
        }

        IteratorImpl& operator--() {
            current = current->prev;
            return *this;
        }

        IteratorImpl operator--(int) {
            IteratorImpl tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator==(const IteratorImpl& other) const {
            return current == other.current;
        }

        bool operator!=(const IteratorImpl& other) const {
            return current != other.current;
        }

        operator IteratorImpl<true>() const {
            return IteratorImpl<true>(current);
        }

    private:
        NodePtr current;
    };

    using iterator = IteratorImpl<false>;
    using const_iterator = IteratorImpl<true>;
    using reverse_iterator = reverse_iterator<iterator>;
    using const_reverse_iterator = reverse_iterator<const_iterator>;

    DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}

    DoublyLinkedList(initializer_list<T> init) : DoublyLinkedList() {
        for (const auto& val : init) {
            push_back(val);
        }
    }

    DoublyLinkedList(const DoublyLinkedList& other) : DoublyLinkedList() {
        for (const auto& val : other) {
            push_back(val);
        }
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            for (const auto& val : other) {
                push_back(val);
            }
        }
        return *this;
    }

    DoublyLinkedList(DoublyLinkedList&& other) noexcept 
        : head(other.head), tail(other.tail), sz(other.sz) {
        other.head = other.tail = nullptr;
        other.sz = 0;
    }

    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            sz = other.sz;
            other.head = other.tail = nullptr;
            other.sz = 0;
        }
        return *this;
    }

    ~DoublyLinkedList() {
        clear();
    }

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
    const_iterator begin() const { return cbegin(); }
    const_iterator end() const { return cend(); }
    const_iterator cbegin() const { return const_iterator(head); }
    const_iterator cend() const { return const_iterator(nullptr); }
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator crbegin() const { return const_reverse_iterator(cend()); }
    const_reverse_iterator crend() const { return const_reverse_iterator(cbegin()); }

    bool empty() const { return head == nullptr; }
    size_t size() const { return sz; }

    T& front() {
        if (empty()) throw out_of_range("front: list is empty");
        return head->data;
    }

    const T& front() const {
        if (empty()) throw out_of_range("front: list is empty");
        return head->data;
    }

    T& back() {
        if (empty()) throw out_of_range("back: list is empty");
        return tail->data;
    }

    const T& back() const {
        if (empty()) throw out_of_range("back: list is empty");
        return tail->data;
    }

    T& at(size_t index) {
        if (index >= sz) throw out_of_range("at: index out of range");
        return getNodeAt(index)->data;
    }

    const T& at(size_t index) const {
        if (index >= sz) throw out_of_range("at: index out of range");
        return getNodeAt(index)->data;
    }

    T& operator[](size_t index) {
        return at(index);
    }

    const T& operator[](size_t index) const {
        return at(index);
    }

    // Modifiers
    void push_front(const T& value) {
        Node* node = new Node(value);
        if (empty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        ++sz;
    }

    void push_front(T&& value) {
        Node* node = new Node(move(value));
        if (empty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        ++sz;
    }

    void push_back(const T& value) {
        Node* node = new Node(value);
        if (empty()) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        ++sz;
    }

    void push_back(T&& value) {
        Node* node = new Node(move(value));
        if (empty()) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        ++sz;
    }

    template <typename... Args>
    void emplace_front(Args&&... args) {
        Node* node = new Node(T(forward<Args>(args)...));
        if (empty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        ++sz;
    }

    template <typename... Args>
    void emplace_back(Args&&... args) {
        Node* node = new Node(T(forward<Args>(args)...));
        if (empty()) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        ++sz;
    }

    bool insert_at(size_t index, const T& value) {
        if (index > sz) return false;
        if (index == 0) {
            push_front(value);
            return true;
        }
        if (index == sz) {
            push_back(value);
            return true;
        }
        Node* cur = getNodeAt(index);
        Node* node = new Node(value);
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        ++sz;
        return true;
    }

    bool insert_at(size_t index, T&& value) {
        if (index > sz) return false;
        if (index == 0) {
            push_front(move(value));
            return true;
        }
        if (index == sz) {
            push_back(move(value));
            return true;
        }
        Node* cur = getNodeAt(index);
        Node* node = new Node(move(value));
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        ++sz;
        return true;
    }

    template <typename... Args>
    bool emplace_at(size_t index, Args&&... args) {
        if (index > sz) return false;
        if (index == 0) {
            emplace_front(forward<Args>(args)...);
            return true;
        }
        if (index == sz) {
            emplace_back(forward<Args>(args)...);
            return true;
        }
        Node* cur = getNodeAt(index);
        Node* node = new Node(T(forward<Args>(args)...));
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        ++sz;
        return true;
    }

    bool insert_before_value(const T& value, const T& before) {
        Node* cur = head;
        while (cur && cur->data != before) cur = cur->next;
        if (!cur) return false;
        if (cur == head) {
            push_front(value);
            return true;
        }
        Node* node = new Node(value);
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        ++sz;
        return true;
    }

    bool insert_after_value(const T& value, const T& after) {
        Node* cur = head;
        while (cur && cur->data != after) cur = cur->next;
        if (!cur) return false;
        if (cur == tail) {
            push_back(value);
            return true;
        }
        Node* node = new Node(value);
        node->next = cur->next;
        node->prev = cur;
        cur->next->prev = node;
        cur->next = node;
        ++sz;
        return true;
    }

    bool pop_front() {
        if (empty()) return false;
        Node* del = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete del;
        --sz;
        return true;
    }

    bool pop_back() {
        if (empty()) return false;
        Node* del = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete del;
        --sz;
        return true;
    }

    bool erase_at(size_t index) {
        if (index >= sz) return false;
        if (index == 0) return pop_front();
        if (index == sz - 1) return pop_back();
        Node* cur = getNodeAt(index);
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        --sz;
        return true;
    }

    iterator erase(iterator pos) {
        if (pos == end()) return end();
        
        Node* node = pos.current;
        Node* next = node->next;
        
        if (node == head) {
            pop_front();
        } else if (node == tail) {
            pop_back();
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            --sz;
        }
        
        return iterator(next);
    }

    iterator erase(iterator first, iterator last) {
        if (first == last) return first;
        
        Node* start = first.current;
        Node* end = last.current;
        Node* prev = (start && start->prev) ? start->prev : nullptr;
        Node* next = (end && end->next) ? end->next : nullptr;
        
        Node* cur = start;
        while (cur != end) {
            Node* del = cur;
            cur = cur->next;
            delete del;
            --sz;
        }
        
        if (prev) {
            prev->next = next;
        } else {
            head = next;
        }
        
        if (next) {
            next->prev = prev;
        } else {
            tail = prev;
        }
        
        return iterator(next);
    }

    bool remove_first(const T& value) {
        Node* cur = head;
        while (cur && cur->data != value) cur = cur->next;
        if (!cur) return false;
        if (cur == head) return pop_front();
        if (cur == tail) return pop_back();
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        --sz;
        return true;
    }

    int remove_all(const T& value) {
        int removed = 0;
        Node* cur = head;
        while (cur) {
            if (cur->data == value) {
                Node* del = cur;
                cur = cur->next;
                if (del == head) pop_front();
                else if (del == tail) pop_back();
                else {
                    del->prev->next = del->next;
                    del->next->prev = del->prev;
                    delete del;
                    --sz;
                }
                ++removed;
            } else {
                cur = cur->next;
            }
        }
        return removed;
    }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
        sz = 0;
    }

    void reverse() {
        if (sz <= 1) return;
        Node* cur = head;
        while (cur) {
            swap(cur->next, cur->prev);
            cur = cur->prev;
        }
        swap(head, tail);
    }

    void sort_ascending() {
        if (sz <= 1) return;
        vector<T> vec = to_vector();
        sort(vec.begin(), vec.end());
        clear();
        for (const auto& val : vec) {
            push_back(val);
        }
    }

    void sort_descending() {
        if (sz <= 1) return;
        vector<T> vec = to_vector();
        sort(vec.begin(), vec.end(), greater<T>());
        clear();
        for (const auto& val : vec) {
            push_back(val);
        }
    }

    void remove_duplicates() {
        Node* cur = head;
        while (cur) {
            Node* inner = cur->next;
            while (inner) {
                if (inner->data == cur->data) {
                    Node* del = inner;
                    inner = inner->next;
                    if (del == tail) pop_back();
                    else {
                        del->prev->next = del->next;
                        del->next->prev = del->prev;
                        delete del;
                        --sz;
                    }
                } else {
                    inner = inner->next;
                }
            }
            cur = cur->next;
        }
    }

    void unique() {
        if (sz <= 1) return;
        iterator it = begin();
        iterator next = it;
        ++next;
        while (next != end()) {
            if (*it == *next) {
                next = erase(next);
            } else {
                it = next;
                ++next;
            }
        }
    }

    void append(DoublyLinkedList& other) {
        if (other.empty()) return;
        Node* cur = other.head;
        while (cur) {
            push_back(cur->data);
            cur = cur->next;
        }
    }

    void splice(iterator pos, DoublyLinkedList& other) {
        if (other.empty()) return;
        
        Node* posNode = pos.current;
        Node* otherHead = other.head;
        Node* otherTail = other.tail;
        
        if (posNode) {
            otherHead->prev = posNode;
            otherTail->next = posNode->next;
            
            if (posNode->next) {
                posNode->next->prev = otherTail;
            } else {
                tail = otherTail;
            }
            
            posNode->next = otherHead;
        } else {
            otherTail->next = head;
            if (head) {
                head->prev = otherTail;
            } else {
                tail = otherTail;
            }
            head = otherHead;
        }
        
        sz += other.sz;
        other.head = other.tail = nullptr;
        other.sz = 0;
    }

    void merge(DoublyLinkedList& other) {
        if (this == &other || other.empty()) return;
        
        if (empty()) {
            splice(begin(), other);
            return;
        }
        
        iterator it1 = begin();
        iterator it2 = other.begin();
        
        while (it2 != other.end()) {
            if (it1 == end() || *it1 > *it2) {
                iterator next = it2;
                ++next;
                splice(it1, other, it2, next);
                it2 = next;
            } else {
                ++it1;
            }
        }
    }

    void swap_nodes(size_t idx1, size_t idx2) {
        if (idx1 >= sz || idx2 >= sz || idx1 == idx2) return;
        Node* n1 = getNodeAt(idx1);
        Node* n2 = getNodeAt(idx2);
        swap(n1->data, n2->data);
    }

    void rotate_left(size_t k) {
        if (sz <= 1 || k == 0) return;
        k = k % sz;
        for (size_t i = 0; i < k; ++i) {
            push_back(front());
            pop_front();
        }
    }

    void rotate_right(size_t k) {
        if (sz <= 1 || k == 0) return;
        k = k % sz;
        for (size_t i = 0; i < k; ++i) {
            push_front(back());
            pop_back();
        }
    }

    bool contains(const T& value) const {
        return find(begin(), end(), value) != end();
    }

    int find_first_index(const T& value) const {
        Node* cur = head;
        int index = 0;
        while (cur) {
            if (cur->data == value) return index;
            cur = cur->next;
            ++index;
        }
        return -1;
    }

    int find_last_index(const T& value) const {
        Node* cur = tail;
        int index = sz - 1;
        while (cur) {
            if (cur->data == value) return index;
            cur = cur->prev;
            --index;
        }
        return -1;
    }

    int count_occurrences(const T& value) const {
        int count = 0;
        Node* cur = head;
        while (cur) {
            if (cur->data == value) ++count;
            cur = cur->next;
        }
        return count;
    }

    T max_value() const {
        if (empty()) throw out_of_range("max_value: list is empty");
        T mx = head->data;
        Node* cur = head->next;
        while (cur) {
            if (cur->data > mx) mx = cur->data;
            cur = cur->next;
        }
        return mx;
    }

    T min_value() const {
        if (empty()) throw out_of_range("min_value: list is empty");
        T mn = head->data;
        Node* cur = head->next;
        while (cur) {
            if (cur->data < mn) mn = cur->data;
            cur = cur->next;
        }
        return mn;
    }

    T median() const {
        if (empty()) throw out_of_range("median: list is empty");
        size_t mid = sz / 2;
        if (sz % 2 == 1) {
            return at(mid);
        }
        T val1 = at(mid - 1);
        T val2 = at(mid);
        return (val1 + val2) / 2;
    }

    DoublyLinkedList get_sublist(size_t start, size_t end) const {
        DoublyLinkedList sub;
        if (start >= sz || end > sz || start > end) return sub;
        for (size_t i = start; i < end; ++i) {
            sub.push_back(at(i));
        }
        return sub;
    }

    bool is_palindrome() const {
        if (sz <= 1) return true;
        Node* left = head;
        Node* right = tail;
        while (left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void replace_all(const T& old_val, const T& new_val) {
        Node* cur = head;
        while (cur) {
            if (cur->data == old_val) {
                cur->data = new_val;
            }
            cur = cur->next;
        }
    }

    bool is_sorted_ascending() const {
        if (sz <= 1) return true;
        Node* cur = head;
        while (cur->next) {
            if (cur->data > cur->next->data) return false;
            cur = cur->next;
        }
        return true;
    }

    bool is_sorted_descending() const {
        if (sz <= 1) return true;
        Node* cur = head;
        while (cur->next) {
            if (cur->data < cur->next->data) return false;
            cur = cur->next;
        }
        return true;
    }

    T sum() const {
        if (empty()) throw out_of_range("sum: list is empty");
        T total = T();
        Node* cur = head;
        while (cur) {
            total += cur->data;
            cur = cur->next;
        }
        return total;
    }

    double average() const {
        if (empty()) throw out_of_range("average: list is empty");
        return static_cast<double>(sum()) / sz;
    }

    vector<T> to_vector() const {
        vector<T> v;
        v.reserve(sz);
        Node* cur = head;
        while (cur) {
            v.push_back(cur->data);
            cur = cur->next;
        }
        return v;
    }

    void print_forward() const {
        if (empty()) {
            cout << "[ empty ]\n";
            return;
        }
        cout << "[ ";
        printHelper(head);
        cout << "]\n";
    }

    void print_backward() const {
        if (empty()) {
            cout << "[ empty ]\n";
            return;
        }
        cout << "[ ";
        printReverseHelper(tail);
        cout << "]\n";
    }

    void print_detailed() const {
        if (empty()) {
            cout << "List: [ empty ]\n\n";
            return;
        }
        cout << "Forward:  [ ";
        printHelper(head);
        cout << "]\n";
        cout << "Backward: [ ";
        printReverseHelper(tail);
        cout << "]\n";
        cout << "Size: " << sz << " | Front: " << front() << " | Back: " << back() << "\n\n";
    }

    void print_with_separator(const string& sep = " -> ") const {
        if (empty()) {
            cout << "[ empty ]\n";
            return;
        }
        Node* cur = head;
        cout << "[";
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << sep;
            cur = cur->next;
        }
        cout << "]\n";
    }
};

template <typename T>
bool operator==(const DoublyLinkedList<T>& lhs, const DoublyLinkedList<T>& rhs) {
    if (lhs.size() != rhs.size()) return false;
    return equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T>
bool operator!=(const DoublyLinkedList<T>& lhs, const DoublyLinkedList<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const DoublyLinkedList<T>& lhs, const DoublyLinkedList<T>& rhs) {
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
bool operator<=(const DoublyLinkedList<T>& lhs, const DoublyLinkedList<T>& rhs) {
    return !(rhs < lhs);
}

template <typename T>
bool operator>(const DoublyLinkedList<T>& lhs, const DoublyLinkedList<T>& rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator>=(const DoublyLinkedList<T>& lhs, const DoublyLinkedList<T>& rhs) {
    return !(lhs < rhs);
}
int main() {
    DoublyLinkedList<int> list = {1, 2, 3, 4, 5};
    
    list.emplace_front(0);
    list.emplace_back(6);
    
    transform(list.begin(), list.end(), list.begin(), 
                  [](int x) { return x * 2; });
    
    for (int x : list) {
        cout << x << " ";
    }
    cout << endl;
    
    auto it = find(list.begin(), list.end(), 10);
    if (it != list.end()) {
        *it = 12;
    }
    
    DoublyLinkedList<int> other = {10, 11, 12};
    list.splice(list.begin(), other);
    
    list.print_detailed();
    return 0;
}