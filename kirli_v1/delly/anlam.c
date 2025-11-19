#include <stdio.h>
#include <string.h>
#include "anlam.h"

void anlam_coz(const char* metin)
{
    printf("[ANLAM] Cümle: %s\n", metin);

    if (strstr(metin, "gel"))
        printf("[ANLAM] Eylem tespit edildi: gelmek\n");

    if (strstr(metin, "sev"))
        printf("[ANLAM] Duygu tespit edildi: sevmek\n");

    if (strstr(metin, "git"))
        printf("[ANLAM] Eylem tespit edildi: gitmek\n");
}
