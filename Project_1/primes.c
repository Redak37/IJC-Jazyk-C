/*
 *  Soubor:      primes.c
 *  Řešení:      IJC-DU1, příklad a)
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       18.3.2018
 */


#include <stdio.h>
#include "bit_array.h"
#include "eratosthenes.h"
#include "error.h"

int main()
{
    bit_array_create(pole,222000000UL);//vytvori bitove pole vhodne velikosti
    eratosthenes(pole);//metodou eratosthenova sita urci prvocisla do velikosti bitoveho pole
    //vypise poslednich 10 prvocisel v poli
    for (unsigned long i = pole[0], j = 0; j < 10; --i)
    {
        if (!bit_array_getbit(pole, i))
            ++j;

        if (j == 10)
            for (; i <= pole[0]; ++i)
                if (!bit_array_getbit(pole, i))
                    printf("%lu\n", i);
    }
}
