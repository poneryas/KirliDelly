#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kirli_core.h"
#include "kirli_cpu.h"
#include "../delly/bellek/bellek.h"

// Bellek ve yazmaçlar
unsigned char RAM[65536];
unsigned char A = 0;
unsigned char B = 0;
unsigned char C = 0;
unsigned char D = 0;

unsigned short PC = 0;  // Program sayacı
unsigned char Z = 0;    // Sıfır bayrağı

// OP Kodları
#define OP_NOP     0
#define OP_AL      1
#define OP_EKLE    2
#define OP_METIN   10
#define OP_MORFO   11
#define OP_BITIR   255

// -------------------- OPERASYONLAR --------------------

void op_no_op() {
    // hiçbir şey yapma
}

void op_al() {
    unsigned char r = RAM[PC++];
    unsigned char v = RAM[PC++];

    switch (r) {
        case 0: A = v; break;
        case 1: B = v; break;
        case 2: C = v; break;
        case 3: D = v; break;
    }

    printf("[AL] R%d := %d\n", r, v);
}

void op_ekle() {
    unsigned char r1 = RAM[PC++];
    unsigned char r2 = RAM[PC++];

    unsigned char* R1 = NULL;
    unsigned char* R2 = NULL;

    switch (r1) {
        case 0: R1 = &A; break;
        case 1: R1 = &B; break;
        case 2: R1 = &C; break;
        case 3: R1 = &D; break;
    }

    switch (r2) {
        case 0: R2 = &A; break;
        case 1: R2 = &B; break;
        case 2: R2 = &C; break;
        case 3: R2 = &D; break;
    }

    *R1 += *R2;

    printf("[EKLE]\n");
}

void op_metin() {
    printf("[METIN] ");

    while (RAM[PC] != 0) {
        putchar(RAM[PC]);
        PC++;
    }
    PC++; // null byte geç

    putchar('\n');
}

void op_morfo() {
    printf("[MORFO] ");

    while (RAM[PC] != 0) {
        putchar(RAM[PC]);
        PC++;
    }
    PC++;

    printf("\n");
}

void op_bitir() {
    printf("[BITIR] Program sonu\n");
    exit(0);
}

// -------------------- CPU ÇALIŞTIRICI --------------------

void cpu_yurut() {
    printf("[KIRLI CPU] başlatıldı.\n");

    while (1) {
        unsigned char kod = RAM[PC++];

        switch (kod) {
            case OP_NOP:   op_no_op();   break;
            case OP_AL:    op_al();      break;
            case OP_EKLE:  op_ekle();    break;
            case OP_METIN: op_metin();   break;
            case OP_MORFO: op_morfo();   break;
            case OP_BITIR: op_bitir();   break;

            default:
                printf("[HATA] Bilinmeyen opcode: %u\n", kod);
                exit(1);
        }
    }
}
