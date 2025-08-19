#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *A;
} Diagonal;

void set(Diagonal *d, int i, int j, int x) {
    if (i == j)
        d->A[i - 1] = x;
}

int get(Diagonal d, int i, int j) {
    if (i == j)
        return d.A[i - 1];
    return 0;
}

void display(Diagonal d) {
    for (int i = 1; i <= d.n; i++) {
        for (int j = 1; j <= d.n; j++) {
            if (i == j)
                printf("%d ", d.A[i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    Diagonal d;
    printf("Enter dimension: ");
    scanf("%d", &d.n);

    d.A = (int*)malloc(d.n * sizeof(int));

    printf("Enter diagonal elements:\n");
    for (int i = 1; i <= d.n; i++) {
        int x;
        scanf("%d", &x);
        set(&d, i, i, x);
    }

    printf("Matrix:\n");
    display(d);

    free(d.A);
    return 0;
}

