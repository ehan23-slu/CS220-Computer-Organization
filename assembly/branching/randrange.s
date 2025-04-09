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
