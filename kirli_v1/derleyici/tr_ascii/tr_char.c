// tr ascii c
#include "tr_char.h"

// Basit UTF8 ? TÃ¼rkÃ§e tek byte dÃ¶nÃ¼Ã¾Ã¼mÃ¼
// Ã§Ã°Ã½Ã¾Ã¼Ã¶ gibi harfleri tek byte haline getirir

unsigned char tr_normalize(const char* s, int* adv)
{
    unsigned char c = (unsigned char)s[0];

    // ASCII karakterse direkt dÃ¶ndÃ¼r
    if (c < 128) {
        *adv = 1;
        return c;
    }

    unsigned char c2 = (unsigned char)s[1];

    // Ã§ (0xC3 0xA7)
    if (c == 0xC3 && c2 == 0xA7) { *adv = 2; return 0x80; }
    // Ã (0xC3 0x87)
    if (c == 0xC3 && c2 == 0x87) { *adv = 2; return 0x81; }

    // Ã° (0xC4 0x9F)
    if (c == 0xC4 && c2 == 0x9F) { *adv = 2; return 0x82; }
    // Ã
    if (c == 0xC4 && c2 == 0x9E) { *adv = 2; return 0x83; }

    // Ã½ (0xC4 0xB1)
    if (c == 0xC4 && c2 == 0xB1) { *adv = 2; return 0x84; }
    // Ã (0xC4 0xB0)
    if (c == 0xC4 && c2 == 0xB0) { *adv = 2; return 0x85; }

    // Ã¶ (0xC3 0xB6)
    if (c == 0xC3 && c2 == 0xB6) { *adv = 2; return 0x86; }
    // Ã
    if (c == 0xC3 && c2 == 0x96) { *adv = 2; return 0x87; }

    // Ã¾ (0xC5 0x9F)
    if (c == 0xC5 && c2 == 0x9F) { *adv = 2; return 0x88; }
    // Ã (0xC5 0x9E)
    if (c == 0xC5 && c2 == 0x9E) { *adv = 2; return 0x89; }

    // Ã¼ (0xC3 0xBC)
    if (c == 0xC3 && c2 == 0xBC) { *adv = 2; return 0x8A; }
    // Ã (0xC3 0x9C)
    if (c == 0xC3 && c2 == 0x9C) { *adv = 2; return 0x8B; }

    // tanÃ½nmayan karakter ? ? yap
    *adv = 1;
    return '?';
}
