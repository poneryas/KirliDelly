#ifndef KIRLI_CORE_H
#define KIRLI_CORE_H

#define OP_NOP     0
#define OP_AL      1
#define OP_EKLE    2
#define OP_METIN   10
#define OP_MORFO   11
#define OP_BITIR   255

void op_no_op();
void op_al();
void op_ekle();
void op_metin();
void op_morfo();
void op_bitir();

#endif
