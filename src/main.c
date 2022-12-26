#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include <matrix.h>
#include <vector.h>
#include <io.h>
#include <ops.h>


int main(int argc, char** argv) {
    lc_setup();

    print("Hello Lina !");
    print("Version 0.0.1\n");

    Matrix* m1 = mat_create(3, 3, 1.,2.,3.,4.,5.,6., 7., 8., 9.);
    Matrix* m2 = mat_create(3, 3, -1.,2.,-3.,-4.,-5.,-6., -7., -8., -9.);

    mat_print(m1);
    mat_print(m2);

    Matrix* m3 = mat_add(m1, m2);

    mat_print(m3);

    // Tryout row and column extraction.
    Matrix* m4 = mat_get_row(m1, 1);
    Matrix* m5 = mat_get_col(m1, 1);
    mat_print(m4);
    mat_print(m5);

    mat_free(m1);
    mat_free(m2);
    mat_free(m3);
    mat_free(m4);
    mat_free(m5);

    log_msg("End of program");
    log_err("Sample error");
    // Vector* v1 = vec_create(VEC_TYPE_COL, 3, 4., 5., 6.);
    // Vector* v2 = vec_create(VEC_TYPE_ROW, 3, 1., 2., 3.);
    // vec_print(v1);
    // vec_print(v2);

    // double result = scalar_product(v1->data, v2->data, 3);

    // wprintf(L"%lf", result);

    // vec_free(v1);
    // vec_free(v2);

    return EXIT_SUCCESS;
}