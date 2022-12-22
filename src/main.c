#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include <matrix.h>
#include <vector.h>
#include <io.h>
#include <ops.h>


int main(int argc, char** argv) {
    lc_setup();

    wprintf(L"%s\n\n", "Hello Lina !");

    Matrix* m = mat_create(3, 3, 1.,2.,3.,4.,5.,6., 7., 8., 9.);
    mat_print(m);
    mat_free(m);

    Vector* v1 = vec_create(VEC_TYPE_COL, 3, 4., 5., 6.);
    Vector* v2 = vec_create(VEC_TYPE_ROW, 3, 1., 2., 3.);
    vec_print(v1);
    vec_print(v2);

    double result = scalar_product(v1->data, v2->data, 3);

    wprintf(L"%lf", result);

    vec_free(v1);
    vec_free(v2);

    return EXIT_SUCCESS;
}