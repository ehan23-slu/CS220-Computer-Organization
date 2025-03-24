#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "int2bin.h"

void printbin(uint16_t x) {
    if (x == 0) {               // 1
        print("0");             // 2
    } else {                    // 3
        printbin(x >> 1);       // 4
        printf("%lu", x & 1);   // 5 (return address)
    }
}

char *int2bin(uint64_t n) {

    // what if n is zero? crash.
    if (n == 0) {
        printf("Usage: no 0 since log2");
        return 1;
    }

    uint32_t nb = (uint32_t) (floor(log2((double) n)) + 2);
    char *r = malloc(nb);
    r[nb - 1] = '\0'; // add null terminator

    for (int i = nb - 2; i >= 0; i--) {
        r[i] = n % 2 + '0';
        n = n >> 1; // same as divide by 2
    }

    return r;

}