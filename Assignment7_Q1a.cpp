#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx])
                minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

int main() {
    int a[] = {50, 20, 40, 10, 60};
    int n = 5;

    selectionSort(a, n);

    cout << "Selection Sort Result: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
