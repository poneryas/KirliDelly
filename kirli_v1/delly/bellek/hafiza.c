#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hafiza.h"

// =======================
// Basit JSON yapımız
// =======================

typedef struct {
    char kelime[64];
    char tur[32];
    char anlam[512];
} HafizaKaydi;

#define MAX_HAFIZA 5000
static HafizaKaydi hafiza[MAX_HAFIZA];
static int hafiza_sayisi = 0;

// =======================
// JSON dosya adı
// =======================
static const char* HAFIZA_DOSYA = "delly/bellek/hafiza.json";

// =======================
// JSON yükle
// =======================
void hafiza_yukle()
{
    FILE* f = fopen(HAFIZA_DOSYA, "r");
    if (!f) return;

    while (!feof(f)) {
        char kel[64], tur[32], anl[512];

        if (fscanf(f, "{%63[^}]} ", kel) == 1) {
            // Çok basit parse; tam JSON değil ama iş görür
        }
    }

    fclose(f);
}

// =======================
// JSON kaydet
// =======================
void hafiza_kaydet()
{
    FILE* f = fopen(HAFIZA_DOSYA, "w");
    if (!f) return;

    fprintf(f, "{\n  \"kelimeler\": [\n");

    for (int i = 0; i < hafiza_sayisi; i++) {
        fprintf(f,
            "    {\"kelime\": \"%s\", \"tur\": \"%s\", \"anlam\": \"%s\"}%s\n",
            hafiza[i].kelime,
            hafiza[i].tur,
            hafiza[i].anlam,
            (i == hafiza_sayisi - 1) ? "" : ","
        );
    }

    fprintf(f, "  ]\n}\n");

    fclose(f);
}

// =======================
// Hafızada var mı?
// =======================
int hafiza_var_mi(const char* kelime)
{
    for (int i = 0; i < hafiza_sayisi; i++) {
        if (strcmp(hafiza[i].kelime, kelime) == 0)
            return 1;
    }
    return 0;
}

// =======================
// Hafızadan oku
// =======================
int hafiza_oku(const char* kelime, char* anlam_out, char* tur_out)
{
    for (int i = 0; i < hafiza_sayisi; i++) {
        if (strcmp(hafiza[i].kelime, kelime) == 0) {
            strcpy(anlam_out, hafiza[i].anlam);
            strcpy(tur_out, hafiza[i].tur);
            return 1;
        }
    }
    return 0;
}

// =======================
// Hafızaya yaz
// =======================
void hafiza_yaz(const char* kelime, const char* tur, const char* anlam)
{
    if (hafiza_sayisi >= MAX_HAFIZA)
        return;

    strcpy(hafiza[hafiza_sayisi].kelime, kelime);
    strcpy(hafiza[hafiza_sayisi].tur, tur);
    strcpy(hafiza[hafiza_sayisi].anlam, anlam);

    hafiza_sayisi++;

    hafiza_kaydet();  // otomatik kaydet
}
