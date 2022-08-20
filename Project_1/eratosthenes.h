/*
 *  Soubor:      eratosthenes.h
 *  Řešení:      IJC-DU1, příklad a)
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       18.3.2018
 */


#ifndef LONG_BIT
#define LONG_BIT (sizeof(long) >> 3)//Bitova velikost longu
#endif

#ifndef _ERATOS_
#define _ERATOS_

#include <math.h>
#include "bit_array.h"
#include "error.h"

void eratosthenes(bit_array_t pole);

#endif
