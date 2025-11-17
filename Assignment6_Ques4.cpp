#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
};

Node* head = nullptr;

void insertEnd(char ch) {
    Node* newNode = new Node{ch, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome(Node* head) {
    if (!head) return true;

    Node *left = head, *right = head;

    while (right->next)
        right = right->next;

    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter characters for the doubly linked list: ";
    cin >> s;

    for (char c : s)
        insertEnd(c);

    if (isPalindrome(head))
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is NOT a palindrome.\n";

    return 0;
}
