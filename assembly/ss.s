// sum_squares function
.arch armv8-a
.global sum_squares

.text
.align 2

/*
* long sum_squares (long n)
* compute and return the sum of the first n squares
 */
sum_squares:
    // x0 contains n

    // compute N+1 and store to x1
    add x1, x0, #1

    // compute 2N+1 and store to x2
    // mul cannot take an immediate (constant), so load x2 with 2
    mov x2, #2
    mul x2, x0, x2
    add x2, x2, #1

    // compute N(N+1)(2N+1) and store to x0
    // x0*x1*x2
    mul x0, x0, x1
    mul x0, x0, x2

    // divide result by 6
    // load 6 into a register first
    // reuse x1
    mov x1, #6
    sdiv x0, x0, x1

    // return 
    ret