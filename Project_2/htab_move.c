/*
 *  Soubor:      htab_move.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "htabs.h"

//Vytvori novou tabulku dane velikosti, premisti do ni obsah stare tabulky a starou tabulku vyprazdni
//Pri velikosti 0 vrati NULL a nic neprovede
htab_t htab_move(unsigned newsize, htab_t t2)
{
    htab_t t = htab_init(newsize);
    struct htab_listitem *item;
    struct htab_listitem *item2;
    struct htab_listitem *item3;

    if (!t) return NULL;

    t->size = t2->size;

    for (unsigned i = 0; i < t2->arr_size; ++i)
    {
        item = t2->ptr[i];

        while (item)
        {
            item2 = item->next;
            item->next = NULL;
            unsigned j = htab_hash_function(item->key) % t->arr_size;
            
            if (!t->ptr[j]) t->ptr[j] = item;

            else {
                item3 = t->ptr[j];
                while(item3->next) item3 = item3->next;
                item3->next = item;
            }

            item = item2;
        }
        
        t2->ptr[i] = NULL;
    }

    t2->size = 0;

    return t;
}
