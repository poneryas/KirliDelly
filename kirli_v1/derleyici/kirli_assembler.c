#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tr_ascii/tr_char.h"

// KÝRLÝ DERLEYÝCÝ
// Türkçe komutlarý bellek.bin dosyasýna çevirir

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
        printf("Dosya bulunamadý: %s\n", giris);
        exit(1);
    }

    FILE* o = fopen(cikis, "wb");
    if (!o) {
        printf("Çýkýþ dosyasý açýlamadý: %s\n", cikis);
        exit(1);
    }

    char komut[64];

    while (fscanf(g, "%63s", komut) == 1)
    {
        if (strcmp(komut, "AL") == 0) {

            unsigned char r, v;
            if (fscanf(g, "%hhu %hhu", &r, &v) != 2) {
                printf("AL komutu hatalý.\n");
                exit(1);
            }

            fputc(OP_AL, o);
            fputc(r, o);
            fputc(v, o);
        }

        else if (strcmp(komut, "EKLE") == 0) {

            unsigned char r1, r2;
            if (fscanf(g, "%hhu %hhu", &r1, &r2) != 2) {
                printf("EKLE komutu hatalý.\n");
                exit(1);
            }

            fputc(OP_EKLE, o);
            fputc(r1, o);
            fputc(r2, o);
        }

        else if (strcmp(komut, "METIN") == 0 || strcmp(komut, "METÝN") == 0) {

            char buf[256];
            if (fscanf(g, " \"%255[^\"]\"", buf) != 1) {
                printf("METÝN komutu hatalý.\n");
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
            fputc(0, o);
        }

        else if (strcmp(komut, "MORFO") == 0) {
            fputc(OP_MORFO, o);
        }

        else if (strcmp(komut, "BITIR") == 0 || strcmp(komut, "BÝTÝR") == 0) {
            fputc(OP_BITIR, o);
        }

        else {
            printf("Tanýnmayan komut: %s\n", komut);
            exit(1);
        }
    }

    fclose(g);
    fclose(o);

    printf("[DERLEYÝCÝ] %s oluþturuldu.\n", cikis);
}

int main()
{
    // Ana dizinden çalýþýyoruz
    derle_dosya("programlar/test.krl", "bellek.bin");
    return 0;
}

