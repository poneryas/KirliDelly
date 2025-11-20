#ifndef KIRLI_CORE_H
#define KIRLI_CORE_H

extern unsigned char RAM[65536];

extern unsigned char A;
extern unsigned char B;
extern unsigned char C;
extern unsigned char D;

extern unsigned short PC;
extern unsigned char Z;

void cpu_yurut();

// operasyonlar
void op_no_op();
void op_al();
void op_ekle();
void op_metin();
void op_morfo();
void op_bitir();

#endif
