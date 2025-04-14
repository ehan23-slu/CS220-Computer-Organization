// Assembly version of the ipow recursive function

/*
int64_t ipow(int16_t base, int16_t pow) {
    // check base case
    if (pow == 0) {
        return 1;
    }
    // recursive case
    return base * ipow(base, pow - 1);
}
*/

.arch armv8-a
.global ipow

.text
.align 2

ipow:
    // x0 = base
    // x1 = pow

    // we need to back up LR, FP, x19, x20
    sub sp, sp, #32
    str fp, [sp]
    str lr, [sp, #8]
    str x19, [sp, #16]
    str x20, [sp, #24]

    // move x0 and x1 into x19 and x20, respectively
    mov x19, x0         // x19 is base
    mov x20, x1         // x20 is pow

    // base case
    // jump if x20 (pow) != 0 ... jump to the recursivce case
    cbnz x20, recurse

    // WHAT IS TRUE HERE? pow is 0
    // return 1
    mov x0, #1
    b return            // jump to the return to restore stack

recurse:
    // recursice case: base * ipow(base, pow -1)
    mov x0, x19         // arg0 is base
    sub x1, x20, #1     // arg1 is pow - 1
    bl ipow             // recursive call

    // x0 holds result of ipow(base, pow - 1)
    mul x0, x0, x19
    // x0 holds the result of ipow(base, pow)

return:
    // restore the stack and registers
    ldr x20, [sp, #24]
    ldr x19, [sp, #16]
    ldr lr, [sp, #8]
    ldr fp, [sp]
    add sp, sp, #32

    // return!
    ret