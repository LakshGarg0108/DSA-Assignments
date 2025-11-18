#include <iostream>
using namespace std;

void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void minHeapify(int a[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] < a[smallest])
        smallest = l;

    if (r < n && a[r] < a[smallest])
        smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

void heapSortIncreasing(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

void heapSortDecreasing(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }
}

int main() {
    int a[] = {40, 10, 30, 80, 50};
    int n = 5;

    cout << "Original array: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    heapSortIncreasing(a, n);
    cout << "Heap Sort (Increasing): ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int b[] = {40, 10, 30, 80, 50};
    heapSortDecreasing(b, n);
    cout << "Heap Sort (Decreasing): ";
    for (int x : b) cout << x << " ";

    return 0;
}
