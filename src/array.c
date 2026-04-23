#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// array, pointer, decay to pointer
void fn(int (*arr0)[20], int arr1[20], int arr2[], int *arr3 /*, int *arr4[20]*/)
{
    printf("value of arr0: %p\n", arr0);
    printf("value of arr1: %p\n", arr1);
    printf("value of arr2: %p\n", arr2);
    printf("value of arr3: %p\n", arr3);

    printf("sizeof arr0: %lu\n", sizeof(arr0));
    printf("sizeof *arr0: %lu\n", sizeof(*arr0));
    printf("sizeof **arr0: %lu\n", sizeof(**arr0));
    printf("sizeof arr1: %lu\n", sizeof(arr1));
    printf("sizeof *arr1: %lu\n", sizeof(*arr1));
    printf("sizeof arr2: %lu\n", sizeof(arr2));
    printf("sizeof arr3: %lu\n", sizeof(arr3));
    // printf("sizeof arr4: %lu\n", sizeof(*arr4));
    for (int i = 0; i < sizeof(*arr0) / sizeof(**arr0); i++) {
        printf("%d ", (*arr0)[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    // for (int i = 0; i < 20; i++)
    // {
    //     printf("%d ", (*arr4)[i]);
    // }
    // printf("\n");
}


struct putito {
    int a;
    struct putito *b;
};

void woof(void)
{
    printf("woof!!\n");
}

typedef struct alv {
    int a[30];
    int b;
} alv_t;

/// arr: *[20]int

struct my_int {
    int z;
};

void fn3(struct my_int *a, int *b)
{
    a->z;
    (*a).z;
    *b;
}

struct my_array {
    int size;
    long arr[];
};

void fn2(int (*arr)[20])
{
    struct my_int a;
    a.z=5;
    int b;
    b=5;
    printf("size of arr: %lu\n", sizeof(*arr));
    fn3(&a, &b);
}

int main()
{
    struct my_array *arrd = malloc(sizeof(struct my_array) + 20 * sizeof(*arrd->arr));
    arrd->size = 20;

    for (int i = 0; i < arrd->size; i++) {
        printf("%ld", arrd->arr[i]);
    }

    int arr[20] = {0, 3, 4, 2};
    // fn2(&arr);

    // int *p;

    //// int arr[20] != int *arr
    //// &arr[0] -> int *
    // DECAY TO POINTER -> int *arr
    // int *arr = malloc(20 * sizeof(int));

    // alv_t woof;
    //
    // fn(&arr, arr, &arr[0], arr /*, &arr*/);
    //
    woof();
    (*woof)();
    (**woof)();
    (********woof)();
    (&woof)();
    (*(&woof))();

    void (*my_fn_ptr)(void) = woof;
    my_fn_ptr();

    int alv_array1[30];
    int alv_array2[30];

    // alv_array1 = alv_array2; // :( of course doesn't work
    memcpy(&alv_array1, &alv_array2, sizeof(alv_array1));

    alv_t alv1 = {.a = {1, 5, 7}, .b = 5};
    alv_t alv2 = {1, 3, 4};
    // alv1.a = alv2.a;  // :( wrong again
    alv1 = alv2;

    printf("alv1.a[2]: %d\n", alv1.a[2]);
    printf("alv1.b: %d\n", alv1.b);

    alv2 = (alv_t){0}; // not safe 0s since not initialization

    printf("alv_struct2.a[2]: %d\n", alv2.a[2]);
    printf("alv_struct2.b: %d\n", alv2.b);
}

// sizeof(arr)	            -> Size of entire array in bytes
// &arr	                    -> Pointer to the array (T(*)[N])
//    void fn(int (&arr)[N])	-> Reference to the actual array
// char s[] = "text"		-> Initializer for array contents
// func(arr)	            -> :( decay! Pointer to first element (int*)
// arr + 1	                -> :( decay! Pointer to second element