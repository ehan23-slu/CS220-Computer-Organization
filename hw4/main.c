#include <stdio.h>
#include <stdlib.h>
#include "tabulate.h"

/**
 * main funciton reads numbers from the command line, storing them in
 * dynamically allocated array. Also, it computes average, maximum, 
 * and minimum using the tabulate function
 * 
 * argc - number of command line arguments
 * argv - array of command line argument strings
 */
int main(int argc, char *argv[]) {
    // check if numbers are provided through command line
    if (argc < 2) {
        printf("Error: no numbers provided.");
        return 1;
    }

    // number of input
    int n = argc - 1;
    // dynamically allocate memory for the numbers
    double *vec = (double *) malloc(n * sizeof(double));
    if (vec == NULL) {
        return 1;
    }

    // convert command-line arguments to double and put in the array
    for (int i = 0; i < n; i++) {
        vec[i] = atof(argv[i + 1]);
    }

    stats_t stats;
    // call tabulate function to compute
    tabulate(vec, n, &stats);

    // print average, max, min
    printf("Average: %.2f\n", stats.average);
    printf("Maximum: %.6f\n", stats.max);
    printf("Minimum: %.6f\n", stats.min);

    // free dynamically allocated memory
    free(vec);

    return 0;
}