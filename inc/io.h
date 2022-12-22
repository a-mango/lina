#ifndef IO_H
#define IO_H

#include <matrix.h>
#include <vector.h>


void lc_setup();

void mat_print(Matrix* const mat);

void vec_print(Vector* const vec);

void _v_col_print(Vector* const vec);
void _v_row_print(Vector* const vec);

#endif // IO_H