#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <matrix.h>
#include <io.h>


int main(int argc, char** argv) {
    printf("%s\n", "Hello Lina !");

    Matrix* m = mat_create(2, 2, 1.,2.,3.,4.);
    mat_print(m);
    
    return EXIT_SUCCESS;
}