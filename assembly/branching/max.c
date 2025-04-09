// testing our max function

#include <stdio.h>
#include <stdlib.h>

long max2(long a, long b);
long max4(long a, long b, long c, long d);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Not enough arguments\n");
        return 1;
    }

    if (argc == 3) {
        long biggest = max2(atol(argv[1]), atol(argv[2]));
        printf("Biggest: %ld\n", biggest);
    }

    if (argc == 5) {
        long biggest = max4(
        atol(argv[1]), 
        atol(argv[2]), 
        atol(argv[3]), 
        atol(argv[4]));
        printf("Biggest: %ld\n", biggest);
    }
    return 0;
}