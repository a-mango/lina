#include <ops.h>


#include <stdlib.h>
#include <stdio.h>

double scalar_product(const double* row, const double* col, size_t n) {
    double result = 0;

    for(uint i = 0; i < n; i++) {
        result += row[i] * col[i];
    }

    return result;
}
 