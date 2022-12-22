#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include <matrix.h>
#include <io.h>


int main(int argc, char** argv) {
    lc_setup();

    wprintf(L"%s\n\n", "Hello Lina !");

    Matrix* m = mat_create(3, 3, 1.,2.,3.,4.,5.,6., 7., 8., 9.);
    mat_print(m);
    mat_free(m);
    return EXIT_SUCCESS;
}