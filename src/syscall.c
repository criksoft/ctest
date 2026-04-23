#include <stddef.h>

int main(void)
{
    const char msg[] = "Hello from pure syscall!\n";

    register long x0 asm("x0") = 1; // fd = 1 (stdout)
    register long x1 asm("x1") = (long)msg;
    register long x2 asm("x2") = sizeof(msg) - 1;
    register long x16 asm("x16") = 0x2000004; // write syscall

    asm volatile(
        "svc #0x80"
        : "+r"(x0) // x0 is read-write: input = fd, output = return value
        : "r"(x1), "r"(x2), "r"(x16)
        : "memory");

    long ret = x0; // x0 now contains the syscall return value

    return 0;
}
