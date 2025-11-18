#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIdx = left, maxIdx = left;

        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIdx]) minIdx = i;
            if (a[i] > a[maxIdx]) maxIdx = i;
        }

        swap(a[left], a[minIdx]);

        if (maxIdx == left)
            maxIdx = minIdx;

        swap(a[right], a[maxIdx]);

        left++;
        right--;
    }
}

int main() {
    int a[] = {40, 10, 70, 20, 60, 30, 50};
    int n = 7;

    improvedSelectionSort(a, n);

    cout << "Improved Selection Sort Result: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
