# Makefile
CC = gcc

all: dfaout

dfaout: dfa.c
	$(CC) $(CFLAGS) -o dfaout dfa.c

%.out: %.input
	./dfaout < $<1 > $@

clean:
	rm -f dfaout