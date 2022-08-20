/*
 *  Soubor:      htab_clear.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "htabs.h"

//Odstrani vsechny polozky v tabulce
void htab_clear(htab_t t)
{
    struct htab_listitem *item;
    struct htab_listitem *item2;

    for (unsigned i = 0; i < t->arr_size; ++i)
    {
        item = t->ptr[i];
        t->ptr[i] = NULL;

        while (item)
        {
            item2 = item->next;
            free(item->key);
            free(item);
            item = item2;
        }
    }

    t->size = 0;
}
