#include <stdio.h>
#include <string.h>

struct part_t {

	int pno;
	char name[10];
	double weight;
	char location[10];

}; // ; is necessary

// struct are passed by value (pass the copy of entire struct)
void print_part(struct part_t p) { // copy of entire struct
	printf("(%d, %s, %.2f, %s)\n", p.pno, p.name, p.weight, p.location);
	p.name[0] = 'Z'; // since we change the copy of struct it doesn't work // not change the original one
}

void f(char s[], struct part_t p) {

	s[0] = 'Z'; // original array is passed as allocaiton (address)
	p.name[0] = 'Z'; // copied array
}

int main() {

	struct part_t p1;
	p1.pno = 1;
	// p1.name = "bolt"; // cannot assign to an array
	strcpy(p1.name, "bolt");
	p1.weight = 3.14159;
	strcpy(p1.location, "London");
	print_part(p1);
	print_part(p1);

	f(p1.location, p1); // pass the location of array and copy
	print_part(p1); // Zondon instead of London

}
