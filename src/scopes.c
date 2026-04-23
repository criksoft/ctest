#include <stdio.h>

int x = 5;

void test_not_works()
{
    int x = x;
    printf("%d\n", x);
}

void test_works()
{
    int y = x;
    int x = y;
    printf("%d\n", x);
}

int main(void)
{
    test_not_works();
    test_works();
    printf("%d\n", x);
}
