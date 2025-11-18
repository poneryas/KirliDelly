#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tr_ascii/tr_char.h"

typedef struct {
    char ad[32];
    int opcode;
} KOMUT;

KOMUT komutlar[32];
int komut_say = 0;

void komut_yukle()
{
    FILE* f = fopen("komutlar.trk", "r");
    if (!f) {
        printf("komutlar.trk bulunamadý!\n");
        exit(1);
    }

    while (!feof(f)) {
        char a[32]; int k;
        if (fscanf(f, "%s %d", a, &k) == 2) {
            strcpy(komutlar[komut_say].ad, a);
            komutlar[komut_say].opcode = k;
            komut_say++;
        }
    }

    fclose(f);
}

int opcode_bul(const char* s)
{
    for (int i = 0; i < komut_say; i++) {
        if (strcmp(komutlar[i].ad, s) == 0)
            return komutlar[i].opcode;
    }
    return -1;
}

void yaz_byte(FILE* o, unsigned char b)
{
    fwrite(&b, 1, 1, o);
}

void metin_derle(FILE* o, const char* metin)
{
    int i = 0;
    while (metin[i]) {
        int adv = 1;
        unsigned char tr = tr_normalize(&metin[i], &adv);
        fwrite(&tr, 1, 1, o);
        i += adv;
    }
    unsigned char end = 0;
    fwrite(&end, 1, 1, o);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("kullanim: kirli_asm dosya.krl\n");
        return 0;
    }

    komut_yukle();

    FILE* g = fopen(argv[1], "r");
    if (!g) { printf("dosya yok\n"); return 1; }

    FILE* o = fopen("../program.bin", "wb");

    while (!feof(g))
    {
        char komut[32];
        if (fscanf(g, "%s", komut) != 1) break;

        int op = opcode_bul(komut);
        if (op < 0) {
            printf("Tanýnmayan komut: %s\n", komut);
            exit(1);
        }

        yaz_byte(o, (unsigned char)op);

        if (strcmp(komut, "AL") == 0) {
            int y, v;
            fscanf(g, "%d %d", &y, &v);
            yaz_byte(o, y);
            yaz_byte(o, v);
        }
        else if (strcmp(komut, "EKLE") == 0) {
            int a, b;
            fscanf(g, "%d %d", &a, &b);
            yaz_byte(o, a);
            yaz_byte(o, b);
        }
        else if (strcmp(komut, "METIN") == 0) {
            char buf[256];
            fscanf(g, " \"%[^\"]\"", buf);
            metin_derle(o, buf);
        }
        else if (strcmp(komut, "MORFO") == 0) {
            yaz_byte(o, 0);
        }
        else if (strcmp(komut, "BITIR") == 0) {
            // parametre yok
        }
    }

    fclose(g);
    fclose(o);

    printf("Derleme tamam.\n");

    return 0;
}
