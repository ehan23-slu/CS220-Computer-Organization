#include <stdio.h>

int main() {
    float z = 23.25;
    int *x = (int *) &z; // type matching

    printf("%X\n", *x);
    printf("%032b\n", *x);
}