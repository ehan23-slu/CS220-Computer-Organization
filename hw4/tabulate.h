// struct stats_t stores results of 
// average, maximum, and minimum value
typedef struct {
    double average;
    double max;
    double min;
} stats_t;

/**
 * tabulate computes average, maximum, and minimum values of 
 * an array of doubles
 * 
 * vec - pointer to array of double 
 * n - number of elements in vec
 * stats - pointer to stats_t struct that stores the results
 * 
 * Precondition:
 * array vec must have at least one element
 */
void tabulate(const double *vec, const int n, stats_t *stats);