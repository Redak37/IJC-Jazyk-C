/*
 *  Soubor:      htab_lookup_add.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       22.4.2018
 */


#include "htabs.h"

//Najde a vrati ukazatel na polozku seznamu daneho klice, pokud neexistuje prida ji a vrati, pri chybe vrati 'NULL'
struct htab_listitem *htab_lookup_add(htab_t t, char *key)
{
    unsigned i = htab_hash_function(key) % t->arr_size;
    struct htab_listitem *item = htab_find(t, key);

    if (item)
    {
        free(key);
        item->data++;
        return item;
    }

    item = malloc(sizeof(struct htab_listitem));

    if (!item) return NULL;

    if (!t->ptr[i]) t->ptr[i] = item;
    
    else {
        struct htab_listitem *item2 = t->ptr[i];

        while (item2->next) item2 = item2->next;

        item2->next = item;
    }

    t->size++;
    item->next = NULL;
    item->data = 1;
    item->key = key;

    return item;
}
