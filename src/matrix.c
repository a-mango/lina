#include <matrix.h>

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>


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

void mat_print(Matrix* const mat) {
    uint mat_display_width = mat->col_cnt * 4 + 2;

    wchar_t* buffer_top = (wchar_t*)calloc(mat_display_width + 1, sizeof(wchar_t));
    wchar_t* buffer_bot = (wchar_t*)calloc(mat_display_width + 1, sizeof(wchar_t));
    wcsncat((buffer_top + 1), L"              ", mat_display_width - 1);
    wcsncat((buffer_bot + 1), L"              ", mat_display_width - 1);
    buffer_top[0] = 0x250c;
    buffer_top[mat_display_width] = 0x2510;
    buffer_bot[0] = 0x2514;
    buffer_bot[mat_display_width] = 0x2518;

    wprintf(L"%ls\n", buffer_top);
    for (uint i = 0; i < mat->row_cnt; i++) {
        wprintf(L"│ ");
        for (uint j = 0; j < mat->col_cnt; j++) {
            wprintf(L"%*.1lf ", 3, mat->data[i][j]);
        }
        wprintf(L"│\n");
    }
    wprintf(L"%ls\n", buffer_bot);
    fflush(stdout);

    free(buffer_top);
    free(buffer_bot);
}
