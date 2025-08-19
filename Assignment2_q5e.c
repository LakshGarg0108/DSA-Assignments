
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *A;
} Symmetric;

void set(Symmetric *s, int i, int j, int x) {
    if (i >= j)
        s->A[i * (i - 1) / 2 + (j - 1)] = x;
}

int get(Symmetric s, int i, int j) {
    if (i >= j)
        return s.A[i * (i - 1) / 2 + (j - 1)];
    else
        return s.A[j * (j - 1) / 2 + (i - 1)];
}

void display(Symmetric s) {
    for (int i = 1; i <= s.n; i++) {
        for (int j = 1; j <= s.n; j++) {
            printf("%d ", get(s, i, j));
        }
        printf("\n");
    }
}

int main() {
    Symmetric s;
    printf("Enter dimension: ");
    scanf("%d", &s.n);

    s.A = (int*)malloc(s.n * (s.n + 1) / 2 * sizeof(int));

    printf("Enter elements row by row:\n");
    for (int i = 1; i <= s.n; i++) {
        for (int j = 1; j <= s.n; j++) {
            int x;
            scanf("%d", &x);
            set(&s, i, j, x);
        }
    }

    printf("Matrix:\n");
    display(s);

    free(s.A);
    return 0;
}

