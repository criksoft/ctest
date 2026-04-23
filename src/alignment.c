#include <stdalign.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

typedef struct adios {
    u64 a;
    u64 b;
    u64 d;
    u8 c;
} adios_t;

typedef struct optimized {
    i64 a;
    i32 c;
} optimized_t;

typedef union lalaland {
    i64 a;
    i32 b;
} lalaland_t;

typedef struct hola {
    u16 c;
    u64 b;
    u8 a;
    adios_t e;
    u8 d;
} hola_t;

typedef struct woof {
    u8 a;
    adios_t b;
    u8 c;
    adios_t d;
} woof_t;

typedef struct fam {
    int a;
    double b[];
} fam_t;

int main(void)
{
    char *p = "hola";

    printf("hola_t sizeof=%lu, alignof=%lu\n", sizeof(hola_t), _Alignof(hola_t));
    printf("hola_t a=%lu, b=%lu, c=%lu, d=%lu, e=%lu\n", offsetof(hola_t, a), offsetof(hola_t, b), offsetof(hola_t, c),
           offsetof(hola_t, d), offsetof(hola_t, e));

    printf("adios_t sizeof=%lu, alignof=%lu\n", sizeof(adios_t), _Alignof(adios_t));
    printf("adios_t a=%lu, b=%lu, c=%lu, d=%lu\n", offsetof(adios_t, a), offsetof(adios_t, b), offsetof(adios_t, c),
           offsetof(adios_t, d));

    printf("__int128 sizeof=%lu, alignof=%lu\n", sizeof(__int128), _Alignof(__int128));

    printf("woof_t sizeof=%lu, alignof=%lu\n", sizeof(woof_t), _Alignof(woof_t));
    printf("lalaland_t sizeof=%lu, alignof=%lu\n", sizeof(lalaland_t), _Alignof(lalaland_t));

    printf("max_align_t sizeof=%lu, alignof=%lu\n", sizeof(max_align_t), alignof(max_align_t));

    printf("FAM sizeof=%lu, alignof=%lu offsetof_b=%lu\n", sizeof(fam_t), _Alignof(fam_t), offsetof(fam_t, b));
    alignas(1024) fam_t f;
    printf("fam_t sizeof=%lu, alignof=%lu addr=%p\n", sizeof(f), _Alignof(f), &f); // 0x16cef7120

    printf("f16 sizeof=%lu, alignof=%lu\n", sizeof(f16), _Alignof(f16));
}
