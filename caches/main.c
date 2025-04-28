#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "init.h"
#include "avg_mat.h"

int main(int argc, char **argv) {
    if (argc !=3) {
        // print to std error
        fprintf(stderr, "usage: %s row col\n", argv[0]);
        return 1;
    }

    // uncomment this for random data
    // srand(time(NULL));

    int r = atoi(argv[1]);
    int c = atoi(argv[2]);

    int *M = malloc(r * c * sizeof(int)); // heap not stack

    init(r, c, M);
    // round to one decimal place
    printf("%.1f\n", avgM(r, c, M));

    // clean up
    free(M);
    M = NULL;
}