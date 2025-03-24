#include <stdint.h>

// return a string representaing
// the binary representation of
// n. The string is allocated from 
// heap and it is the job of the 
// caller to free the memory 
// when doen with it. // C doesn't have garbage collector
char *int2bin(uint64_t n);
void printbin(uint16_t x);