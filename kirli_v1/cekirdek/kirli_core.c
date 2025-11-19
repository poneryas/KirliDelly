#include <stdlib.h>
#include <stdio.h>
#include "kirli_core.h"

// DELLY beyin modülleri
#include "../delly/morfoloji.h"
#include "../delly/anlam.h"
#include "../delly/sozdizimi.h"
#include "../delly/bellek/bellek.h"

extern unsigned char RAM[];
extern unsigned int  PS;
extern unsigned char A, B, C, D, Z;

void op_no_op()
{
    PS += 1;
}

void op_al()
{
    unsigned char r = RAM[PS + 1];
    unsigned char v = RAM[PS + 2];

    switch (r) {
    case 0: A = v; break;
    case 1: B = v; break;
    case 2: C = v; break;
    case 3: D = v; break;
    }

    Z = (v == 0);
    PS += 3;
}

void op_ekle()
{
    unsigned char* hedef;
    switch (RAM[PS + 1]) {
    case 0: hedef = &A; break;
    case 1: hedef = &B; break;
    case 2: hedef = &C; break;
    case 3: hedef = &D; break;
    default: hedef = &A; break;
    }

    unsigned char v;
    switch (RAM[PS + 2]) {
    case 0: v = A; break;
    case 1: v = B; break;
    case 2: v = C; break;
    case 3: v = D; break;
    default: v = 0;
    }

    *hedef += v;
    Z = (*hedef == 0);

    PS += 3;
}

void op_metin()
{
    printf("[ÝÞLEMCÝ] METÝN: ");

    int i = PS + 1;
    while (RAM[i] != 0) {
        printf("%c", RAM[i]);
        i++;
    }
    printf("\n");

    // METÝN komutundan sonra PS'yi metnin sonuna taþý
    int j = PS + 1;
    while (RAM[j] != 0) j++;

    PS = j + 1;
}

void op_morfo()
{
    printf("[ÝÞLEMCÝ] MORFO tetiklendi.\n");

    // METÝN komutundan gelen son string RAM üzerinde hala duruyor
    const char* m = (const char*)&RAM[PS + 1];

    // DELLY BEYNÝ DEVREYE GÝRÝYOR
    morfoloji_coz(m);
    anlam_coz(m);
    sozdizimi_coz(m);
    bellek_yaz(m);

    PS += 1;
}

void op_bitir()
{
    printf("[ÝÞLEMCÝ] Program bitti.\n");
    exit(0);
}
