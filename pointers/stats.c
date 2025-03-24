#include <stdio.h>
#include <stdlib.h>

/**
 * n is an input parameter
 * max is an output parameter
 * constant similar to final in java
 * 
 * modify stats so it does not return the mean, but passes
 * it back through an output parameter
 */
// pass int n for length
void stats(const double *vec, const int n, double *max, double *mean) { 
    // double vec [] is same with *vec
    double sum = 0;
    *max = *vec;
    // n = 0; since it's 'const' to n which means don't change in side of fucntion, 
    // we can't put n in lhs
    for (int i = 0; i < n; i++) {
        sum += *(vec + i); // vec[i] == *(vec + i)

        if (*(vec + i) > *max) {
            *max = *(vec + i);
        } 
    } *mean = sum/n;
    
}

// rewrite the stats funciton so it returns a struct
struct stats_t {
    double mean;
    double max;
};

struct stats_t stats2(const double *vec, const int n) {
    struct stats_t rv; // return value
    double sum = 0;
    rv.max = *vec; // since vec points to the first item
    for (int i = 0; i < n; i++) {
        sum += *(vec + i);

        if (*(vec + i) > rv.max) {
            rv.max = *(vec + i);
        }
    } 
    rv.mean = sum/n;
    return rv;
}

// stats3 returns a pointer to a struct
// dangling pointer
struct stats_t * stats3(const double *vec, const int n) {
    // allocate memory for the struct
    struct stats_t * rv = malloc(sizeof(struct stats_t)); // return value
    double sum = 0;

    (*rv).max = *vec; // since vec points to the first item 
    // rv->max == (*rv).max

    for (int i = 0; i < n; i++) {
        sum += *(vec + i);

        if (*(vec + i) > (*rv).max) {
            (*rv).max = *(vec + i);
        }
    } 
    rv->mean = sum/n;
    return rv; // copy the value once it is called
}

int main() {
    double grades[] = {99.1, 85.3, 72.9}; // 24 bytes
    double max = 0.0; // 8 bytes
    // double avg = stats(grades, 3, &max); // max is passed by value without * then modifying copy // we need &
    // printf("%.1f %f\n", avg, max);
    double avg;
    stats(grades, 3, &max, &avg);
    printf("%.1f %f\n", avg, max);

    struct stats_t v = stats2(grades, 3);
    // print values of v
    printf("Stats2 - Mean: %.1f, Max: %.1f\n", v.mean, v.max);

    // call stats3
    struct stats_t * s = stats3(grades, 3);
    // Study: write a statement to print the values in s
    printf("Stats3 - Mean: %.1f, Max: %.1f\n", (*s).mean, s->max);

    // Study: 
    // Q: what happens the memory that stats3 allocated?
    // A: This does not automatically deallocated.

    // Q: when does it get deallocated?
    // A; Once we call free(s); by free function, it will get deallocated.

}