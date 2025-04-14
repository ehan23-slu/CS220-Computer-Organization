#include <stdio.h>
#include <stdlib.h>
#include "ipow.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }
    
    int64_t res = ipow(atol(argv[1]), atol(argv[2]));
    printf("%ld\n", res);

}