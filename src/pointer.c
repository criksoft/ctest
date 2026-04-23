#include <stdio.h>
#include <stdlib.h>

void fn(int x)
{
    printf("%d\n", x);
}

struct Tonto;

int main(void)
{
    // struct Tonto *tonto_ptr;
    // *tonto_ptr;

    void (*my_fn_ptr)(int) = fn;

    printf("my_fn_ptr: %p\n", my_fn_ptr);
    my_fn_ptr++;
    printf("my_fn_ptr: %p\n", my_fn_ptr);



    my_fn_ptr(99);


    char arr2[] = "abc";
    ;
    for (char *s = arr2; *s != '\0'; s++) {
        printf("%c", *s);
    }
    printf("\n");

    int x = 1;

    void *woof = &x;
    woof++;

    int arr[20] = {3,2,4,1};
    for (int *s = arr; s < (arr + 4); s++) {
        printf("%d", *s);
    }
    printf("\n");



    int *p = arr;
    int **p2 = &p;

    printf("arr: %p\n", &arr);
    printf("p: %p\n", p);
    printf("value: %d\n", p[2]);
    printf("value: %d\n", *(p + 2));
    printf("value: %p\n", p + 2);
    printf("value: %p\n", &p[2]);
    printf("value: %d\n", arr[2]);
    printf("value: %d\n", *p);

    printf("value: %p\n", p2);
    printf("value: %p\n", p2 + 1);
}
