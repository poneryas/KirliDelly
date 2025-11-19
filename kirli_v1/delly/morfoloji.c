#include <stdio.h>
#include <string.h>
#include "morfoloji.h"

void morfoloji_coz(const char* metin)
{
    printf("[MORFO] Kelime: %s\n", metin);

    int len = strlen(metin);

    if (len > 3) {
        printf("[MORFO] Kök: ");
        for (int i = 0; i < len - 2; i++)
            putchar(metin[i]);

        printf("\n[MORFO] Ek: %c%c\n", metin[len - 2], metin[len - 1]);
    }
    else {
        printf("[MORFO] Kök: %s\n", metin);
        printf("[MORFO] Ek yok.\n");
    }
}
