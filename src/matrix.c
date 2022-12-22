#include <matrix.h>

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
