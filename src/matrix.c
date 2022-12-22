#include <matrix.h>
#include <ops.h>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


Matrix* mat_create(uint row_cnt, uint col_cnt, ...) {
    Matrix* mat = mat_alloc(row_cnt, col_cnt);

    va_list args;
    va_start(args, col_cnt);

    for (uint i = 0; i < row_cnt; i++) {
        for (uint j = 0; j < row_cnt; j++) {
            mat->data[i][j] = va_arg(args, double);
        }
    }

    va_end(args);

    return mat;
}

Matrix* mat_alloc(uint row_cnt, uint col_cnt) {
    Matrix* mat = malloc(sizeof(Matrix));
    mat->row_cnt = row_cnt;
    mat->col_cnt = col_cnt;
    mat->data = (double**)calloc(mat->row_cnt, sizeof(double*));
    for (uint i = 0; i < mat->row_cnt; i++) {
        mat->data[i] = (double*)calloc(mat->col_cnt, sizeof(double));
    }

    return mat;
}

void mat_free(Matrix* mat) {
    for (uint i = 0; i < mat->row_cnt; i++)
        free(mat->data[i]);

    free(mat->data);
    free(mat);
}


void mat_transpose(Matrix* mat) {
    return;
}

void mat_inverse(Matrix* mat) {
    return;
}

Matrix* mat_add(const Matrix* m1, const Matrix* m2) {
    // Check if matrices are compatible.
    if (m1->row_cnt != m2->row_cnt || m1->col_cnt != m2->col_cnt) {
        fprintf(stderr, "Error: matrices are incompatible\nExiting...\n");
        exit(EXIT_FAILURE);
    }

    Matrix* mat = mat_create(m1->row_cnt, m1->col_cnt);

    for(size_t i = 0; i < m1->row_cnt; i++) {
        for(size_t j = 0; j < m1->col_cnt; j++) {
            mat->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return mat;
}

Matrix* mat_multiply(const Matrix* m1, const Matrix* m2) {
    return NULL;
}
