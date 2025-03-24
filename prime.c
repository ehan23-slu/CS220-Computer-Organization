#include <stdio.h>

// equivalent statement for 
// usigned long and unsigned long int
unsigned long int factor(unsigned long n) {
    
    unsigned long int i = 2;

    while (i <= n/2) { // indentation in c doesn't matter so use {}
        if (n % i == 0) {
            return i;
        } i++;
    } 

    return 1;
}

int main() {
    unsigned long int n;
    scanf("%lu", &n); // & addressof // pass by value -> need address
    printf("%lu\n", factor(n));
}