/*
 *  Soubor:      htab.h
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       23.4.2018
 */


#ifndef _HTAB_H_
#define _HTAB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Ukazatel na hashovaci tabulku
typedef struct htab *htab_t;
//Struktura pro polozky tabulky
struct htab_listitem;

//Vytvori tabulku velikosti size, pri chybe vraci NULL
htab_t htab_init(unsigned size);
//Vytvori novou tabulku dane velikosti, premisti do ni obsah stare tabulky a starou tabulku vyprazdni
//Pri velikosti 0 vrati NULL a nic neprovede
htab_t htab_move(unsigned newsize, htab_t t2);
//Vrati pocet polozek v tabulce
unsigned htab_size(htab_t t);
//vraci velikost pole ukazatelu v tabulce
unsigned htab_bucket_count(htab_t t);
//Najde a vrati ukazatel na polozku seznamu daneho klice, pokud neexistuje prida ji a vrati, pri chybe vrati 'NULL'
struct htab_listitem *htab_lookup_add(htab_t t, char *key);
//Vraci ukazatel na polozku v tabulce pokud existuje polozka s odpovidajicim klicem, jinak 'NULL'
struct htab_listitem *htab_find(htab_t t, char *key);
//Provede pro kazdou polozku v tabulce zadanou funkci s parametry "const char*" a "unsigned*"
void htab_foreach(htab_t t, void (*func)(const char*, unsigned*));
//Odstrani polozku daneho klice z tabulky, pokud existuje a vrati true, jinak vrati false
bool htab_remove(htab_t t, char *key);
//Odstrani vsechny polozky v tabulce
void htab_clear(htab_t t);
//Vycisti a odstrani tabulku
void htab_free(htab_t t);
//Hashuje retezec
unsigned int htab_hash_function(const char *str);


#endif
