#include <stdio.h>

// Define the stats_t struct
struct stats_t {
    double average;
    double max;
    double min;
};

/**
 * vec - a pointer to the first element in an array of doubles
 * n - the number of elements in the vec array
 * stats - a struct with fields for average, max, and min
 * 
 * This function calculates the average, maximum, 
 * and minimum of the numbers in vec
 */
void tabulate(const double *vec, const int n, struct stats_t *stats) {
    // initialize variables
    double sum = 0.0;
    stats->max = vec[0];
    stats->min = vec[0];

    // loop through vec to calculate average
    // and find mininum and maximum value
    for (int i = 0; i < n; i++) {
        // add each element of vec
        sum += vec[i];

        // Note: "stats->" and (*stats)." are identical statements
        if (vec[i] > stats->max) {
            // update max if the current element is greater than
            // current max
            stats->max = vec[i];
        }

        if (vec[i] < stats->min) {
            // update min if the current element is less than
            // current min
            (*stats).min = vec[i];
        }
    }

    stats->average = sum / n;
}

int main() {
    // declare variable n to read the number of elements from the user
    int n;

    // If n is less than 1 or bigger than 50, prints ERROR\n 
    // (no spaces or anythingthing else) and returns 1
    if (scanf("%d", &n) != 1 || n < 1 || n > 50) {
        printf("ERROR\n");
        return 1;
    }

    // If n is valid, reads n doubles from standard input
    double vec[50];
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &vec[i]) != 1) {
            printf("ERROR\n");
            return 1;
        }
    }

    // declare struct stats
    struct stats_t stats;
    tabulate(vec, n, &stats);

    // print the results in given format
    printf("Average: %.2f\n", stats.average);
    printf("Maximum: %.6f\n", stats.max);
    printf("Minimum: %.6f\n", stats.min);

    return 0;
}