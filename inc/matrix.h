#ifndef MATRIX_H
#define MATRIX_H

typedef unsigned int uint;

typedef struct Matrix {
    uint     row_cnt;
    uint     col_cnt;
    double** data;
} Matrix;

Matrix* mat_create(uint row_cnt, uint col_cnt, ...);

Matrix* mat_alloc(uint row_cnt, uint col_cnt);
void    mat_free(Matrix* mat);

// Utils
void    mat_print(Matrix* const mat);

#endif // MATRIX_H