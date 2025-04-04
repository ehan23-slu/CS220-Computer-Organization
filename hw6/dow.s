/* HW6 dow.s
 *
 * This function calculates the day of the week 
 for a given data (month, day, year).
 * It returns a value 0-6, where
 * 0 = sunday, 1 = monday, ... , 6 = saturday
 * 
 * x0 - month m
 * x1 - day d
 * x2 - year y
 *
 */

.arch armv8-a
.global dow

.text
.align 2

dow:

    // Calculate the year adjusted based on month (y0)
    mov x3, #14         // initialize x3 with the constant 14
    sub x3, x3, x0      // subtract m from 14
    mov x4, #12         // initialize x2 with the constant 12
    sdiv x3, x3, x4     // divide (14-m) by 12 for adjustment factor for y
    sub x5, x2, x3      // subtract the adjustment from y to get y0

    // Calculate the value x, which is used for further adjustments
    mov x6, x5          // initialize x6 with y0
    mov x7, #4          // initialize x7 with constant 4
    sdiv x7, x5, x7     // divide y0 by 4
    mov x8, #100        // initialize x8 with the constant 100
    sdiv x8, x5, x8     // divide y0 by 100
    mov x9, #400        // initialize x9 with the constant 400
    sdiv x9, x5, x9     // divide y0 by 400 for further adjustment
    add x6, x6, x7      // add the result of y0 divided by 4 to x6
    sub x6, x6, x8      // subtract the result of y0 divided by 100 from x6
    add x6, x6, x9      // add the result of y0 divided by 400 to x6

    // Calculate m0, which adjusts m based on the formula:
    // m0 = m + 12 * ((14 - m) / 12) - 2
    mov x3, #14         // initialize x3 with constant 14
    sub x3, x3, x0      // substract m from 14
    mov x7, #12         // initialize x7 with constant 12
    sdiv x3, x3, x7     // divide (14-m) by 12
    mul x3, x3, x7      // multiply the result by 12
    add x3, x3, x0      // add the original month to the adjustment
    sub x3, x3, #2      // substract 2 to get m0

    // Calculate d0, which adjusts d
    // to account for the given y and m
    mov x7, #31         // initialize x7 with constant 31
    mul x8, x7, x3      // multiply 31 by m0
    mov x9, #12         // initialize x9 with constant 12
    sdiv x8, x8, x9     // divide the result by 12 for # of d in m
    add x8, x8, x6      // add x to the adjusted d
    add x8, x8, x1      // add d to the result

    // Calculate the remainder of d0 divided by 7 
    // to get d of the week
    mov x9, #7          // initialize x9 with constant 7
    sdiv x10, x8, x9    // divide d0 by 7
    mul x10, x10, x9    // multiply by 7 to get back the whole # of weeks
    sub x0, x8, x10     // substract the whole # of weeks from d0 to get
                        // remainder

    ret                 // return the result(d of the week) in x0
