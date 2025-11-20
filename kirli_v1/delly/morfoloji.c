#include <stdio.h>
#include <string.h>
#include "morfoloji.h"

void morfoloji_kok_bul(const char* kelime, char* kok)
{
    int len = strlen(kelime);

    for (int i = len; i > 0; i--)
    {
        if (kelime[i] == 'm' || kelime[i] == 'n' || kelime[i] == 's' || kelime[i] == 'z')
            continue;

        strncpy(kok, kelime, i);
        kok[i] = '\0';
        return;
    }

    strcpy(kok, kelime);
}

void morfoloji_coz(const char* kelime)
{
    char kok[64];
    morfoloji_kok_bul(kelime, kok);

    printf("[MORFO] Kelime: %s\n", kelime);
    printf("[MORFO] Kök   : %s\n", kok);
}
