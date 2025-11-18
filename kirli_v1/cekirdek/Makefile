CC=gcc
CFLAGS=-O2 -Wall
SRC=kirli_cpu.c kirli_core.c tr_ascii/tr_char.c
OUT=kirli_cpu

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
