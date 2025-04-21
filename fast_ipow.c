#include <stdint.h>

/*
 * This funciton computes the fast integer power using recursion:
 *
 * When y == 0: The function returns 1, 
 * since any number to the power of 0 is 1.
 * 
 * When y is even: It computes fast_ipow(x, y/2) once, stores it, 
 * and returns its square
 * 
 * When y is odd: It still computes fast_ipow(x, y/2), squares the result,
 * and multiplies by x once more to account for the odd exponent
 *
 * Parameters:
 * x - Base
 * y - Exponent
 * 
 * Returns:
 * x raised to the power y
 */

int64_t fast_ipow(int64_t x, int64_t y) {
    // check base case
    if (y == 0) {
        return 1;
    }
    // Variable pow computes x^(y/2) once and reuse it
    int64_t pow = fast_ipow(x, y/2);

    // recursie case 1: y is even
    if (y % 2 == 0) {
        return pow * pow;
    }
    // recursive case 2: y is odd
    return x * pow * pow;
}