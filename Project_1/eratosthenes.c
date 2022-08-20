/*
 *  Soubor:      eratosthenes.c
 *  Řešení:      IJC-DU1, příklad a)
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       18.3.2018
 */


#include <math.h>
#include "bit_array.h"
#include "error.h"
#include "eratosthenes.h"

//Hledani prvocisel v bitovem poli metodou eratosthenova sita
void eratosthenes(bit_array_t pole)
{
    //rychlejsi nastaveni sudych bitu na '1' pro 32 a 64bit architekturu
    if (sizeof(long) == 4){
        for (unsigned long i = 1, j = ((pole[0] / LONG_BIT) + 1); i <= j; ++i)
            pole[i] = (unsigned long)0x55555555;
    }else if (sizeof(long) == 8){
        for (unsigned long i = 1, j = ((pole[0] / LONG_BIT) + 1); i <= j; ++i)
            pole[i] = (unsigned long)0x5555555555555555;
    }else for (unsigned long i = 0; i <= pole[0]; i += 2)
        bit_array_setbit(pole, i, 1);

    bit_array_setbit(pole, 1, 1);
    bit_array_setbit(pole, 2, 0);//spraveni bitu na indexu 2 na 0
    const unsigned long odm = sqrt(pole[0]);
    //nastaveni lichych nasobku 3 na '1'
    for (unsigned long i = 9; i <= pole[0]; i += 6)
        bit_array_setbit(pole, i, 1);

    //nastaveni dalsich neprvociselnych bitu na '1', pro optimalizaci vynechava nasobky 2 a 3
    //obdobnym zpusobem lze optimalizovat i vynechavanim dalsich prvocisel, ale postup je mnohem slozitejsi s minimalnim zrychlenim
    for (unsigned long i = 5; i <= odm; i += 4)
    {
        if (!bit_array_getbit(pole, i))
            for (unsigned long j = (i * i), k = (i << 1); j <= pole[0]; j += k)
                bit_array_setbit(pole, j, 1);

        i += 2;

        if (!bit_array_getbit(pole, i))
            for (unsigned long j = (i * i), k = (i << 1); j <= pole[0]; j += k)
                bit_array_setbit(pole, j, 1);
    }
}
