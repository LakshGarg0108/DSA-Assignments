#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteAllKey(Node*& head, int key) {
    int count = 0;

    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* p = head;
    while (p && p->next) {
        if (p->next->data == key) {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
            count++;
        } else {
            p = p->next;
        }
    }

    cout << "Occurrences deleted = " << count << endl;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int x;

    cout << "Enter elements (end with -1): ";
    while (cin >> x && x != -1) {
        Node* temp = new Node{x, nullptr};
        if (!head) head = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    deleteAllKey(head, key);

    cout << "Final List: ";
    display(head);
}
