#include <stdio.h>
#include <string.h>
#include "sozdizimi.h"

void sozdizimi_coz(const char* metin)
{
    printf("[SÃZDÃZÃMÃ] ÃÃ¶zÃ¼mleme: %s\n", metin);

    int kelimeler = 1;

    for (int i = 0; metin[i]; i++)
        if (metin[i] == ' ') kelimeler++;

    printf("[SÃZDÃZÃMÃ] Kelime sayÃ½sÃ½: %d\n", kelimeler);
}
