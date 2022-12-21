#ifndef MATRIX_H
#define MATRIX_H

typedef unsigned int uint;

typedef struct Matrix {
    uint     row_cnt;
    uint     col_cnt;
    double** data;
} Matrix;

Matrix* create_matrix(uint row_cnt, uint col_cnt);

#endif // MATRIX_H