#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// TODO: edit to take value from user and add them

int64_t array_sum(int64_t vec[], int64_t n);

int main(void) {
    int64_t data[] = {5, 7, 12, 0, 6};

    int64_t res = array_sum(data, 5);
    printf("The sum is: %ld\n", res);
}