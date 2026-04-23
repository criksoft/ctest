#include <stdio.h>

typedef struct vector {
    int x, y;
} vector_t;

vector_t vector_add(vector_t v1, vector_t v2)
{
    vector_t result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

vector_t vector_mul(vector_t v1, vector_t v2)
{
    vector_t result;
    result.x = v1.x * v2.x;
    result.y = v1.y * v2.y;
    return result;
}

// Helper for token pasting
#define PASTE_TOKENS(a, b) a##b
// The renamed macro
#define VOP(left, op_name, right) PASTE_TOKENS(vector_, op_name)(left, right)

int main()
{
    vector_t a = {2, 3};
    vector_t b = {4, 5};
    vector_t c;
    vector_t d;

    // Usage of addition with VOP
    // Expands to vector_add(a, b)
    c = VOP(a, add, b);

    // Usage of multiplication with VOP
    // Expands to vector_mul(a, b)
    d = VOP(a, mul, b);

    // Nested usage with mixed operations: a * (a + b)
    // Expands to vector_mul(a, vector_add(a, b))
    vector_t e = VOP(a, mul, VOP(a, add, b));

    printf("a = {%d, %d}\n", a.x, a.y);
    printf("b = {%d, %d}\n", b.x, b.y);
    printf("c = a + b = {%d, %d}\n", c.x, c.y);       // Expected: {6, 8}
    printf("d = a * b = {%d, %d}\n", d.x, d.y);       // Expected: {8, 15}
    printf("e = a * (a + b) = {%d, %d}\n", e.x, e.y); // Expected: {12, 24}

    return 0;
}
