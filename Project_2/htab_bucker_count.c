/*
 *  Soubor:      htab_bucker_count.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "htabs.h"

//vraci velikost pole ukazatelu v tabulce
unsigned htab_bucket_count(htab_t t)
{
    return t->arr_size;
}
