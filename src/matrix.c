#include <matrix.h>
#include <ops.h>
#include <io.h>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


#define ERR_MAT_ALLOC_MSG "Error while allocating memory for matrix."
#define ERR_MAT_DATA_ALLOC_MSG "Error while allocating memory for matrix data."

Matrix* mat_create(uint row_cnt, uint col_cnt, ...) {
    Matrix* mat = mat_alloc(row_cnt, col_cnt);

    va_list args;
    va_start(args, col_cnt);

    for (size_t i = 0; i < row_cnt; ++i) {
        for (size_t j = 0; j < row_cnt; ++j) {
            mat->data[i][j] = va_arg(args, double);
        }
    }

    va_end(args);

    return mat;
}

Matrix* mat_alloc(uint row_cnt, uint col_cnt) {
    Matrix* mat = malloc(sizeof(Matrix));
    if (mat == NULL) {
        log_err(ERR_MAT_ALLOC_MSG);
        exit(EXIT_FAILURE);
    }

    mat->row_cnt = row_cnt;
    mat->col_cnt = col_cnt;

    mat->data = (double**)calloc(mat->row_cnt, sizeof(double*));
    if (mat->data == NULL) {
        log_err(ERR_MAT_DATA_ALLOC_MSG);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < mat->row_cnt; ++i) {
        mat->data[i] = (double*)calloc(mat->col_cnt, sizeof(double));
        if (mat->data[i] == NULL) {
            log_err(ERR_MAT_DATA_ALLOC_MSG);
            exit(EXIT_FAILURE);
        }
    }

    return mat;
}

void mat_free(Matrix* mat) {
    for (size_t i = 0; i < mat->row_cnt; ++i)
        free(mat->data[i]);

    free(mat->data);
    free(mat);
}

// Copying.
Matrix* mat_copy(const Matrix* mat) {
    Matrix* mat_copy = mat_alloc(mat->row_cnt, mat->col_cnt);
    memcpy(mat_copy->data, mat->data, mat->row_cnt * mat->col_cnt * sizeof(double));
    return mat_copy;
}

// Creation
Matrix* mat_square(uint size, ...) {
    Matrix* mat = mat_alloc(size, size);

    va_list args;
    va_start(args, size);

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            mat->data[i][j] = va_arg(args, double);
        }
    }

    va_end(args);

    return mat;
}

Matrix* mat_identity(uint size);

Matrix* mat_transpose(const Matrix* mat) {
    Matrix* mat_t = mat_alloc(mat->col_cnt, mat->row_cnt);
    // Invert rows and columns.
    for (size_t i = 0; i < mat->row_cnt; ++i) {
        for (size_t j = 0; j < mat->col_cnt; ++j) {
            mat_t->data[j][i] = mat->data[i][j];
        }
    }

    return mat_t;
}

Matrix* mat_add(const Matrix* m1, const Matrix* m2) {
    // Check if matrices are compatible.
    if (m1->row_cnt != m2->row_cnt || m1->col_cnt != m2->col_cnt) {
        fprintf(stderr, "Error: matrices are incompatible\nExiting...\n");
        exit(EXIT_FAILURE);
    }

    Matrix* mat = mat_create(m1->row_cnt, m1->col_cnt);

    for (size_t i = 0; i < m1->row_cnt; ++i) {
        for (size_t j = 0; j < m1->col_cnt; ++j) {
            mat->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return mat;
}

Matrix* mat_sub(const Matrix* m1, const Matrix* m2) {
    // Check if matrices are compatible.
    if (m1->row_cnt != m2->row_cnt || m1->col_cnt != m2->col_cnt) {
        fprintf(stderr, "Error: matrices are incompatible\nExiting...\n");
        exit(EXIT_FAILURE);
    }

    Matrix* mat = mat_create(m1->row_cnt, m1->col_cnt);

    for (size_t i = 0; i < m1->row_cnt; ++i) {
        for (size_t j = 0; j < m1->col_cnt; ++j) {
            mat->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }

    return mat;
}

Matrix* mat_multiply(const Matrix* m1, const Matrix* m2) {
    // Check if matrices are compatible.
    if (m1->col_cnt != m2->row_cnt) {
        fprintf(stderr, "Error: matrices are incompatible\nExiting...\n");
        exit(EXIT_FAILURE);
    }

    Matrix* m2_t = mat_transpose(m2);
    Matrix* res = mat_create(m1->row_cnt, m2->col_cnt);

    // Multiply matrices.
    for (size_t i = 0; i < m1->row_cnt; ++i) {
        for (size_t j = 0; j < m2->col_cnt; ++j) {
            res->data[i][j] = scalar_product(m1->data[i], m2_t->data[j], m1->col_cnt);
        }
    }

    free(m2_t);

    return res;
}

Matrix* mat_divide(const Matrix* m1, const Matrix* m2) {
    // Check if matrices are compatible.
    if (m1->row_cnt != m2->row_cnt || m1->col_cnt != m2->col_cnt) {
        fprintf(stderr, "Error: matrices are incompatible\nExiting...\n");
        exit(EXIT_FAILURE);
    }

    Matrix* mat = mat_create(m1->row_cnt, m1->col_cnt);

    for (size_t i = 0; i < m1->row_cnt; ++i) {
        for (size_t j = 0; j < m1->col_cnt; ++j) {
            mat->data[i][j] = m1->data[i][j] / m2->data[i][j];
        }
    }

    return mat;
}

Matrix* mat_get_row(const Matrix* mat, uint row_idx) {
    Matrix* row = mat_alloc(1, mat->col_cnt);
    for (size_t i = 0; i < mat->col_cnt; ++i) {
        row->data[0][i] = mat->data[row_idx][i];
    }

    return row;
}

Matrix* mat_get_col(const Matrix* mat, uint col_idx) {
    Matrix* col = mat_alloc(mat->row_cnt, 1);
    for (size_t i = 0; i < mat->row_cnt; ++i) {
        col->data[i][0] = mat->data[i][col_idx];
    }

    return col;
}

double mat_get_entry(const Matrix* mat, size_t row_idx, size_t col_idx) {
    return mat->data[row_idx][col_idx];
}