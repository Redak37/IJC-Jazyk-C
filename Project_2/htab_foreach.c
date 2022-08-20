/*
 *  Soubor:      htab_foreach.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "htabs.h"

//Provede pro kazdou polozku v tabulce zadanou funkci s parametry "const char*" a "unsigned*"
void htab_foreach(htab_t t, void (*func)(const char*, unsigned*))
{
    struct htab_listitem *item;

    for (unsigned i = 0; i < t->arr_size; ++i)
    {
        item = t->ptr[i];

        while (item)
        {
            func(item->key, &item->data);
            item = item->next;
        }
    }

}
