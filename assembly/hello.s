// print hello world!

.arch armv8-a

// text segment (code)
.text
.align 2    // align instructions to 2^2 byte offsets
.global _start

_start:

    // tell OS to print a string to stdout
    mov x0, #1      // 1 in x0 indicates stdout
    ldr x1, =hello  // stores pointer to hello string in x1
    mov x2, #13     // x2 gets the number of characters to print

    // store 64 in x8 to tell linux to print
    mov x8, #64
    // service call to linux
    svc 0

    // "return 0"
    mov x0, XZR     // move (copy) XZR into x0 // could be #0
    mov x8, #93     // service call 93 is exit
    svc 0



.data
hello: .ascii "Hello, world\n"