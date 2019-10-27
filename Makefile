##################################################
# make init: create build and bin directories
## NOTE: only need to do this once
# make clean: clean build and bin
# make: compile the program
# make run: run the program
##################################################

IDIR= include
CC= gcc
CFLAGS= `sdl2-config --libs --cflags` -I. -Wall -lSDL2_image
_DEPS= Board.h Piece.h Point.h chessfunc.h node.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ= build/main.o build/chessfunc.o
MAKEFLAGS+= -s

default: bin/main

init:
	mkdir bin;mkdir build

build/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bin/main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	cd bin;rm main
	cd build;rm main.o;rm chessfunc.o

run:
	cd bin; ./main