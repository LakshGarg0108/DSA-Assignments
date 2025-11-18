#include <iostream>
using namespace std;

#define MAX 100
int heap[MAX];
int heapSize = 0;

void insert(int x) {
    heapSize++;
    heap[heapSize] = x;

    int i = heapSize;
    while (i > 1 && heap[i/2] < heap[i]) {
        swap(heap[i], heap[i/2]);
        i /= 2;
    }
}

int deleteMax() {
    if (heapSize == 0) {
        cout << "Priority Queue is empty!\n";
        return -1;
    }

    int maxVal = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;

    int i = 1;
    while (true) {
        int largest = i;
        int left = 2*i, right = 2*i+1;

        if (left <= heapSize && heap[left] > heap[largest])
            largest = left;

        if (right <= heapSize && heap[right] > heap[largest])
            largest = right;

        if (largest == i) break;

        swap(heap[i], heap[largest]);
        i = largest;
    }

    return maxVal;
}

int getMax() {
    if (heapSize == 0) return -1;
    return heap[1];
}

void display() {
    if (heapSize == 0) {
        cout << "Priority Queue is empty!\n";
        return;
    }
    cout << "Priority Queue (Heap): ";
    for (int i = 1; i <= heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    insert(40);
    insert(20);
    insert(50);
    insert(10);
    insert(60);

    display();

    cout << "Max element: " << getMax() << endl;

    cout << "Deleting max: " << deleteMax() << endl;
    display();

    return 0;
}
