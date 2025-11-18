CC=gcc
CFLAGS=-O2 -Wall -I./tr_ascii

SRC=kirli_assembler.c \
    tr_ascii/tr_char.c

OUT=kirli_asm

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT) *.o tr_ascii/*.o
