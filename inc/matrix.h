#ifndef MATRIX_H
#define MATRIX_H

#include <types.h>


typedef struct Matrix {
    uint     row_cnt;
    uint     col_cnt;
    double** data;
} Matrix;

Matrix* mat_create(uint row_cnt, uint col_cnt, ...);
Matrix* mat_alloc(uint row_cnt, uint col_cnt);
void    mat_free(Matrix* mat);

// Utilities.
Matrix* mat_transpose(const Matrix* mat);
Matrix* mat_add(const Matrix* m1, const Matrix* m2);
Matrix* mat_sub(const Matrix* m1, const Matrix* m2);
Matrix* mat_multiply(const Matrix* m1, const Matrix* m2);

// 0-based indexing.
Matrix* mat_get_row(const Matrix* mat, uint row_idx);
Matrix* mat_get_col(const Matrix* mat, uint col_idx);

#endif // MATRIX_H