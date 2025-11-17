#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertBeginning(int x) {
    Node* temp = new Node{x, nullptr};

    if (!head) {
        head = temp;
        temp->next = head;
        return;
    }

    Node* p = head;
    while (p->next != head) p = p->next;

    temp->next = head;
    p->next = temp;
    head = temp;
}

void insertEnd(int x) {
    if (!head) { insertBeginning(x); return; }

    Node* temp = new Node{x, head};
    Node* p = head;

    while (p->next != head) p = p->next;
    p->next = temp;
}

void insertAfter(int key, int x) {
    if (!head) return;

    Node* p = head;

    do {
        if (p->data == key) {
            Node* temp = new Node{x, p->next};
            p->next = temp;
            return;
        }
        p = p->next;
    } while (p != head);

    cout << "Key not found\n";
}

void insertBefore(int key, int x) {
    if (!head) return;

    if (head->data == key) {
        insertBeginning(x);
        return;
    }

    Node *p = head, *prev = nullptr;

    do {
        if (p->data == key) {
            Node* temp = new Node{x, p};
            prev->next = temp;
            return;
        }
        prev = p;
        p = p->next;
    } while (p != head);

    cout << "Key not found\n";
}

void deleteValue(int key) {
    if (!head) return;

    Node *p = head, *prev = nullptr;

    do {
        if (p->data == key) {
            if (p == head) {
                if (head->next == head) { 
                    delete head;
                    head = nullptr;
                    return;
                }
                Node* last = head;
                while (last->next != head) last = last->next;
                head = head->next;
                last->next = head;
                delete p;
                return;
            }
            prev->next = p->next;
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    } while (p != head);

    cout << "Value not found\n";
}

void search(int key) {
    if (!head) return;

    int pos = 1;
    Node* p = head;

    do {
        if (p->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    } while (p != head);

    cout << "Not found\n";
}

void display() {
    if (!head) { cout << "Empty\n"; return; }

    Node* p = head;

    cout << "List: ";
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);

    cout << endl;
}

int main() {
    int ch, x, key;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
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
