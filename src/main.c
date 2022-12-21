#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>
#include <display.h>

int main(int argc, char** argv) {
    printf("%s\n", "Hello Lina !");
    Matrix m = {2, 2, 1, 2, 3, 4};
    print_matrix(&m);
    return EXIT_SUCCESS;
}
