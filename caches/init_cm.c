#include <stdlib.h>
#include "init.h"

void init(int r, int c, int *M) {
    for (int row = 0; row < c; row++) {
        for (int col = 0; col < r; col++) {
            int *p = M + col*r + row;
            *p = rand() % 1000;
        }
    }
}