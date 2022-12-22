#ifndef LINA_VECTOR_H
#define LINA_VECTOR_H

#include <types.h>

typedef enum VectorType {
    VEC_TYPE_COL,
    VEC_TYPE_ROW,
} VectorType;

typedef struct Vector {
    VectorType  type;
    uint        size;
    double*     data;
} Vector;

Vector* vec_create(VectorType type, uint size, ...);
Vector* vec_alloc(uint size);
void    vec_free(Vector* vec);

#endif // LINA_VECTOR_H