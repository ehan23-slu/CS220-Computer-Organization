#include <stdio.h>
#include "string_util.h" //not angle bracket

int main() {
    printf("%s\n", ltrim("         hello"));
    char s[] = "hello";
    upper(s);
    printf("%s\n", s);
}