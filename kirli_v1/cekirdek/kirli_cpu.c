#include "kirli_cpu.h"
#include "kirli_core.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char RAM[65536];
unsigned int  PS = 0;
unsigned char A = 0, B = 0, C = 0, D = 0, Z = 0;

void ram_yukle(const char* dosya)
{
    FILE* f = fopen(dosya, "rb");
    if (!f) {
        printf("bellek.bin bulunamadý\n");
        exit(1);
    }

    size_t okunan = fread(RAM, 1, 65536, f);
    if (okunan == 0) {
        printf("bellek.bin okunamadý.\n");
        exit(1);
    }

    fclose(f);

    printf("[bilgi] bellek.bin RAM’e yüklendi.\n");
}

int main()
{
    ram_yukle("bellek.bin");

    while (1) {
        unsigned char op = RAM[PS];

        switch (op) {
        case OP_NOP:   op_no_op(); break;
        case OP_AL:    op_al(); break;
        case OP_EKLE:  op_ekle(); break;
        case OP_METIN: op_metin(); break;
        case OP_MORFO: op_morfo(); break;
        case OP_BITIR: op_bitir(); break;

        default:
            printf("HATA: bilinmeyen opcode %d PS=%d\n", op, PS);
            exit(1);
        }
    }

    return 0;
}
