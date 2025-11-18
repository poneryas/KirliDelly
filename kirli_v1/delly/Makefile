CC=gcc
CFLAGS=-O2 -Wall -c

SRC=morfoloji.c anlam.c sozdizimi.c bellek/bellek.c
OBJ=$(SRC:.c=.o)

OUT=libdelly.a

all: $(OUT)

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

bellek/%.o: bellek/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) bellek/*.o $(OUT)
