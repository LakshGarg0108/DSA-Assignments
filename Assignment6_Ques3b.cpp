#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

int sizeCircular(Node* head) {
    if (head == nullptr) return 0;

    int count = 0;
    Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } 
    while (temp != head);

    return count;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 5);
    insertEnd(head, 15);
    insertEnd(head, 25);
    insertEnd(head, 35);

    cout << "Size of Circular Linked List: " << sizeCircular(head);

    return 0;
}
