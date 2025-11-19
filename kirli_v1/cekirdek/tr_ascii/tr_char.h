#ifndef TR_CHAR_H
#define TR_CHAR_H

// UTF-8 → Türkçe tek bayt dönüşümü
unsigned char tr_normalize(const char* utf8, int* adv);

#endif
