/**
 * long max4(long a, long b, long c, long d) {
 *     return(max2(max2(a,b), max2(c,d)));
 * }
 */

.arch armv8-a
.global max4

.text
.align 2

// x0 - a, x1 - b, x2 - c, x3 - d
max4:
    // because we will be calling other functions
    // we should back up x30 (link register) and
    // x29 (frame pointer)

    // SP must have an address that is divisible by 16
    // (quad word aligned)
    sub sp, sp, #16
    str x29, [sp]       // store the contents of x29 at the address
                        // stored in the stack pointer
    str x30, [sp, #8]   // store x30 at SP+8

    // call max2(a,b)
    bl max2
    // return value is in x0

    // call max2(c,d)
    // put c and d in x0, x1
    mov x4, x0         // back up the returned max
    mov x0, x2          // move c into x0
    mov x1, x3          // move d into x1
    bl max2

    // return value in x0
    mov x1, x4          // move previous max into x1
    bl max2             // get the max of the two maxes

    // final return value is in x0
    // restore x29 and x30 from the stack
    ldr x30, [sp, #8]   // restore the link register
    ldr x29, [sp]       // restore the frame pointer
    add sp, sp, #16     // restore stack pointer

    // return
    ret