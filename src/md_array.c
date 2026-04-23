#include <stdio.h>
#include <stdlib.h>

void fn2(int (*a)[4])
{
    printf("%d\n", a[3][2]);
    // printf("%p\n", arr);
    // printf("%p\n", arr + 1);
}

void fn1(int *a, int row_size)
{
    printf("%d\n", *(a + (3 * row_size) + 2));
    // printf("%p\n", arr);
    // printf("%p\n", arr + 1);
}

int main(void)
{
    int a[5][4]    = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    //               1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20
    //               1, 5, 9,13,17, 2, 6,10,14,18, 3, 7,11,15,19, 4, 8,12,16,20;


    int b[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    int (*c)[4] = (int(*)[4])&b;

    printf("%d\n", *(b + (3 * 4) + 2));
    printf("%d\n", c[3][2]);

    int *ar[4]; // jagged array
    ar[0] = malloc(20 * sizeof(int));
    ar[1] = malloc(4 * sizeof(int));


    // int a[5][4] = {{1,5,9,13,17},{2,6,10,14,18},{3,7,11,15,19},{4,8,12,16,20}};

    // printf("%d\n", *(((int*)a) + 14));

    // a[3][2];
    // a + (3 * 4) + 2;
    // a + (2 * 5) + 3;

    printf("%d\n", a[3][2]);

    fn1((int*)a, sizeof(a[0]) / sizeof(a[0][0]));
    fn2(a);
}
