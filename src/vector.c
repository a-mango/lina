#include <vector.h>

#include <stdlib.h>
#include <stdarg.h>
// #include <stdio.h>

Vector* vec_create(VectorType type, uint size, ...) {
    Vector* vec = vec_alloc(size);
    vec->type = type;
    
    va_list args;
    va_start(args, size);

    for (uint i = 0; i < size; i++) {
        vec->data[i] = va_arg(args, double);
    }

    va_end(args);

    return vec;
}

Vector* vec_alloc(uint size) {
    Vector* vec = (Vector*)malloc(sizeof(Vector));
    vec->size = size;
    vec->data = (double*)calloc(size, sizeof(double));

    return vec;
}

void vec_free(Vector* vec) {
    free(vec->data);
    free(vec);
}