#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// uint8_t, int8_t (signed int 8 bits),b uint32_t, ... uinr64_t
typedef char * string; // array of char == string == char *

void f(string strs[]) { // *strs w/o [] -> char * *strs == char **strs
    
}

// typedef - type definition
// typedef unsigned long int uint64_t;

// command line arguments example

// argv[0] is always the command name
// argc is argument count
int main(int argc, char **argv) { // args array of string in Java // *array = array []
    // char **argv is the smae as char *argv[]

    // if (argc < 3) {
    //     printf("Usage: sum needs at least two values\n");
    //     return 1; // non zero value 
    // }
    // int r = atoi(argv[1]) + atoi(argv[2]);
    // printf("%d\n", r);

    // WatchoUt! Don't overlow an int
    // Watchout! for non integer arguments

    unsigned long int sum = 0;
    // uint64_t sum = 0;
    for (int i = 0; i < argc; i++) {
        sum += atoi(argv[i]);
    }
    printf("%lu\n", sum);

    // printf("argc = %d argv[0] = %s\n", argc, argv[0]);
    return 0; // successfully complete 0
}