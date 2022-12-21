#include <stdio.h>

#include <display.h>

void print_matrix(Matrix* const m) {
    for(int i = 0; i < m->row_cnt; i++) {
        for(int j = 0; j < m->col_cnt; j++) {
            printf("%.2lf", m->data[i * sizeof(double)][j * sizeof(double)]);
        }
    }
}
