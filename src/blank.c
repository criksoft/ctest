int printf(const char *, ...);

// variables (globals)
// types definitions
// function declaration/definitions aka impl

int x = 0;

struct person {
    int field1;
    char field2;
    double field3;
    int *field4;
};

union weird {
    int a;
    float b;
};

enum thing {
    ZERO,
    ONE,
    TWO,
};

typedef unsigned long index_size_t;
typedef struct person person_t;

void fn1(struct person p)
{
    // do something with struct person
}

void fn2(person_t p)
{
    // do something with person_t
}

int main(int argc, char *argv[])
{
    int n = printf("hi bitch\n");
    printf("I wrote %d chars\n", n);
}

// Preprocess -> (Compile -> Assemble) -> Link Other/System Object Files + Executable Format
