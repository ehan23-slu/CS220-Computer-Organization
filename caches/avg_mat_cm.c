#include "avg_mat.h"

double avgM(int r, int c, int *M) {
    long sum = 0;
    for (int row = 0; row < c; row++) {
        for (int col = 0; col < r; col++) {
            sum += *(M + col*r + row);
        }
    }

    return (double) sum / (r*c);
}