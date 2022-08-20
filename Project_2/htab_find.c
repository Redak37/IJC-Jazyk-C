/*
 *  Soubor:      htab_find.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "htabs.h"

//Vraci ukazatel na polozku v tabulce pokud existuje polozka s odpovidajicim klicem, jinak 'NULL'
struct htab_listitem *htab_find(htab_t t, char *key)
{
    struct htab_listitem *item = t->ptr[htab_hash_function(key) % t->arr_size];

    while (item)
    {
        if (!strcmp(item->key, key)) return item;

        item = item->next;
    }

    return NULL;
}
