#/*
# *  Soubor:      Makefile
# *  Řešení:      IJC-DU1, příklad a)
# *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
# *  Přeloženo:   gcc 6.4.0
# *  Datum:       20.3.2018
# */

CC = gcc
M32FLAG =  
CFLAGS = -O2 -std=c99 -Wall -pedantic $(M32FLAG)
LDFLAGS = -lm $(M32FLAG)
TARGETS = primes primes-i steg-decode
SHELL = /bin/bash

all: dep $(TARGETS)

primes: error.o eratosthenes.o primes.o

primes-i: eratosthenes-i.o error.o primes-i.o

%-i.o: %.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c -o $@ $< $(LDFLAGS)

steg-decode: eratosthenes.o error.o ppm.o steg-decode.o

dep:
	@$(CC) -MM *.c >dep.list
	@cat dep.list | grep es.o | sed s/es.o/es-i.o/ >>dep.list

-include dep.list

clean:
	@rm *.o $(TARGETS) dep.list

run: all
	time ./primes
	time ./primes-i

zip:
	zip xducho07.zip *.c *.h Makefile
