#include <stdio.h>
#include <string.h>
#include "sozdizimi.h"

void sozdizimi_coz(const char* metin)
{
    printf("[SÖZDÝZÝMÝ] Çözümleme: %s\n", metin);

    int kelimeler = 1;

    for (int i = 0; metin[i]; i++)
        if (metin[i] == ' ') kelimeler++;

    printf("[SÖZDÝZÝMÝ] Kelime sayýsý: %d\n", kelimeler);
}
