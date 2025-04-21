/*
 * Assembly version of the fast_ipow recursive function
 *
 * Arguments:
 * x0 - base (x)
 * x1 - exponent (y)
 * 
 * Returns:
 * x0 - result of x raised to the power of y
 * 
 * Example:
 * x0 = 2
 * x1 = 6
 * bl fast_ipow returns 64 in x0
*/

.arch armv8-a
.global fast_ipow

.text
.align 2

fast_ipow:
    // Back up callee saved registers and link register
    sub sp, sp, #32
    str fp, [sp]
    str lr, [sp, #8]
    str x19, [sp, #16]
    str x20, [sp, #24]

    // move x0 and x1 into x19 and x20, respectively
    mov x19, x0         // x19 holds base, x
    mov x20, x1         // x20 holds exponent, y

    // Check base case: if y == 0, return 1

    cbnz x20, recurse   //  if y != 0, jump to the recursivce case
    mov x0, #1          // return 1 for base case
    b return   

recurse:
    // compute y / 2 and store in x1
    mov x1, x20
    mov x2, #2
    sdiv x1, x1, x2     // x1 = y / 2
    
    // recursive call: fast_ipow(x, y / 2)
    mov x0, x19
    bl fast_ipow        // result in x0

    // store recursive result in x3
    mov x3, x0          // x3 = fast_ipow(x, y / 2)

    // check if y is even
    // compute remainder through y - ((y / 2) * 2)
    mov x4, x20         // x4 = y
    sdiv x5, x4, x2     // x5 = y / 2
    mul x5, x5, x2      // x5 = (y / 2) * 2
    sub x5, x4, x5      // x5 = y - (y / 2) * 2
    cbz x5, even        // if remainder is 0 which means y is even
                        // jump to even branch
    
    // y is odd
    // return x * fast_ipow * fast_ipow
    mul x0, x3, x3      // fast_ipow * fast_ipow
    mul x0, x0, x19     // x * fast_ipow * fast_ipow
    b return
    
even:
    // y is even
    // return fast_ipow * fast_ipow
    mul x0, x3, x3

return:
    // restore the stack and registers
    // then return
    ldr x20, [sp, #24]
    ldr x19, [sp, #16]
    ldr lr, [sp, #8]
    ldr fp, [sp]
    add sp, sp, #32

    ret
