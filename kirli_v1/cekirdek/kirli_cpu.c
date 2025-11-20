#include <stdio.h>
#include <stdlib.h>
#include "kirli_cpu.h"
#include "kirli_core.h"

int main() {

    FILE* f = fopen("bellek.bin", "rb");
    if (!f) {
        printf("bellek.bin bulunamadı.\n");
        return 1;
    }

    size_t okunan = fread(RAM, 1, 65536, f);
    fclose(f);

    if (okunan == 0) {
        printf("bellek.bin okunamadı veya boş.\n");
        return 1;
    }

    cpu_yurut();
    return 0;
}
