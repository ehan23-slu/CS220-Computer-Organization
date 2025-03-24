#include <stdio.h>

int main() {

	char t[] = "Hello"; // null character is automatically added
	char s[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char w[] = {72, 101, 108, 108, 111, 0};
	char z[10];

	printf("%s\n", t);
	printf("%c\n", t[0]);
	printf("%d\n", t[0]);

	scanf("%s", z); // z regers to the locaiton of the first character
	scanf("%s", &z[0]); // equivalent expression

}
