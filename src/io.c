#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#include <io.h>


void lc_setup() {
    setlocale(LC_ALL, "");
    fwide(stdout, 1);
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

void vec_print(Vector* const vec) {
    switch(vec->type) {
        case VEC_TYPE_COL:
            _v_col_print(vec);
            break;
        case VEC_TYPE_ROW:
            _v_row_print(vec);
            break;
        default:
            wprintf(L"Error while printing vector");
            break;
    }
}

void _v_col_print(Vector* const vec) {
    uint vec_display_width = 6;

    wchar_t* buffer_top = (wchar_t*)calloc(vec_display_width + 1, sizeof(wchar_t));
    wchar_t* buffer_bot = (wchar_t*)calloc(vec_display_width + 1, sizeof(wchar_t));
    wcsncat((buffer_top + 1), L"             ", vec_display_width - 1);
    wcsncat((buffer_bot + 1), L"             ", vec_display_width - 1);
    buffer_top[0] = 0x250c;
    buffer_top[vec_display_width] = 0x2510;
    buffer_bot[0] = 0x2514;
    buffer_bot[vec_display_width] = 0x2518;

    wprintf(L"%ls\n", buffer_top);
    for (uint i = 0; i < vec->size; i++) {
        wprintf(L"│ %*.1lf │\n", 3, vec->data[i]);
    }
    wprintf(L"%ls\n", buffer_bot);
    fflush(stdout);

    free(buffer_top);
    free(buffer_bot);
}

void _v_row_print(Vector* const vec) {
    wprintf(L"%s ", L"[");
    for (uint i = 0; i < vec->size; i++) {
        wprintf(L"%*.1lf ", 3, vec->data[i]);
    }
    wprintf(L"%ls\n", L"]");

    fflush(stdout);
}