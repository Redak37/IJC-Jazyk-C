/*
 *  Soubor:      bit_array.h
 *  Řešení:      IJC-DU1, příklad a)
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       18.3.2018
 */


#ifndef LONG_BIT
#define LONG_BIT (sizeof(long) << 3) //bitova velikost longu
#endif

#ifndef _BIT_ARRAY_
#define _BIT_ARRAY_

#include "error.h"

//typ bitoveho pole
typedef unsigned long bit_array_t[];

//Vytvari bitove pole dane velikosti a inicializuje ho na nuly, na 1. pozici pole zapise velikost bitoveho pole
#define bit_array_create(jmeno_pole,velikost) unsigned long jmeno_pole[((velikost + 1) / LONG_BIT) + 1 + !!((velikost + 1) % (LONG_BIT))] = {velikost}

#ifdef USE_INLINE

//Vraci velikost bitoveho pole
static inline unsigned long bit_array_size(bit_array_t jmeno_pole)
{
    return jmeno_pole[0];
}
//Nastavuje bit na pozici 'index' bitoveho pole na hodnotu 1 nebo 0
static inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, unsigned long vyraz)
{
    ((index) > jmeno_pole[0]) ?\
        error_exit("index %lu mimo rozsah 0..%lu", index, (jmeno_pole[0])), 2 :\
        ((vyraz) ?\
        (jmeno_pole[((index) / LONG_BIT) + 1] |= (1UL << ((index) % LONG_BIT))) :\
        (jmeno_pole[((index) / LONG_BIT) + 1] &= ~(1UL << ((index) % LONG_BIT))));
}
//Vraci hodnotu bitu na pozici 'index' bitoveho pole
static inline unsigned long bit_array_getbit(bit_array_t jmeno_pole, unsigned long index)
{
    return (((index) > jmeno_pole[0]) ?\
            error_exit("index %lu mimo rozsah 0..%lu", index, (jmeno_pole[0])), 2 :\
            !!(jmeno_pole[((index) / LONG_BIT) + 1] & (1UL << ((index) % LONG_BIT))));
}

#else

#define bit_array_size(jmeno_pole) (jmeno_pole[0])//Vraci velikost bitoveho pole

//nastavuje bit na pozici 'index' bitoveho pole na hodnotu 1 nebo 0
#define bit_array_setbit(jmeno_pole,index,vyraz) ((index) > jmeno_pole[0]) ?\
    error_exit("index %lu mimo rozsah 0..%lu", index, (jmeno_pole[0])), 2 :\
    ((vyraz) ?\
    (jmeno_pole[((index) / LONG_BIT) + 1] |= (1UL << ((index) % LONG_BIT))) :\
    (jmeno_pole[((index) / LONG_BIT) + 1] &= ~(1UL << ((index) % LONG_BIT))))

//Vraci hodnotu bitu na pozici 'index' bitoveho pole
#define bit_array_getbit(jmeno_pole,index) (((index) > jmeno_pole[0]) ?\
    error_exit("index %lu mimo rozsah 0..%lu", index, (jmeno_pole[0])), 2 :\
    !!(jmeno_pole[((index) / LONG_BIT) + 1] & (1UL << ((index) % LONG_BIT))))

#endif
#endif
