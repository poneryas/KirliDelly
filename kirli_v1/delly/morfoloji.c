#include "morfoloji.h"
#include <stdio.h>
#include <string.h>

void morfolojik_cozumle(const unsigned char* metin)
{
    // Çok basit þablon
    printf("[MORFO] Kök+Ek analizi: ");

    // Örnek: son 3 byte ? ek varsayýyoruz
    int len = strlen((const char*)metin);

    if (len <= 3) {
        printf("kök=%s ek=YOK\n", metin);
        return;
    }

    printf("kök=");
    for (int i = 0; i < len - 3; i++) printf("%c", metin[i]);

    printf(" ek=");
    for (int i = len - 3; i < len; i++) printf("%c", metin[i]);

    printf("\n");
}
