// long smallest_div(long n)
// return the smallest number that divides
// n without remainder (>1)

.arch armv8-a
.global smallest_div

.text
.align 2

smallest_div:
    /*
     * long i = 2;
     * while (n % i != 0)
     *   i++;
     * return i;
     */
    
    // x1 is i
    mov x1, #2

while:
    // x % y = x - (x/y)y
    sdiv x2, x0, x1     // n / i
    mul x3, x2, x1      // n / i * i
    sub x3, x0, x3      // subtact this from n
    // x3 contains n % i 
    cmp x3, #0          // if mode is 0
    b.eq done           // loop is done
    
    // loop body
    add x1, x1, #1

    b while // jump back to start of loop
done:
    // return i
    mov x0, x1
    ret

