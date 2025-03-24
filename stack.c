#include <stdio.h>

int main() {
    int x = 1;
    int y = 2;
    int z = 3; // stack // Where x, y, z in stack? next each other? 

    printf("&x = %u, &y = %u, &z = %u\n", &x, &y, &z); 
    // Output: &x = 3402709532, &y = 3402709528, &z = 3402709524
    // difference between them = 4
    // due to 4 bytes of size
}