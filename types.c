#include <stdio.h>

int main() {

	int x = 123;
	printf("%lu\n", sizeof(int));

	unsigned int y;

	char c1; // char type 8 bit integer signed or unsigned?
	signed char c2;
	unsigned char c3;
	printf("char is %lu bytes\n", sizeof(char));

	short int s1; // half the size of an int
	printf("short is %lu bytes\n", sizeof(short int));

	long int li1; // double size of an int
	printf("long is %lu bytes\n", sizeof(long int));

	long long int lli;
	printf("long long is %lu bytes\n", sizeof(long long int));

	float f1;
	printf("float is %lu bytes\n", sizeof(float));

	double d1;
	printf("double is %lu bytes\n", sizeof(double));

	long double d2;
	printf("long double is %lu bytes\n", sizeof(long double));

}

