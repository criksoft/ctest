#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

// THE JAVA WAY OF CRAP
// class Person {
//     String name;
//     int age;
//     boolean sex;
// }

void fn()
{
    int x;
    int *p = NULL; // uninit memory ???????
    *p = 123;
    p = malloc(10);

    if (p != NULL) {
        // don't do anything
    }
    // int *p = (int*)0x0129382;
    printf("%d\n", x);
}

struct person {
    char name[20];
    int age;
    char sex;
};

union ip_address {
    char octets[4];
    int ip;
};

enum json_node_type {
    JSON_TYPE_INT,
    JSON_TYPE_DOUBLE,
    JSON_TYPE_STRING,
};
// const int JSON_TYPE_INT = 0;
// const int JSON_TYPE_DOUBLE = 1;
// const int JSON_TYPE_STRING = 2;

enum json_result_type {
    JSON_SUCCESS,
    JSON_ERROR_INT_OUT_OF_RANGE,
};

struct json_node {
    // int tag; // 0 int, 1 double, 2 boolean, 3 string, 4 object, 5 array, 6 null
    enum json_node_type type;
    union {
        int json_int;
        double json_double;
        bool json_bool;
        char *json_string;
        struct json_node *json_object;
        struct json_node *json_array;
    };
    union {
        int another_int;
        double another_double;
    };
};

void fn2(void)
{
    struct json_node node;
    node.type = JSON_TYPE_INT;
    node.json_int = 100;
    node.another_int = 200;
}

int set_json_int(struct json_node *node, int value)
{
    if (value < 0) {
        return JSON_ERROR_INT_OUT_OF_RANGE;
    }
    node->type = JSON_TYPE_INT;
    node->json_int = value;
    return JSON_SUCCESS;
}

struct json_node_naive {
    char *field_name;
    int *json_int;
    bool *json_bool;
    char *json_string;
    struct json_node_naive *json_object;
    struct json_node_naive *json_array;
};

union weird_stuff {
    int my_int;
    double my_double;
};

int main(void);

void _start()
{
    // lots of OS code here

    int result = main();
    syscall(SYS_exit, result);
}

// array -> contiguous memory block containing elements of same type
// struct -> contiguous memory block containing fields of different type
// union -> single memory block containing different fields of different types
int main(void)
{
    union ip_address addr;

    printf("sizeof: %lu\n", sizeof(struct json_node));
    printf("sizeof: %lu\n", sizeof(struct json_node_naive));

    addr.octets[0] = 123;
    addr.octets[1] = 123;
    addr.octets[2] = 22;
    addr.octets[3] = 99;

    printf("%d\n", JSON_TYPE_INT + JSON_TYPE_DOUBLE);
}
