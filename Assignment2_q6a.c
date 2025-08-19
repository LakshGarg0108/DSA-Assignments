#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row, col, val;
} Term;

typedef struct {
    int rows, cols, num;
    Term *data;
} Sparse;

void readSparse(Sparse *s) {
    printf("Enter rows, cols, and number of non-zero elements: ");
    scanf("%d %d %d", &s->rows, &s->cols, &s->num);

    s->data = (Term*)malloc(s->num * sizeof(Term));

    printf("Enter row col value:\n");
    for (int i = 0; i < s->num; i++)
        scanf("%d %d %d", &s->data[i].row, &s->data[i].col, &s->data[i].val);
}

void printSparse(Sparse s) {
    printf("\nRow Col Val\n");
    for (int i = 0; i < s.num; i++)
        printf("%3d %3d %3d\n", s.data[i].row, s.data[i].col, s.data[i].val);
}

Sparse transpose(Sparse s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.num = s.num;
    t.data = (Term*)malloc(t.num * sizeof(Term));

    for (int i = 0; i < s.num; i++) {
        t.data[i].row = s.data[i].col;
        t.data[i].col = s.data[i].row;
        t.data[i].val = s.data[i].val;
    }
    return t;
}

int main() {
    Sparse a, t;

    printf("Enter sparse matrix:\n");
    readSparse(&a);

    printf("\nOriginal matrix (triplet form):");
    printSparse(a);

    t = transpose(a);
    printf("\nTranspose (triplet form):");
    printSparse(t);

    free(a.data);
    free(t.data);

    return 0;
}

