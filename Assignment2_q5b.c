#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *A;
} TriDiagonal;

void set(TriDiagonal *t, int i, int j, int x) {
    if (i - j == 1)
        t->A[i - 2] = x;
    else if (i - j == 0)
        t->A[t->n - 1 + (i - 1)] = x;         
    else if (i - j == -1)
        t->A[2 * t->n - 1 + (i - 1)] = x;      
}

int get(TriDiagonal t, int i, int j) {
    if (i - j == 1)
        return t.A[i - 2];
    else if (i - j == 0)
        return t.A[t.n - 1 + (i - 1)];
    else if (i - j == -1)
        return t.A[2 * t.n - 1 + (i - 1)];
    else
        return 0;
}

void display(TriDiagonal t) {
    for (int i = 1; i <= t.n; i++) {
        for (int j = 1; j <= t.n; j++) {
            printf("%d ", get(t, i, j));
        }
        printf("\n");
    }
}

int main() {
    TriDiagonal t;
    printf("Enter dimension: ");
    scanf("%d", &t.n);

    t.A = (int*)malloc((3 * t.n - 2) * sizeof(int));

    printf("Enter tri-diagonal elements:\n");
    for (int i = 1; i <= t.n; i++) {
        for (int j = 1; j <= t.n; j++) {
            int x;
            scanf("%d", &x);
            set(&t, i, j, x);
        }
    }

    printf("Matrix:\n");
    display(t);

    free(t.A);
    return 0;
}

