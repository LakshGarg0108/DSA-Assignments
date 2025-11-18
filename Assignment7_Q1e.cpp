#include <iostream>
using namespace std;

int partitionArray(int a[], int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot)
            swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partitionArray(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int a[] = {50, 20, 40, 10, 60};
    int n = 5;

    quickSort(a, 0, n - 1);

    cout << "Quick Sort Result: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
