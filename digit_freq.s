/*
 * This function calculates the frequency of each digit (0–9) in a given number
 *
 * This function corresponds to the C funtion:
 * void digit_freq(int64_t n, int64_t freq[]);
 *
 * Parameters:
 * x0: int64_t n - input number
 * x1: int64_t freq[] - array to store the frequency of each digit
 * 
 * Expected Output:
 * The result is stored in the array pointed to by freq[]
 */

.arch armv8-a
.global digit_freq

.text
.align 2

digit_freq:

    // store the input number (n) in x2 for further processing
    mov x2, x0
    // initialize the index i for freq[] to 0
    mov x3, #0              // i = 0

loop:
    // calculate the address of freq[i]; each element in freq is 8 bytes
    lsl x4, x3, #3          // x4 = i * 8
    add x4, x1, x4          // x4 = address of freq[i]
    
    // initialize freq[i] to 0
    mov x5, #0
    str x5, [x4]
    add x3, x3, #1          // increment index i by 1 (i++)

    // check if we've processed all 10 digits
    cmp x3, #10
    b.eq negative           // if i == 10, jump to negative branch
    b loop

negative:
    // handle the case: n < 0
    cmp x2, #0
    b.ge zero               // if n >= 0, skip negation
    neg x2, x2              // else negate, x2 = -x2

zero:
    // handle the case: n == 0
    cbz x2, set_zero_freq   // if zero, jump to set_zero_freq branch
    b freq_loop             // if not zero, proceed to process digits

set_zero_freq:
    // if n == 0, set freq[0] = 1
    mov x3, #1
    str x3, [x1]            // store 1 in freq[0]
    b done                  // finish the function

freq_loop:
    // main loop to process each digit of n
    mov x4, #10             // load x4 to 10 for division
    udiv x5, x2, x4         // divide n by 10, store the quotient in x5
    mul x6, x5, x4          // multiply quotient by 10 for most significant part
    sub x7, x2, x6          // subtract the most significant part for last digit

    // find the correct index in freq[] array for this digit
    lsl x8, x7, #3          // multiply digit by 8 for byte offset
    add x8, x1, x8          // add offset to the base address of freq[] 
                            // to get the address of freq[digit]

    ldr x9, [x8]            // load current frequency of digit

    add x9, x9, #1          // increment frequency by 1
    str x9, [x8]            // store updated frequency in freq[digit]

    mov x2, x5              // update n to remove last digit (quotient)
    cbz x2, done            // if n is 0, jump to done branch
    b freq_loop             // otherwise, continue with next digit

done:
    ret
