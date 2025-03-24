#include <stdint.h>

uint64_t mult(uint32_t multiplicand, uint32_t multiplier) {
    uint64_t result = 0;
    uint64_t tmp_multiplicand = multiplicand;

    while (multiplier > 0) {
        if (multiplier & 1) {
            result = result + tmp_multiplicand;
        } 
        tmp_multiplicand = tmp_multiplicand << 1;
        multiplier = multiplier >> 1;
    } return result;
}