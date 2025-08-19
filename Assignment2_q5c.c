#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *A;
} LowerTriangular;

void set(LowerTriangular *l, int i, int j, int x) {
    if (i >= j)
        l->A[i * (i - 1) / 2 + (j - 1)] = x;
}

int get(LowerTriangular l, int i, int j) {
    if (i >= j)
        return l.A[i * (i - 1) / 2 + (j - 1)];
    return 0;
}

void display(LowerTriangular l) {
    for (int i = 1; i <= l.n; i++) {
        for (int j = 1; j <= l.n; j++) {
            printf("%d ", get(l, i, j));
        }
        printf("\n");
    }
}

int main() {
    LowerTriangular l;
    printf("Enter dimension: ");
    scanf("%d", &l.n);

    l.A = (int*)malloc(l.n * (l.n + 1) / 2 * sizeof(int));

    printf("Enter elements row by row:\n");
    for (int i = 1; i <= l.n; i++) {
        for (int j = 1; j <= l.n; j++) {
            int x;
            scanf("%d", &x);
            set(&l, i, j, x);
        }
    }

    printf("Matrix:\n");
    display(l);

    free(l.A);
    return 0;
}

