/*
 * void scale(int64_t *mat, int64_t nrow, int64_t ncols, int64_t factor);
 */

.arch armv8-a
.global scale

.text
.align 2

scale:
    // x0 contains pointer to matrix
    // x1 contains nrows
    // x2 contains ncols
    // x3 contains scale factor

    mov x4, #0                  // row = 0

while_row:
    cmp x4, x1
    b.ge while_row_done         // break if row >= nrows

    // while row body
    mov x5, #0                  // col = 0

while_col:
    cmp x5, x2
    b.ge while_col_done         // break if col >= ncols

    // while col body
    // have x4 is row, x5 is col
    // mat + (row*ncols + col) << 3 // left shift --> since it is fast
    mul x6, x4, x2              // row * ncols
    add x6, x6, x5              // + col
    lsl x6, x6, #3              // * 8 (equiv to << 3)

    ldr x7, [x0, x6]            // load *(mat + offset)
    mul x7, x7, x3              // multiply by scale factor // can't use <<
    str x7, [x0, x6]            // store updated value in matrix

    add x5, x5, #1              // col++
    b while_col                 // branch back to start of inner loop
while_col_done: 

    add x4, x4, #1              // row++
    b while_row                 // branch back to start of outer loop

while_row_done:
    // return 
    ret
