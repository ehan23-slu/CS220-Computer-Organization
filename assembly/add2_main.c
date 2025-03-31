// c file to call add2 in assembly
#include <stdio.h>

// declare an external funciton
long add2(long n);

int main(void) {
    printf("add2(40) = %ld\n", add2(40));
    return 0;
}