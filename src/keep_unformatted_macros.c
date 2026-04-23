#include <stdio.h>
#include <unistd.h>

#define Y X Z
#define X Y Z A

#define STR(x) #x #x
#define CAT(x, y, z) x##x##y##z

#define MAIN(x)      \
    int main(void) { \
        x            \
    }

#define SAFE_MACRO(x) \
    do {              \
        printf(       \
            "Value: %d\\
n",                   \
            x);       \
    } while (0);

char newline = '\n';

MAIN(
    char msg[] = "ho\
la";
    write(STDOUT_FILENO, msg, 4);
    write(STDOUT_FILENO, &newline, 1);

    char s[] = STR(hi);
    printf("%s\n", s);

    int CAT(a, b, c);
    aabc = 10;
    printf("%d\n", aabc);

    SAFE_MACRO(5);
    fflush(stdout);

    int x = 1634496360;
    write(STDOUT_FILENO, &x, 4);
    write(STDOUT_FILENO, &newline, 1);

)
