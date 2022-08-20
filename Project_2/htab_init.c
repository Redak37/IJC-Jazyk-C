/*
 *  Soubor:      htab_init.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "htabs.h"

//Vytvori tabulku velikosti size, pri chybe vraci NULL
htab_t htab_init(unsigned size)
{
    if (!size) return NULL;
    //alokuje misto pro obsah tabulky a pole ukazatelu na polozky tabulky
    htab_t t = malloc(sizeof(htab_t) + size * sizeof(struct htab_listitem*));
    
    if (!t) return NULL;
    
    t->arr_size = size;
    t->size = 0;

    while (size) t->ptr[--size] = NULL;

    return t;
}

