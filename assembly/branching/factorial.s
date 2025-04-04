// long factorial(long n)
// compute the factorial of a number
.arch armv8-a
.global factorial

.text
.align 2

/*
 * long total = 1
 * while (n != 0) {
 *   total *= n;
 *   n--;
 * }
 * return total;
 */

factorial:
    // x0 is n
    // x1 is total
    mov x1, #1          // total = 1
loop:
    // check loop condition
    // could stop at 1
    // cmp x0, #0          // if n == 0
    // b.eq done           // break out of the loop
    cbz x0, done           // check if x0 == 0, branch to done         

    // loop body
    mul x1, x1, x0      // total = total * n
    sub x0, x0, #1      // n = n - 1

    b loop              // jump back to the loop

done:
    // return total
    mov x0, x1
    ret
