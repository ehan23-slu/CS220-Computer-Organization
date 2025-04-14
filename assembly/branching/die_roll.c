// use randrange to roll a 6-sided of die

#include <stdio.h>
#include <stdlib.h>

long randrange(long start, long end);

int main(void) {
    srand(42);
    long roll = randrange(1, 7);
    printf("Die roll: %ld\n", roll);
}