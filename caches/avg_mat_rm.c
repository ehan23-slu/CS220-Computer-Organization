#include "avg_mat.h"

double avgM(int r, int c, int *M) {
    long sum = 0;
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            sum += *(M + row*c + col);
        }
    }

    return (double) sum / (r*c);
}