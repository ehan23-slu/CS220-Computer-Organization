// scale the contents of a 2d matrix

#include <stdio.h>
#include <stdint.h>

void print_matrix(int64_t *mat, int64_t nrows, int64_t ncols) {
    for (int64_t row = 0; row < nrows; row++) {
        for (int64_t col = 0; col < ncols; col++) {
            printf("%ld ", *(mat + row*ncols + col));
        } 
        printf("\n");
    }
}

int main(void) {
    // declare a 3x2 matrix
    int64_t M[3][2] = {{1,2}, {3,4}, {5,6}};

    print_matrix(M, 3, 2);

    // print matrix
    for (int row = 0; row <3; row++) {
        for (int col = 0; col < 2; col++) {
            printf("%ld ", M[row][col]);
        }
        printf("\n");
    }
}