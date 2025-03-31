// Simple function for adding 2 to a long

.arch armv8-a
.global add2

.text
.align 2

/*
* add 2 function 
* long add2(long n)
* @return n + 2
 */
add2:
    // x0 contains n
    // goal: place n + 2 into x0
    add x0, x0, #2
    ret // returns from a function call