#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = nullptr;

void insertBeginning(int x) {
    Node* temp = new Node{x, nullptr, head};
    if (head) head->prev = temp;
    head = temp;
}

void insertEnd(int x) {
    if (!head) { insertBeginning(x); return; }

    Node* p = head;
    while (p->next) p = p->next;

    Node* temp = new Node{x, p, nullptr};
    p->next = temp;
}

void insertAfter(int key, int x) {
    Node* p = head;
    while (p && p->data != key) p = p->next;

    if (!p) { cout << "Key not found\n"; return; }

    Node* temp = new Node{x, p, p->next};
    if (p->next) p->next->prev = temp;
    p->next = temp;
}

void insertBefore(int key, int x) {
    if (!head) return;
    if (head->data == key) { insertBeginning(x); return; }

    Node* p = head;
    while (p && p->data != key) p = p->next;

    if (!p) { cout << "Key not found\n"; return; }

    Node* temp = new Node{x, p->prev, p};
    p->prev->next = temp;
    p->prev = temp;
}

void deleteValue(int key) {
    Node* p = head;

    while (p && p->data != key) p = p->next;
    if (!p) { cout << "Not found\n"; return; }

    if (p->prev) p->prev->next = p->next;
    else head = p->next;

    if (p->next) p->next->prev = p->prev;

    delete p;
}

void search(int key) {
    Node* p = head;
    int pos = 1;

    while (p) {
        if (p->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found\n";
}

void display() {
    Node* p = head;
    cout << "List: ";
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, x, key;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert After\n4. Insert Before\n";
        cout << "5. Delete Node\n6. Search Node\n7. Display\n8. Exit\n";
        cin >> ch;

        switch(ch) {
            case 1: cin >> x; insertBeginning(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: cin >> key >> x; insertAfter(key, x); break;
            case 4: cin >> key >> x; insertBefore(key, x); break;
            case 5: cin >> key; deleteValue(key); break;
            case 6: cin >> key; search(key); break;
            case 7: display(); break;
            case 8: return 0;
        }
    }
}
