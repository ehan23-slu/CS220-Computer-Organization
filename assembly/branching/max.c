// testing our max function

#include <stdio.h>
#include <stdlib.h>

long max2(long a, long b);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Not enough arguments");
        return 1;
    }

    long biggest = max2(atol(argv[1]), atol(argv[2]));
    printf("Biggest: %ld\n", biggest);
    return 0;
}