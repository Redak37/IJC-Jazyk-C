/*
 *  Soubor:      io.h
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#ifndef _IO_H_
#define _IO_H_


#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

//Zpise jedno slovo maximalni delky max-1 ze streamu do rezezce s, kde slovo je vse oddelene pomoci white-space a vrati jeho delku, pripadne EOF
int get_word(char *s, int max, FILE *f);


#endif
