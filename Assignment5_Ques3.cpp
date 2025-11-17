#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *head = nullptr, *tail = nullptr;
    int x;

    cout << "Enter elements (end with -1): ";
    while (cin >> x && x != -1) {
        Node* temp = new Node{x, nullptr};
        if (!head) head = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle = " << slow->data;
}