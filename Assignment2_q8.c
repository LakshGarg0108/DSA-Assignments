#include <stdio.h>

int main() {
    int n, i, j, count = 0, isDistinct;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        int Distinct = 1;
        for (j = 0; j < i; j++) { 
            if (arr[i] == arr[j]) {
                Distinct = 0;
                break;
            }
        }
        if (Distinct) {
            count++;
        }
    }

    printf("Total number of distinct elements: %d\n", count);

    return 0;
}

