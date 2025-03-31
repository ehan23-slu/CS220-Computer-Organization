// Warm_up 

.arch armv8-a
.global mul_five

.text
.align 2

/**
This assembly funciton takes 1 
and return its value multiplied by 5
 */
mul_five:
    // value is in x0
    mov x1, #5          // mul can't take immediate (constant)
    mul x0, x0, x1      // multiply two numbers together
    ret                 // x0 is return label

mul_five_opt:
    // use logival shift to avoid slow multiplicaiton
    lsl x1, x0, #2
    add x0, x0, x1
    ret

mul_five_opt2:
    // combine add and lsl instruction
    add x0, x0, x0, lsl #2
    ret