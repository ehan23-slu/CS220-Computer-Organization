#include "tabulate.h"

/**
 * tabulate computes average, maximum, and minimum values of 
 * an array of doubles
 * 
 * vec - pointer to array of double 
 * n - number of elements in vec
 * stats - pointer to stats_t struct that stores the results
 */
void tabulate(const double *vec, const int n, stats_t *stats) {
    double sum = 0;
    // initialize max and min with first element of array
    stats->max = vec[0];
    stats->min = vec[0];

    // iterate through the array to calculate average
    // and find mininum and maximum value
    for (int i= 0; i < n; i++) {
        sum += vec[i];

        // update max if the current value is greater than the current max
        if (vec[i] > stats->max) {
            stats->max = vec[i];
        }
        // update min if the current value is less than the current min
        if (vec[i] < stats->min) {
            stats->min = vec[i];
        }
    } 
    // compute the average
    stats->average = sum/n;
}
