#include <stdint.h>
#include "bin2int.h"

/**
 * bin2int function converts a binary string into an unsigned 64-bit integer.
 * 
 * s - a pointer to a null-terminated string representing the binary number.
 * 
 * condition:
 * 1. If the result is approaching the maximum value that 
 * can be held by a 64-bit unsigned integer (UINT64_MAX),it returns 
 * UINT64_MAX to avoid overflow.
 * 
 * 2. Leading zeros are ignored.
 * 
 * 3. conversion stops at the first non'0' or '1' character.
 * 
 */

uint64_t bin2int (const char *s) {
    uint64_t result = 0;

    // skip any leading zeros
    while (*s == '0') {
        s++;
    }

    // iterate each character in the string until the null terminator
    while (*s != '\0') {
        // if the character is '1', add it to the result
        if (*s == '1') {

            // prevent overflow
            if (result > (UINT64_MAX / 2)) {
                return UINT64_MAX;
            }

            // shift left by 1(multiplying by 2), then add 1
            result = (result * 2) + 1;

        // if the character is '0', shift the result by 1
        } else if (*s == '0') {

            // prevent overflow
            if (result > (UINT64_MAX / 2)) {
                return UINT64_MAX;
            } 

            // shift left by 1(multiplying by 2)
            result *= 2;
        }
        // move to the next character in the string
        s++;
        
    } return result;
}