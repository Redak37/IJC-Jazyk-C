/*
 *  Soubor:      steg-decode.c
 *  Řešení:      IJC-DU1, příklad a)
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       18.3.2018
 */


#include <stdio.h>
#include <ctype.h>
#include "bit_array.h"
#include "eratosthenes.h"
#include "error.h"
#include "ppm.h"

//Lusti zakodovanou zpravu v ppm souboru pomoci seznamu prvocisel ziskanych eratosthenovym sitem
int main(int argc, char *argv[])
{
    if (argc != 2)
        error_exit("Zadany spatne argumenty.\n");

    struct ppm *img = ppm_read(argv[1]);

    if (img == NULL)
        error_exit("Soubor %s se nepodarilo nacist.\n", argv[1]);

    bit_array_create(primes, 1000 * 1000 * 3UL);
    eratosthenes(primes);

    char pismeno = 1;
    unsigned long i = 11;

    while (pismeno != '\0')
    {
        pismeno = 0;

        for (short j = 0; j < 8; ++j)
        {   //hleda dalsi prvocislo
            while(bit_array_getbit(primes, i))
                ++i;
            //kontrola indexu
            if (i > img->xsize * img->ysize * 3 * sizeof(char))
            {
                free(img);
                error_exit("Nebyl nalezen ukoncovaci znak.\n");
            }

            pismeno |= ((img->data[i] & 1) << j);
            ++i;
        }

        if (!isprint(pismeno) && pismeno != '\0')
        {
            putchar('\n');
            free(img);
            error_exit("Nalezen neplatny znak.\n");
        }

        printf("%c", pismeno);
    }

    printf("\n");

    free(img);

    return 0;
}
