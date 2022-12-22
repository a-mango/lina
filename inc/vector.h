#ifndef LINA_VECTOR_H
#define LINA_VECTOR_H

#include <types.h>


typedef struct Vector {
    uint size;
    double* data;
} Vector;

Vector* vec_create(uint size, ...);
Vector* vec_alloc(uint size);
void    vec_free(Vector* vec);

#endif // LINA_VECTOR_H