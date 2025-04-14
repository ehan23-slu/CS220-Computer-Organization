/*
 * compute a random number in the range [start, end)
 * using the C library's rand() funciton:
 *
 * rand() % (end - start) + start
 */

.arch armv8-a
.global randrange

.text
.align 2

/*
 * long mod(long x, long y)ss
 * x - (x//y) * y
 */
mod:
    sdiv x2, x0, x1         // x / y
    mul x2, x2, x1          // (x / y) * y
    sub x0, x0, x2          // x - (x / y) * y
    ret

randrange:
    // x0 - start --- x19
    // x1 - end   --- x20

    // back up on the stack
    sub sp, sp, #32
    str fp, [sp]            // fp is x29
    str lr, [sp, #8]        // lr is x30
    str x19, [sp, #16]      // x19 will store start
    str x20, [sp, #24]      // x20 will store end

    // move x0 and x1 into x19 and x20
    mov x19, x0
    mov x20, x1

    // rand() % (end - start) + start
    bl rand                 // call rand() ---> x0
    sub x1, x20, x19        // end - start --> x1
    
    bl mod                  // call mod (rand() % (end-start))
    add x0, x0, x19         // add start to the result

    // restore data from the stack
    ldr x20, [sp, #24]
    ldr x19, [sp, #16]
    ldr lr, [sp, #8]
    ldr fp, [sp]

    add sp, sp, #32
    
    ret
