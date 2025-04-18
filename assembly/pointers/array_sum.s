/*
 * int64_t array_sum(int64_t vec[], int64_t n); // need to provide second 
 * argument since c has no function to calculate size of array
*/

.arch armv8-a
.global array_sum

.text
.align 2

array_sum:
    // x0 contains the pointer to the array
    // x1 contains the number of items in the array

    mov x2, #0          // sum
    mov x3, #0          // i

while:
    cmp x3, x1          // compare i and n
    b.ge done           // break if i >= n

    // loop body
    // 1. get array value
    // ptr + idx * size(type)
    // x0 + x3 * 8 ==== x0 + x3 << 3
    lsl x4, x3, #3
    ldr x4, [x0, x4]    // load [x0+x3*8] into x4

    // 2. add to sum
    add x2, x2, x4

    // 3. increment i
    add x3, x3, #1

    b while             // jump back to start of loop

done:
    mov x0, x2          // move result into return reg
    ret