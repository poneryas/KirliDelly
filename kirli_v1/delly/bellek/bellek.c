#include <stdio.h>
#include <string.h>
#include "bellek.h"

char bellek[10][256];
int sayac = 0;

void bellek_yaz(const char* m)
{
    if (sayac < 10) {
        strcpy(bellek[sayac], m);
        sayac++;
    }
}

void bellek_goster()
{
    for (int i = 0; i < sayac; i++)
        printf("[BELLEK] %d: %s\n", i + 1, bellek[i]);
}
