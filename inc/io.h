#ifndef IO_H
#define IO_H

#include <matrix.h>
#include <vector.h>


void lc_setup();

void mat_print(const Matrix* mat);
void vec_print(const Vector* vec);

void _v_col_print(const Vector* vec);
void _v_row_print(const Vector* vec);

void print(const char* msg);
void log_msg(const char* msg);
void log_err(const char* msg);

#endif // IO_H