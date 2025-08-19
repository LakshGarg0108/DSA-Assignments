#include <stdio.h>

int main() {
    int choice;

    printf("MENU\n");
    printf("1. Reverse an Array\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose of a Matrix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int arr[100], n, i, temp;
        printf("Enter size of array: ");
        scanf("%d", &n);
        printf("Enter %d elements:\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (i = 0; i < n / 2; i++) {
            temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }

        printf("Reversed array:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    else if (choice == 2) {
        int a[10][10], b[10][10], result[10][10];
        int r1, c1, r2, c2;
        int i, j, k;

        printf("Enter rows and columns for Matrix A: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and columns for Matrix B: ");
        scanf("%d%d", &r2, &c2);

        if (c1 != r2) {
            printf("Matrix multiplication not possible. Columns of A must equal rows of B.\n");
        } else {
            printf("Enter elements of Matrix A:\n");
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                    scanf("%d", &a[i][j]);
                }
            }
            printf("Enter elements of Matrix B:\n");
            for (i = 0; i < r2; i++) {
                for (j = 0; j < c2; j++) {
                    scanf("%d", &b[i][j]);
                }
            }
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                    result[i][j] = 0;
                    for (k = 0; k < c1; k++) {
                        result[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            printf("Resultant Matrix:\n");
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
        }
    }
    else if (choice == 3) {
        int mat[10][10], trans[10][10];
        int rows, cols;
        int i, j;
        printf("Enter rows and columns of matrix: ");
        scanf("%d%d", &rows, &cols);
        printf("Enter elements of matrix:\n");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                trans[j][i] = mat[i][j];
            }
        }
        printf("Transpose of matrix:\n");
        for (i = 0; i < cols; i++) {
            for (j = 0; j < rows; j++) {
                printf("%d ", trans[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Invalid choice.\n");
    }
    return 0;
}

