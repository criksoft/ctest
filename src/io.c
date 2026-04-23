#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char buf[3];
    memset(buf, 0, sizeof(buf));
    int r = read(0, &buf, sizeof(buf));
    if (r == -1) {
        _exit(1);
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("0x%02X ", buf[i]);
    }
    printf("\n");

    r = read(0, &buf, sizeof(buf));
    if (r == -1) {
        _exit(1);
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("0x%02X ", buf[i]);
    }
    printf("\n");
}