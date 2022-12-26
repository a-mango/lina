#ifndef MATRIX_H
#define MATRIX_H

#include <types.h>
#include <stdlib.h>


typedef struct Matrix {
    uint     row_cnt;
    uint     col_cnt;
    double** data;
} Matrix;

// Constructors.
Matrix* mat_create(uint row_cnt, uint col_cnt, ...);
Matrix* mat_alloc(uint row_cnt, uint col_cnt);
void    mat_free(Matrix* mat);

// Copying.
Matrix* mat_copy(const Matrix* mat);

// Creation
Matrix* mat_square(uint size, ...);
Matrix* mat_identity(uint size);

// Operations.
Matrix* mat_transpose(const Matrix* mat);
Matrix* mat_add(const Matrix* m1, const Matrix* m2);
Matrix* mat_sub(const Matrix* m1, const Matrix* m2);
Matrix* mat_multiply(const Matrix* m1, const Matrix* m2);
Matrix* mat_divide(const Matrix* m1, const Matrix* m2);

// Scalar operations.
// Matrix* mat_scalar_add(const Matrix* mat, double scalar);
// Matrix* mat_scalar_sub(const Matrix* mat, double scalar);
// Matrix* mat_scalar_multiply(const Matrix* mat, double scalar);
// Matrix* mat_scalar_divide(const Matrix* mat, double scalar);

// 0-based indexing.
Matrix* mat_get_row(const Matrix* mat, uint row_idx);
Matrix* mat_get_col(const Matrix* mat, uint col_idx);
double  mat_get_entry(const Matrix* mat, size_t row_idx, size_t col_idx);

#endif // MATRIX_H