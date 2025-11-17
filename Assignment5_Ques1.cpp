#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertBeginning(int x) {
    Node* temp = new Node{x, head};
    head = temp;
}

void insertEnd(int x) {
    Node* temp = new Node{x, nullptr};
    if (!head) {
        head = temp;
        return;
    }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

void insertBefore(int key, int x) {
    if (!head) { cout << "List empty\n"; return; }

    if (head->data == key) { insertBeginning(x); return; }

    Node* p = head;
    while (p->next && p->next->data != key)
        p = p->next;

    if (!p->next) { cout << "Key not found\n"; return; }

    Node* temp = new Node{x, p->next};
    p->next = temp;
}

void insertAfter(int key, int x) {
    Node* p = head;
    while (p && p->data != key)
        p = p->next;

    if (!p) { cout << "Key not found\n"; return; }

    Node* temp = new Node{x, p->next};
    p->next = temp;
}

void deleteBeginning() {
    if (!head) { cout << "List empty\n"; return; }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (!head) { cout << "List empty\n"; return; }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* p = head;
    while (p->next->next) p = p->next;

    delete p->next;
    p->next = nullptr;
}

void deleteValue(int key) {
    if (!head) { cout << "List empty\n"; return; }

    if (head->data == key) {
        deleteBeginning();
        return;
    }

    Node* p = head;
    while (p->next && p->next->data != key)
        p = p->next;

    if (!p->next) { cout << "Node not found\n"; return; }

    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
}

void searchValue(int key) {
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
    if (!p) { cout << "List empty\n"; return; }
    cout << "List: ";
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int choice, x, key;

    while (true) {
        cout << "\n--- SINGLY LINKED LIST MENU ---\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Before\n4. Insert After\n";
        cout << "5. Delete Beginning\n6. Delete End\n7. Delete Value\n";
        cout << "8. Search\n9. Display\n10. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: cin >> x; insertBeginning(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: cin >> key >> x; insertBefore(key, x); break;
            case 4: cin >> key >> x; insertAfter(key, x); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> key; deleteValue(key); break;
            case 8: cin >> key; searchValue(key); break;
            case 9: display(); break;
            case 10: return 0;
            default: cout << "Invalid\n";
        }
    }
}
