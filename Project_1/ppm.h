/*
 *  Soubor:      ppm.h
 *  Řešení:      IJC-DU1, příklad a)
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       18.3.2018
 */


#ifndef _PPM_
#define _PPM_

#include <stdio.h>
#include "error.h"

//struktura pro data ze souboru ppm
struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm *ppm_read(const char *filename);

int ppm_write(struct ppm *p, const char *filename);

#endif
