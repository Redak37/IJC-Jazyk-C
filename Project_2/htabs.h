/*
 *  Soubor:      htabs.h
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */

//Utajena knihovna pro utajeni podoby struktur
#ifndef _HTABS_H_
#define _HTABS_H_


#include "htab.h"


struct htab_listitem{
    char *key;
    unsigned data;
    struct htab_listitem *next;
};


struct htab{
    unsigned size;
    unsigned arr_size;
    struct htab_listitem *ptr[];
};


#endif
