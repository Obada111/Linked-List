#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t sz;

    // helper for printReverse
    void printReverseHelper(Node* cur) const {
        if (!cur) return;
        printReverseHelper(cur->next);
        cout << cur->data << " ";
    }

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}

    ~SinglyLinkedList() {
        clear();
    }

    bool empty() const {
        return head == nullptr;
    }

    size_t size() const {
        return sz;
    }

    // --------- Access ---------
    int front() const {
        if (empty()) {
            throw runtime_error("List is empty (front).");
        }
        return head->data;
    }

    int back() const {
        if (empty()) {
            throw runtime_error("List is empty (back).");
        }
        return tail->data;
    }

    // --------- Insertion ---------
    void push_front(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        if (!tail) tail = head;
        ++sz;
    }

    void push_back(int value) {
        Node* node = new Node(value);
        if (empty()) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        ++sz;
    }

    // insert at position (0-based index)
    void insert_at(size_t index, int value) {
        if (index > sz) {
            throw out_of_range("insert_at: index out of range");
        }
        if (index == 0) {
            push_front(value);
            return;
        }
        if (index == sz) {
            push_back(value);
            return;
        }

        Node* prev = head;
        for (size_t i = 0; i + 1 < index; ++i) {
            prev = prev->next;
        }
        Node* node = new Node(value);
        node->next = prev->next;
        prev->next = node;
        ++sz;
    }

    // --------- Deletion ---------
    void pop_front() {
        if (empty()) {
            throw runtime_error("pop_front: list is empty");
        }
        Node* del = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete del;
        --sz;
    }

    void pop_back() {
        if (empty()) {
            throw runtime_error("pop_back: list is empty");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* prev = nullptr;
            Node* cur = head;
            while (cur->next) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = nullptr;
            tail = prev;
            delete cur;
        }
        --sz;
    }

    // erase node at position (0-based)
    void erase_at(size_t index) {
        if (index >= sz) {
            throw out_of_range("erase_at: index out of range");
        }
        if (index == 0) {
            pop_front();
            return;
        }

        Node* prev = head;
        for (size_t i = 0; i + 1 < index; ++i) {
            prev = prev->next;
        }
        Node* del = prev->next;
        prev->next = del->next;
        if (del == tail) tail = prev;
        delete del;
        --sz;
    }

    // remove first occurrence of value
    bool remove_first(int value) {
        if (empty()) return false;

        if (head->data == value) {
            pop_front();
            return true;
        }

        Node* prev = head;
        Node* cur = head->next;

        while (cur) {
            if (cur->data == value) {
                prev->next = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                --sz;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    // remove all occurrences of value
    int remove_all(int value) {
        int removed = 0;
        while (!empty() && head->data == value) {
            pop_front();
            ++removed;
        }
        if (empty()) return removed;

        Node* prev = head;
        Node* cur = head->next;
        while (cur) {
            if (cur->data == value) {
                prev->next = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                cur = prev->next;
                --sz;
                ++removed;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return removed;
    }

    // --------- Search ---------
    Node* find(int value) const {
        Node* cur = head;
        while (cur) {
            if (cur->data == value) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    bool contains(int value) const {
        return find(value) != nullptr;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void reverse() {
        if (sz <= 1) return;

        Node* prev = nullptr;
        Node* cur = head;
        tail = head; 

        while (cur) {
            Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    int max_value() const {
        if (empty()) {
            throw runtime_error("max_value: list is empty");
        }
        int mx = head->data;
        Node* cur = head->next;
        while (cur) {
            if (cur->data > mx) mx = cur->data;
            cur = cur->next;
        }
        return mx;
    }

    void print() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void print_reverse() const {
        printReverseHelper(head);
        cout << endl;
    }
};

int main() {
    SinglyLinkedList lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_front(5);      
    lst.insert_at(2, 15);  

    cout << "List: ";
    lst.print();

    cout << "Size = " << lst.size() << endl;
    cout << "Front = " << lst.front() << endl;
    cout << "Back  = " << lst.back()  << endl;
    cout << "Max   = " << lst.max_value() << endl;

    cout << "Contains 20? " << (lst.contains(20) ? "YES" : "NO") << endl;

    lst.remove_first(15);   
    cout << "After remove_first(15): ";
    lst.print();

    lst.reverse();
    cout << "After reverse: ";
    lst.print();

    cout << "Print reverse (recursion): ";
    lst.print_reverse();

    return 0;
}
