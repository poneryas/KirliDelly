#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tr_ascii/tr_char.h"

// KIRLI DERLEYICI
// Türkçe komutları bellek.bin dosyasına çevirir

#define OP_NOP     0
#define OP_AL      1
#define OP_EKLE    2
#define OP_METIN   10
#define OP_MORFO   11
#define OP_BITIR   255

void derle_dosya(const char* giris, const char* cikis)
{
    FILE* g = fopen(giris, "r");
    if (!g) {
        printf("Dosya bulunamadı: %s\n", giris);
        exit(1);
    }

    FILE* o = fopen(cikis, "wb");
    if (!o) {
        printf("Çıkış dosyası açılamadı: %s\n", cikis);
        exit(1);
    }

    char komut[64];

    while (fscanf(g, "%63s", komut) == 1)
    {
        // AL R V
        if (strcmp(komut, "AL") == 0) {

            unsigned char r, v;
            if (fscanf(g, "%hhu %hhu", &r, &v) != 2) {
                printf("AL komutu hatalı.\n");
                exit(1);
            }

            fputc(OP_AL, o);
            fputc(r, o);
            fputc(v, o);
        }

        // EKLE R1 R2
        else if (strcmp(komut, "EKLE") == 0) {

            unsigned char r1, r2;
            if (fscanf(g, "%hhu %hhu", &r1, &r2) != 2) {
                printf("EKLE komutu hatalı.\n");
                exit(1);
            }

            fputc(OP_EKLE, o);
            fputc(r1, o);
            fputc(r2, o);
        }

        // METIN "..."
        else if (strcmp(komut, "METIN") == 0) {

            char buf[256];
            if (fscanf(g, " \"%255[^\"]\"", buf) != 1) {
                printf("METIN komutu hatalı.\n");
                exit(1);
            }

            fputc(OP_METIN, o);

            int i = 0;
            while (buf[i]) {
                int adv = 1;
                unsigned char t = tr_normalize(&buf[i], &adv);
                fputc(t, o);
                i += adv;
            }

            fputc(0, o); // string sonu
        }

        // MORFO "..."
        else if (strcmp(komut, "MORFO") == 0) {

            char buf[256];
            if (fscanf(g, " \"%255[^\"]\"", buf) != 1) {
                printf("MORFO komutu hatalı.\n");
                exit(1);
            }

            fputc(OP_MORFO, o);

            for (int i = 0; buf[i]; i++)
                fputc((unsigned char)buf[i], o);

            fputc(0, o);
        }

        // BITIR
        else if (strcmp(komut, "BITIR") == 0) {
            fputc(OP_BITIR, o);
        }

        else {
            printf("Tanımlanmayan komut: %s\n", komut);
            exit(1);
        }
    }

    fclose(g);
    fclose(o);

    printf("[DERLEYICI] %s oluşturuldu.\n", cikis);
}

int main()
{
    derle_dosya("programlar/test.krl", "bellek.bin");
    return 0;
}
