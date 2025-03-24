#include <stdio.h> 
#include <string.h>

/**
 * common function takes two strings s1 and s2 as input 
 * and builds up the string rslt that 
 * contains the characters that are in common between s1 and s2.
 */
 
void common(const char s1[], const char s2[], char rslt[]){
    int rslt_idx = 0; // to track the number of characters in rslt
    
    // calculate the lengths of s1 and s2 to control the loop bounds
    int length_s1 = strlen(s1);
    int length_s2 = strlen(s2);

    // nested loops to compare each character of s1 and s2
    for (int i = 0; i < length_s1; i++) {
        for (int j = 0; j < length_s2; j++) {

            // when characters from s1 and s2 are match
            if (s1[i] == s2[j]) {

                int checked = 0; // to track whether the character is already in rslt 

                // check if the character is already in rslt
                for (int k = 0; k < rslt_idx; k++) {
                    if (rslt[k] == s1[i]) {
                        // set checked to 1 if the character is found in rslt
                        checked = 1;
                        break;
                    }
                }
                // 0 indicates false
                // if the character is not a duplicate, add it into rslt
                 if (checked == 0) {
                    rslt[rslt_idx] = s1[i];
                    rslt_idx++; // move to next index in rslt
                    rslt[rslt_idx] = '\0'; // null-terminate rslt
                 }
                 break; // exit the loop
            }
        }
    }
}

int main() {
    // declare arrays for s1, s2, and rslt
    // s1 and s2 are limited to 40 characters (plus null terminator)
    // rslt can hold up to 26 characters plus the null terminator
    char s1[41];
    char s2[41];
    char rslt[27];
    
    // read strings from user for s1 and s2
    scanf("%s", s1);
    scanf("%s", s2);
    
    // call common function
    common(s1, s2, rslt);
    
    // print the result
    printf("common: %s\n", rslt);

    // return statement for main function
    return 0;
}