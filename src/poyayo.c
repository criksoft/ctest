#include <stdio.h>

typedef struct {
    int size;
    int *data;
} IntArray;

typedef struct {
    int size;
    int *data;
} CharArray;

void printSizeInt(int arr[], int size) {
    printf("Calling: printSizeInt(int arr[], int size).....\n");
    printf("Good job you beaner, for an int array I do need the size: %d\n\n\n", size);
}

void printSizeIntNoSize(int arr[]) {
    printf("Calling: printSizeIntNoSize(int arr[]).....\n");
    printf("Remember a passed array is just a pointer, so I can't know the size you dumb fuck.\n\n\n");
}

void printSizeChar(char arr[]) {
    printf("Calling: printSizeChar(char arr[]).....\n");
    printf("I can loop through a char array if it has a null terminator, let's try.\n");
    int len = 0;
    while (arr[len] != '\0' || len == 100) {
        len++;
    }
    if (len == 100) {
        printf("You didn't give me a null terminator idiot. Pick another career.\n\n\n");
    } else {
        printf("Good job you big dick John, your array size is %d\n\n\n", len);
    }
}

void printSizeIntArrayStruct(IntArray arr) {
    printf("Calling: printSizeIntArrayStruct(IntArray arr).....\n");
    printf("Oh fancy pants here... Hey look everyone this guy is being fancy.. jackass\n");
    printf("Here you go.. cunt. Your size is: %d\n", arr.size);
    printf("Btw.. you made a copy of the struct. Take better care of your memory you hoe\n\n\n");
}

void printSizeIntArrayStructPtr(IntArray *arr) {
    printf("Calling: printSizeIntArrayStructPtr(IntArray *arr).....\n");
    printf("Ok big shot... a little respect for you, no extra memory, and you're using a struct\n");
    printf("How many bitches you got?\n");
    printf("Oh yeah your arr size is %d\n\n\n", arr->size);
}

void printSizeCharArrayStruct(CharArray arr) {
    printf("Calling: printSizeCharArrayStruct(CharArray arr).....\n");
    printf("Oh fancy pants here... Hey look everyone this guy is being fancy.. jackass\n");
    printf("Here you go.. cunt. Your size is: %d\n", arr.size);
    printf("Btw.. you made a copy of the struct. Take better care of your memory you hoe\n\n\n");
}

void printSizeCharArrayStructPtr(CharArray *arr) {
    printf("Calling: printSizeCharArrayStructPtr(CharArray *arr).....\n");
    printf("Ok big shot... a little respect for you, no extra memory, and you're using a struct\n");
    printf("How many bitches you got?\n");
    printf("Oh yeah your arr size is %d\n\n\n", arr->size);
}

int main(void) {
    int arr1[4] = {10, 20, 30, 40};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printSizeIntNoSize(arr1);
    printSizeInt(arr1, size1);

    char arr2[4] = {'f', 'u', 'c', 'k'};
    printSizeChar(arr2);

    char arr3[5] = {'f', 'u', 'c', 'k', '\0'};
    printSizeChar(arr3);

    int temp4[] = {10, 20, 30, 40};
    IntArray arr4 = {4, temp4};
    printSizeIntArrayStruct(arr4);
    printSizeIntArrayStructPtr(&arr4);

    char temp5[] = {'f', 'u', 'c', 'k'};
    CharArray arr5 = {4, temp5};
    printSizeCharArrayStruct(arr5);
    printSizeCharArrayStructPtr(&arr5);
}