#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

int main() {
    int a[] = {50, 20, 40, 10, 60};
    int n = 5;

    bubbleSort(a, n);

    cout << "Bubble Sort Result: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
