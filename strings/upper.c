#include <stdio.h>
#include <string.h>

// convert the lowercase characters in s
// to uppercase, modifying the original a rray s.

// precondition: s has a null terminating character ***
// strlen is unsecure function dut to this

// study: modify to use a maxlen parameter to make it safe
//	 void upper (char s[], size_t maxlen) {
//	 size_t length = strnlen(s, maxlen);
// 		for (size_t i = 0; i < length; i++} ... same code}

void upper(char s[]) {

	for (int i = 0; i < strlen(s); i++) { // can we do s[i] != '\0'? Yes but it's more while loop style
		// what if the s[] has no null terminating character? keep going :( (see precondition)
		if (s[i] >= 'a' && s[i] <= 'z') // checking the lower case
			s[i] = s[i] - 'a' + 'A'; // readability use this instead of 32
	}
}

int main() {

	char t[] = "Hello123world";
	upper(t);
	printf("%s\n", t);
	// upper("hello123"); // Crash Segmentation fault // can't modify the constant
	return 0;
}
