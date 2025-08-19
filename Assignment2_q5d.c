#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *A;
} UpperTriangular;

void set(UpperTriangular *u, int i, int j, int x) {
    if (i <= j)
        u->A[j * (j - 1) / 2 + (i - 1)] = x;
}

int get(UpperTriangular u, int i, int j) {
    if (i <= j)
        return u.A[j * (j - 1) / 2 + (i - 1)];
    return 0;
}

void display(UpperTriangular u) {
    for (int i = 1; i <= u.n; i++) {
        for (int j = 1; j <= u.n; j++) {
            printf("%d ", get(u, i, j));
        }
        printf("\n");
    }
}

int main() {
    UpperTriangular u;
    printf("Enter dimension: ");
    scanf("%d", &u.n);

    u.A = (int*)malloc(u.n * (u.n + 1) / 2 * sizeof(int));

    printf("Enter elements row by row:\n");
    for (int i = 1; i <= u.n; i++) {
        for (int j = 1; j <= u.n; j++) {
            int x;
            scanf("%d", &x);
            set(&u, i, j, x);
        }
    }

    printf("Matrix:\n");
    display(u);

    free(u.A);
    return 0;
}

