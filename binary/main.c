#include <stdio.h>
#include <stdlib.h>
#include "int2bin.h"

int main(int argc, char *argv[]) {

    // TODO. Make sure argc is 2
    if (argc != 2) {
        printf("Usage: provide number");
        return 1;
    }

    printbin(atol(argv[1])); // 1
    printf("\n");           // 2 (return address)

    printf("%s\n", int2bin(atoi(argv[1])));

}

