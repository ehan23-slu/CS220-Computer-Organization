/*
 * This function calculates the frequency of each digit (0–9) in a given number
 * 
 * Parameters:
 * int64_t n - input number
 * int64_t freq[] - array to store the frequency of each digit
 * 
 * Example:
 * For input: 224498344
 * The array will be:
 * index = 0 1 2 3 4 5 6 7 8 9
 * value = 0 0 2 1 4 0 0 0 1 1
 */

#include <stdint.h>
#include <stdio.h>

void digit_freq(int64_t n, int64_t freq[]) {
    // initialize the freq array to 0
    for (int i = 0; i < 10; i++) {
        freq[i] = 0;
    }

    // if n is negative, convert to positive (negate)
    if (n < 0) {
        n = -n;
    }

    // if n is 0, increment the 0th entry
    if (n == 0) {
        freq[0] = 1;
        return;
    }

    // extract each digit and increment its count
    while (n > 0) {
        int digit = n % 10;      // get the last digit of n
        freq[digit]++;           // increment the count for this digit
        n = n / 10;              // remove the last digit from n
    }
}