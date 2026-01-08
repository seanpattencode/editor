# Makefile for single-file uEmacs
CC = gcc
CFLAGS = -O2 -Wall
DEFINES = -DAUTOCONF -DPOSIX -DUSG -D_XOPEN_SOURCE=600 -D_GNU_SOURCE
LIBS = -lcurses

em: uemacs.c
	$(CC) $(CFLAGS) $(DEFINES) -o $@ $< $(LIBS)

clean:
	rm -f em

.PHONY: clean
