#include <iostream>
using namespace std;

#define MAX 100

class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (rear + 1) % MAX == front; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular Queue Full!\n";
            return;
        }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % MAX;

        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Empty!\n";
            return;
        }
        cout << arr[front] << " dequeued\n";

        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void peek() {
        if (isEmpty()) cout << "Empty\n";
        else cout << "Front = " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty\n";
            return;
        }
        cout << "Circular Queue: ";

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, val;

    while (true) {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
            case 2: cq.dequeue(); break;
            case 3: cout << (cq.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 4: cout << (cq.isFull() ? "Full\n" : "Not Full\n"); break;
            case 5: cq.display(); break;
            case 6: cq.peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
