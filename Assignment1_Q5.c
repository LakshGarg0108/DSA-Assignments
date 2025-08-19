#include <stdio.h>

int main() {
    int rows, cols;
    int i, j;
    int arr[5][5];

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nSum of each row:\n");
    for (i = 0; i < rows; i++) {
        int rowSum = 0;
        for (j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, rowSum);
    }

    printf("\nSum of each column:\n");
    for (j = 0; j < cols; j++) {
        int colSum = 0;
        for (i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        printf("Column %d sum = %d\n", j + 1, colSum);
    }

    return 0;
}

