#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << arr[top--] << " popped.\n";
    }

    void peek() {
        if (!isEmpty())
            cout << "Top element: " << arr[top] << endl;
        else
            cout << "Stack is empty.\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; s.push(value); break;
            case 2: s.pop(); break;
            case 3: cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n"); break;
            case 4: cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n"); break;
            case 5: s.display(); break;
            case 6: s.peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}