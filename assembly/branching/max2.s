// long max2(long a, long b)
// return the greater of a or b

.arch armv8-a
.global max2

.text
.align 2

max2:
    // Goal: place in x0 the larger of the two arguments
    // x0 - a, x1 - b
    cmp x0, x1
    b.gt true_branch    // jump to true_branch if x0 > x1
    // otherwise, fall through to the next instruction
    // we need to return x1
    mov x0, x1
true_branch:
    // just return x0 is the biggest
    ret