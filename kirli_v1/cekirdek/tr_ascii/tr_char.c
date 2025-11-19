#include "tr_char.h"

// Türkçe karakterleri tek bayta indirger.
// Ama UTF-8 ASCII olmayan karakterlerde adv (ileri atlama) belirler.

unsigned char tr_normalize(const char* s, int* adv)
{
    unsigned char c = (unsigned char)s[0];

    // ASCII ise deðiþmeden dön
    if (c < 128) {
        *adv = 1;
        return c;
    }

    unsigned char c2 = (unsigned char)s[1];

    // ç: C3 A7
    if (c == 0xC3 && c2 == 0xA7) { *adv = 2; return 0x80; }
    // Ç: C3 87
    if (c == 0xC3 && c2 == 0x87) { *adv = 2; return 0x81; }

    // ð: C4 9F
    if (c == 0xC4 && c2 == 0x9F) { *adv = 2; return 0x82; }
    // Ð: C4 9E
    if (c == 0xC4 && c2 == 0x9E) { *adv = 2; return 0x83; }

    // ý: C4 B1
    if (c == 0xC4 && c2 == 0xB1) { *adv = 2; return 0x84; }
    // Ý: C4 B0
    if (c == 0xC4 && c2 == 0xB0) { *adv = 2; return 0x85; }

    // ö: C3 B6
    if (c == 0xC3 && c2 == 0xB6) { *adv = 2; return 0x86; }
    // Ö: C3 96
    if (c == 0xC3 && c2 == 0x96) { *adv = 2; return 0x87; }

    // þ: C5 9F
    if (c == 0xC5 && c2 == 0x9F) { *adv = 2; return 0x88; }
    // Þ: C5 9E
    if (c == 0xC5 && c2 == 0x9E) { *adv = 2; return 0x89; }

    // ü: C3 BC
    if (c == 0xC3 && c2 == 0xBC) { *adv = 2; return 0x8A; }
    // Ü: C3 9C
    if (c == 0xC3 && c2 == 0x9C) { *adv = 2; return 0x8B; }

    // Tanýnmayan karakter:
    *adv = 1;
    return '?';
}
