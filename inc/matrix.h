#ifndef MATRIX_H
#define MATRIX_H

typedef unsigned int uint;

typedef struct Matrix {
    uint     row_cnt;
    uint     col_cnt;
    double** data;
} Matrix;

Matrix* create_matrix(uint row_cnt, uint col_cnt, ...);

Matrix* matrix_alloc(uint row_cnt, uint col_cnt);
void    matrix_free(Matrix* const mat);

// Utils
void    print_matrix(Matrix* const mat);

#endif // MATRIX_H