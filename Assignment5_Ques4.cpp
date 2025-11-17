#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    Node *prev = nullptr, *curr = head, *next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node *head = nullptr, *tail = nullptr;
    int x;

    cout << "Enter elements (end with -1): ";
    while (cin >> x && x != -1) {
        Node* temp = new Node{x, nullptr};
        if (!head) head = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    head = reverseList(head);

    cout << "Reversed List: ";
    display(head);
}