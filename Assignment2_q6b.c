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

Sparse addSparse(Sparse a, Sparse b) {
    Sparse c;
    if (a.rows != b.rows || a.cols != b.cols) {
        c.num = -1;
        c.data = NULL;
        return c;
    }

    c.rows = a.rows;
    c.cols = a.cols;
    c.data = (Term*)malloc((a.num + b.num) * sizeof(Term));
    c.num = 0;

    int i = 0, j = 0;
    while (i < a.num && j < b.num) {
        if (a.data[i].row < b.data[j].row ||
           (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            c.data[c.num++] = a.data[i++];
        } else if (b.data[j].row < a.data[i].row ||
                  (b.data[j].row == a.data[i].row && b.data[j].col < a.data[i].col)) {
            c.data[c.num++] = b.data[j++];
        } else {
            int sum = a.data[i].val + b.data[j].val;
            if (sum != 0) {
                c.data[c.num].row = a.data[i].row;
                c.data[c.num].col = a.data[i].col;
                c.data[c.num].val = sum;
                c.num++;
            }
            i++; j++;
        }
    }

    while (i < a.num) c.data[c.num++] = a.data[i++];
    while (j < b.num) c.data[c.num++] = b.data[j++];

    return c;
}

int main() {
    Sparse a, b, c;

    printf("Enter first sparse matrix:\n");
    readSparse(&a);

    printf("Enter second sparse matrix:\n");
    readSparse(&b);

    printf("\nFirst Matrix:");
    printSparse(a);
    printf("\nSecond Matrix:");
    printSparse(b);

    c = addSparse(a, b);

    if (c.num == -1)
        printf("\nAddition not possible (dimension mismatch).\n");
    else {
        printf("\nResultant Matrix after Addition:");
        printSparse(c);
        free(c.data);
    }

    free(a.data);
    free(b.data);

    return 0;
}

