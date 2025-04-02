#include <stdio.h>
#include <stdlib.h>

long sum_squares(long n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error!\n");
        return 1;
    }
    printf("The sum of the first %s squares is %ld\n", argv[1], sum_squares(atol(argv[1])));
    return 0;
}