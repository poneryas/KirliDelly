#include "kirli_core.h"
#include <stdio.h>

extern unsigned char RAM[];
extern unsigned int PS;
extern unsigned char A, B, C, D, Z;

void op_no_op()
{
    PS += 1;
}

void op_al()
{
    unsigned char reg = RAM[PS + 1];
    unsigned char val = RAM[PS + 2];

    switch (reg) {
    case 0: A = val; break;
    case 1: B = val; break;
    case 2: C = val; break;
    case 3: D = val; break;
    }
    Z = (val == 0);
    PS += 3;
}

void op_ekle()
{
    unsigned char r1 = RAM[PS + 1];
    unsigned char r2 = RAM[PS + 2];

    unsigned char* x;

    switch (r1) {
    case 0: x = &A; break;
    case 1: x = &B; break;
    case 2: x = &C; break;
    case 3: x = &D; break;
    default: x = &A;
    }

    unsigned char val;

    switch (r2) {
    case 0: val = A; break;
    case 1: val = B; break;
    case 2: val = C; break;
    case 3: val = D; break;
    default: val = 0;
    }

    *x = *x + val;
    Z = (*x == 0);
    PS += 3;
}

void op_metin()
{
    printf("[CPU] METÝN verisi: ");

    int i = PS + 1;
    while (RAM[i] != 0) {
        printf("%c", RAM[i]);
        i++;
    }
    printf("\n");

    // metin sonunu bul
    while (RAM[PS] != 0) PS++;
    PS += 1;
}

void op_morfo()
{
    printf("[CPU] MORFO analizi tetiklendi.\n");
    PS += 1;
}

void op_bitir()
{
    printf("[CPU] Program bitti.\n");
    PS += 1;
}
