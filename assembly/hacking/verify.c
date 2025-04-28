// example program for checking a password

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void logged_in() {
    printf("Logged in. Secret access granted.\n");
    exit(0);
}

// return true if password is valid
int valid() {
    char password[12];  // 12 bytes as char - 1 byte
    scanf("%s", password);
    return 0 == strcmp(password, "goodpass");
}

int main(void) {

    int status;
    printf("Enter password: ");

    // get password and confirm if valid
    status = valid();

    if (!status) {
        printf("Access denied\n");
        return 1;
    }

    // print out success message
    logged_in();
    return 0;

}