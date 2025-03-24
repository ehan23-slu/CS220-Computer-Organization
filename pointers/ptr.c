# include <stdio.h>

int z; // global variable // outside of function // located in data memory

int main() {

    int x = 7; // local variable located in stack
    int *px, *pz;

    px = &x; // types have to match // left(px): pointer to int // right(&x): pointer to int
    pz = &z;
    
    printf("%lu\n", sizeof(px));
    printf("%lu\n", sizeof(int *)); // pointer to int 
    printf("px = %p\n", px);
    printf("pz = %p\n", pz);
    printf("&x = %p\n", &x);
    printf("&px = %p\n", &px); // type of px: pointer to int // type of &px: pointer to a pointer to int 
    // local vaiable so located in stack
}