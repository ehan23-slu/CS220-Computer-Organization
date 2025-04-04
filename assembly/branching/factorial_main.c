#include <stdio.h>
#include <stdlib.h>

long factorial (long n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    printf("%ld\n", factorial(atol(argv[1])));
}