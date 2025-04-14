#include <stdint.h>
#include "ipow.h"

int64_t ipow(int64_t base, int64_t pow) {
    // check base case
    if (pow == 0) {
        return 1;
    }
    // recursive case
    return base * ipow(base, pow - 1);
}