/*
 *  Soubor:      ppm.c
 *  Řešení:      IJC-DU1, příklad a)
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       19.3.2018
 */


#include <stdio.h>
#include "error.h"
#include "ppm.h"

//Nacte a vrati ppm soubor
struct ppm *ppm_read(const char *filename)
{
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        warning_msg("Zadany soubor %s nelze otevrit.\n", filename);
        return NULL;
    }
    
    unsigned xsize, ysize;
    int control = fscanf(fp, "P6 %u %u 255 ", &xsize, &ysize);
    
    if (control != 2)
    {
        fclose(fp);
        warning_msg("Chybny format souboru %s.\n", filename); 
        return NULL;
    }

    struct ppm *img = malloc((3 * xsize * ysize * sizeof(char)) + sizeof(struct ppm));

    if (img == NULL)
    {
        fclose(fp);
        warning_msg("Nepodarila se alokovat pamet.\n");
        return NULL;
    }

    control = fread(&img->data, 1, 3 * xsize * ysize, fp);

    if (control != 3 * xsize * ysize || img->data == NULL ||  fgetc(fp) != EOF)
    {
        fclose(fp);
        free(img);
        warning_msg("Chybna data souboru %s.\n", filename);
        return NULL;
    }

    img->xsize = xsize;
    img->ysize = ysize;

    fclose(fp);

    return img;
}

//Zapise data do ppm souboru
int ppm_write(struct ppm *p, const char *filename)
{
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        warning_msg("Soubor %s se nepodarilo otevrit.\n", filename);
        return -1;
    }

    int control = fprintf(fp, "P6\n%u %u\n255\n", p->xsize, p->ysize);

    if (control < 0)
    {
        fclose(fp);
        warning_msg("Do souboru %s se nepodarilo zapsat data.\n", filename);
        return -2;
    }

    control = fwrite(p->data, 1, 3 * p->xsize * p->ysize, fp);

    if (control != 3 * p->xsize * p->ysize)
    {
        fclose(fp);
        warning_msg("Do souboru %s se nepodarilo zapsat data.\n", filename);
        return -2;
    }

    fclose(fp);

    return 0;
}
