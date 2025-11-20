ROOT := $(shell pwd)

all:
	$(shell cd $(ROOT)/derleyici && gcc -O2 -Wall kirli_assembler.c tr_ascii/tr_char.c -o kirli_asm)
	$(shell cp $(ROOT)/derleyici/kirli_asm $(ROOT)/kirli_asm)
	$(shell cd $(ROOT)/delly && gcc -c morfoloji.c -o morfoloji.o)
	$(shell cd $(ROOT)/delly && gcc -c anlam.c -o anlam.o)
	$(shell cd $(ROOT)/delly && gcc -c sozdizimi.c -o sozdizimi.o)
	$(shell cd $(ROOT)/delly && gcc -c bellek/bellek.c -o bellek/bellek.o)
	$(shell cd $(ROOT)/delly && gcc -c bellek/hafiza.c -o bellek/hafiza.o)
	$(shell cd $(ROOT)/delly && ar rcs libdelly.a morfoloji.o anlam.o sozdizimi.o bellek/bellek.o bellek/hafiza.o)
	$(shell cd $(ROOT)/cekirdek && gcc -O2 -Wall kirli_cpu.c kirli_core.c tr_ascii/tr_char.c ../delly/libdelly.a -o kirli_cpu)
	$(shell cp $(ROOT)/cekirdek/kirli_cpu $(ROOT)/kirli_cpu)
	@echo "🎉 Tüm sistem başarıyla derlendi."

clean:
	$(shell rm -f $(ROOT)/derleyici/kirli_asm)
	$(shell rm -f $(ROOT)/kirli_asm)
	$(shell rm -f $(ROOT)/cekirdek/kirli_cpu)
	$(shell rm -f $(ROOT)/kirli_cpu)
	$(shell rm -f $(ROOT)/delly/*.o)
	$(shell rm -f $(ROOT)/delly/bellek/*.o)
	$(shell rm -f $(ROOT)/delly/libdelly.a)
	@echo "🧹 Temizlik tamam."
