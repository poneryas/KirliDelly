#ifndef HAFIZA_H
#define HAFIZA_H

int hafiza_var_mi(const char* kelime);
int hafiza_oku(const char* kelime, char* anlam_out, char* tur_out);
void hafiza_yaz(const char* kelime, const char* tur, const char* anlam);

void hafiza_yukle();
void hafiza_kaydet();

#endif
