#include <stdio.h>

void itoa(int n, char *buf)
{
    if (n < 0) {
        *buf++ = '-';
    }

    if (n > 0) {
        n = -n;
    }

    char *start = buf;
    do {
        *buf++ = '0' - (n % 10);
        n /= 10;
    } while (n < 0);

    *buf = '\0';

    for (char *end = buf - 1; start < end; start++, end--) {
        char tmp = *start;
        *start = *end;
        *end = tmp;
    }
}

int main(void)
{
    int n = 1024;
    for (int i = 0; i < 5; i++) {
        char str[20];
        itoa(n, str);
        n = n * n;
    }
}
