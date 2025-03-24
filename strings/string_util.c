#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_util.h"

// s points to constant data
/**
 * ltrim retruns a new string with the 
 * leading whitespace in s removed.
 * 
 * s - the string removing the leadin whitespace
 * precondition: s must be null terminated 
 */
char *ltrim(const char *s) { // const -> value 
                            // "what points to" souldn't change 
    while(*s == ' ') 
        s++;

    // WATChOUT! use strnlen:
   
    // size_t len = strnlen(s, 1000);
    // char *r = malloc(len + 1);

    char *r = malloc(strlen(s) + 1); // if we don't have null char // -> len will massive

    // if (r == NULL) {printf("Error"); return 1;}
    // strncpy(r, s, len);
    // r[len] = '\0';
    strcpy(r,s); // WATCHOUT! strncpy
    return r; // s passed by value -> modify copy
}

void upper(char *s)
{

    for (int i = 0; i < strlen(s); i++) { // can we do s[i] != '\0'? Yes but it's more while loop style
		// what if the s[] has no null terminating character? keep going :( (see precondition)
		if (s[i] >= 'a' && s[i] <= 'z') // checking the lower case
			s[i] = s[i] - 'a' + 'A'; // readability use this instead of 32
	}
}
 