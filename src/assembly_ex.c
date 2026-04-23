#include <stdio.h>

int fn(int n)
{
    int number = 1;
    while (number <= n) {
        printf("%d\n", number);
        number = number + 1;
    }
    return 10;
}

int main(void)
{
    int x = fn(5);
}