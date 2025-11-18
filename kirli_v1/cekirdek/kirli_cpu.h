#ifndef KIRLI_CPU_H
#define KIRLI_CPU_H

extern unsigned char RAM[65536];
extern unsigned int PS;

extern unsigned char A, B, C, D, Z;

void ram_yukle(const char* dosya);

#endif
