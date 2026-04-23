#include <stdio.h>

int main(void)
{
    char templ[5] = { 0xF0, 0x9F, 0x98, 0x8A, 0 };
    printf(templ, 1024);
}
