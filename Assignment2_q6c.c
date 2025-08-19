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

Sparse multiplySparse(Sparse a, Sparse b) {
    Sparse c;
    if (a.cols != b.rows) {
        c.num = -1;
        c.data = NULL;
        return c;
    }

    c.rows = a.rows;
    c.cols = b.cols;
    c.data = (Term*)malloc((a.num * b.num) * sizeof(Term)); // worst-case size
    c.num = 0;

    Sparse bt = transpose(b);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < bt.rows; j++) {
            int sum = 0;
            for (int p = 0; p < a.num; p++) {
                if (a.data[p].row == i) {
                    for (int q = 0; q < bt.num; q++) {
                        if (bt.data[q].row == j && a.data[p].col == bt.data[q].col) {
                            sum += a.data[p].val * bt.data[q].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                c.data[c.num].row = i;
                c.data[c.num].col = j;
                c.data[c.num].val = sum;
                c.num++;
            }
        }
    }

    free(bt.data);
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

    c = multiplySparse(a, b);

    if (c.num == -1)
        printf("\nMultiplication not possible (dimension mismatch).\n");
    else {
        printf("\nResultant Matrix after Multiplication:");
        printSparse(c);
        free(c.data);
    }

    free(a.data);
    free(b.data);

    return 0;
}

