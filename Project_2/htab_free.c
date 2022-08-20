/*
 *  Soubor:      htab_free.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "htabs.h"


//Vycisti a odstrani tabulku
void htab_free(htab_t t)
{
    htab_clear(t);
    free(t);
}
