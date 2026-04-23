#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define DA_DEFAULT_CAPACITY 4

#define DA_RESERVE(da, expected_capacity)                                                          \
    do {                                                                                           \
        if ((expected_capacity) > (da)->capacity) {                                                \
            if ((da)->capacity == 0) {                                                             \
                (da)->capacity = DA_DEFAULT_CAPACITY;                                              \
            }                                                                                      \
            while ((expected_capacity) > (da)->capacity) {                                         \
                (da)->capacity *= 2;                                                               \
            }                                                                                      \
            (da)->items = realloc((da)->items, (da)->capacity * sizeof(*(da)->items));             \
            assert((da)->items != NULL && "Buy more RAM lol");                                     \
        }                                                                                          \
    } while (0)

#define DA_INIT(da) DA_RESERVE((da), DA_DEFAULT_CAPACITY)

#define DA_APPEND(da, item)                                                                        \
    do {                                                                                           \
        DA_RESERVE((da), (da)->size + 1);                                                          \
        (da)->items[(da)->size++] = (item);                                                        \
    } while (0)

#define DA_FREE(da) free((da).items)

typedef struct int_array {
    int *items;
    int size;
    int capacity;
} int_array_t;

void init_int_array(struct int_array *arr)
{
    arr->items = malloc(DA_DEFAULT_CAPACITY * sizeof(*arr->items));
    if (arr->items == NULL) {
        printf("Error allocating memory for dynamic array\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = DA_DEFAULT_CAPACITY;
}

void init_int_array_wcap(struct int_array *arr, int capacity)
{
    arr->items = malloc(sizeof(arr->items[0]) * capacity);
    if (arr->items == NULL) {
        printf("Error allocating memory for int_array\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = capacity;
}

void append_int_array(struct int_array *arr, int item)
{
    if (arr->capacity == 0) {
        init_int_array(arr);
    } else if (arr->size >= arr->capacity) {
        arr->items = realloc(arr->items, 2 * arr->capacity * sizeof(arr->items[0]));
        if (arr->items == NULL) {
            printf("Error allocating memory for int_array\n");
            exit(1);
        }
        arr->capacity *= 2;
    }
    arr->items[arr->size] = item;
    arr->size++;
}

typedef struct char_array {
    char *items;
    int size;
    int capacity;
} char_array_t;

int main(void)
{
    int_array_t arr;
    init_int_array_wcap(&arr, 4);

    append_int_array(&arr, 1);
    append_int_array(&arr, 2);
    append_int_array(&arr, 3);
    append_int_array(&arr, 4);
    append_int_array(&arr, 5);

    printf("Dynamic array size: %d\n", arr.size);
    printf("Dynamic array capacity: %d\n", arr.capacity);
    for (int i = 0; i < arr.size; i++) {
        printf("Element %d: %d\n", i, arr.items[i]);
    }

    char_array_t arr2 = {0};
    DA_INIT(&arr2); // or skip... doesn't matter as long as initialized as = {0}
    printf("Dynamic array size: %d\n", arr2.size);
    printf("Dynamic array capacity: %d\n", arr2.capacity);
    DA_APPEND(&arr2, 'p');
    DA_APPEND(&arr2, 'u');
    DA_APPEND(&arr2, 't');
    DA_APPEND(&arr2, 'o');
    DA_APPEND(&arr2, '\n');
    DA_APPEND(&arr2, '\0');

    printf("Dynamic array size: %d\n", arr2.size);
    printf("Dynamic array capacity: %d\n", arr2.capacity);
    for (int i = 0; i < arr2.size - 1; i++) {
        printf("%c", arr2.items[i]);
    }
}
