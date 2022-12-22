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


Matrix* mat_inverse(const Matrix* mat);
Matrix* mat_add(const Matrix* m1, const Matrix* m2);
Matrix* mat_multiply(const Matrix* m1, const Matrix* m2);

#endif // MATRIX_H