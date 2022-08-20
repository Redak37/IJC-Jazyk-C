/*
 *  Soubor:      htab_remove.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "htabs.h"

//Odstrani polozku daneho klice z tabulky, pokud existuje a vrati true, jinak vrati false
bool htab_remove(htab_t t, char *key)
{
    unsigned i = htab_hash_function(key) % t->arr_size;
    struct htab_listitem *item = t->ptr[i];

    if(item)
    {
        if (!strcmp(item->key, key))
        {
            struct htab_listitem *item2 = item->next;
            t->size--;
            free(item->key);
            free(t->ptr[i]);
            t->ptr[i] = item2;
            return true;
        }
    }

    while (item->next)
    {
        if (!strcmp(item->next->key, key))
        {
            struct htab_listitem *item2 = item->next->next;
            t->size--;
            free(item->next->key);
            free(item->next);
            item->next = item2;
            return true;
        }

        item = item->next;
    }

    return false;
}
