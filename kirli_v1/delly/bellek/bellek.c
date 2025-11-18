#include "bellek.h"
#include <string.h>

unsigned char delly_bellek[4096];

void bellek_yaz(const unsigned char* d)
{
    strcpy((char*)delly_bellek, (const char*)d);
}

const unsigned char* bellek_oku()
{
    return delly_bellek;
}
