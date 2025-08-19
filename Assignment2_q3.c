#include <stdio.h>

int findMissingLinear(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return size + 1;
}

int findMissingBinary(int arr[], int size) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid + 1) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }
    return left + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Linear Search Missing Number: %d\n", findMissingLinear(arr, size));
    printf("Binary Search Missing Number: %d\n", findMissingBinary(arr, size));

    return 0;
}

