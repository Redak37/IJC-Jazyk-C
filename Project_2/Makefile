#/*
# *  Soubor:      Makefile
# *  Řešení:      IJC-DU2
# *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
# *  Přeloženo:   gcc 6.4.0
# *  Datum:       22.4.2018
# */

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -O2
TARGETS = libhtab.a libhtab.so tail tail2 wordcount wordcount-dynamic

MODULES_A = htab_bucker_count.o\
	    htab_clear.o\
	    htab_find.o\
	    htab_foreach.o\
	    htab_free.o\
	    htab_init.o\
	    htab_lookup_add.o\
	    htab_move.o\
	    htab_remove.o\
	    htab_size.o\
	    htab_hash_function.o

MODULES_SO = htab_bucker_count-s.o\
	     htab_clear-s.o\
	     htab_find-s.o\
	     htab_foreach-s.o\
	     htab_free-s.o\
	     htab_init-s.o\
	     htab_lookup_add-s.o\
	     htab_move-s.o\
	     htab_remove-s.o\
	     htab_size-s.o\
	     htab_hash_function-s.o

all: $(TARGETS)

tail: tail.o

tail2: tail2.o
	g++ -std=c++11 -pedantic -Wall -Wextra -o tail2 tail2.o

wordcount: io.o wordcount.o
	$(CC) $(CFLAGS) -o wordcount wordcount.o io.o libhtab.a

wordcount-dynamic: io.o wordcount.o
	$(CC) $(CFLAGS) -o wordcount-dynamic wordcount.o io.o libhtab.so

libhtab.a: $(MODULES_A)
	ar rcs libhtab.a $(MODULES_A)

libhtab.so: $(MODULES_SO)
	$(CC) -shared -o libhtab.so $(MODULES_SO)

%-s.o: %.c
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

clean:
	@rm -f *.o $(TARGETS)

zip:
	rm xducho07.zip
	zip xducho07.zip *.c *.h *.cc Makefile
