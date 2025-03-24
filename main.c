#include <stdio.h>
#include <stdlib.h>
#include "bin2int.h"

/**
 * main function reads string binary from command line, convert it to an
 * unsigned 64-bit integer and prints the result.
 * 
 * argc - number of command line arguments
 * argv - array of command line argument strings
 */
int main(int argc, char *argv[]) {
    // check if exactly one argument (binary number) is provided
    if (argc != 2) {
        printf("Provide one binary number.\n");
        return 1;

    // call the bin2int function to convert the binary string (argv[1])
    // into an usigned 64-bit integer then print the result
    } printf("%llu\n", bin2int(argv[1]));
    return 0;
}