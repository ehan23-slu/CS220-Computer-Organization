#include <stdlib.h>
#include "init.h"

void init(int r, int c, int *M) {

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            int *p = M + row * c + col;
            *p = rand() % 1000;
        }
    }
}