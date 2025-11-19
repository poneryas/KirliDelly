# ============================================================
# KIRLI v1 — ANA MAKEFILE
# Her şey ana dizinde derlenir ve ana dizine kopyalanır.
# ============================================================

DERLEYICI = derleyici
CEKIRDEK  = cekirdek
DELLY     = delly

ASM_BIN   = kirli_asm
CPU_BIN   = kirli_cpu
DELLY_LIB = $(DELLY)/libdelly.a

all: $(ASM_BIN) $(DELLY_LIB) $(CPU_BIN)

# ============================================================
# DERLEYİCİ
# ============================================================
$(ASM_BIN):
	@echo "[Derleyici] kirli_asm derleniyor..."
	cd $(DERLEYICI) && gcc -O2 -Wall \
		kirli_assembler.c \
		tr_ascii/tr_char.c \
		-o kirli_asm

	# Ana dizine kopyala
	cp $(DERLEYICI)/kirli_asm ./kirli_asm

# ============================================================
# DELLY (Beyin)
# ============================================================
$(DELLY_LIB):
	@echo "[DELLY] libdelly.a derleniyor..."
	cd $(DELLY) && \
		gcc -c morfoloji.c -o morfoloji.o && \
		gcc -c anlam.c     -o anlam.o     && \
		gcc -c sozdizimi.c -o sozdizimi.o && \
		gcc -c bellek/bellek.c -o bellek/bellek.o && \
		ar rcs libdelly.a morfoloji.o anlam.o sozdizimi.o bellek/bellek.o

# ============================================================
# ÇEKİRDEK
# ============================================================
$(CPU_BIN):
	@echo "[Çekirdek] kirli_cpu derleniyor..."
	cd $(CEKIRDEK) && gcc -O2 -Wall \
		kirli_cpu.c \
		kirli_core.c \
		tr_ascii/tr_char.c \
		../delly/libdelly.a \
		-o kirli_cpu

	# Ana dizine kopyala
	cp $(CEKIRDEK)/kirli_cpu ./kirli_cpu

# ============================================================
# Temizlik
# ============================================================
clean:
	rm -f kirli_asm kirli_cpu bellek.bin
	rm -f $(DELLY)/*.o $(DELLY)/bellek/*.o $(DELLY)/libdelly.a
	rm -f $(DERLEYICI)/kirli_asm
	rm -f $(CEKIRDEK)/kirli_cpu

# ============================================================
# SON
# ============================================================
