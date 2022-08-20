/*
 *  Soubor:      tail.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       23.4.2018
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tail.h"


#define LINE_LIMIT 1026//(1024 + konec řádku + '0')

//Vypise poslednich 'nlines' radku ze streamu
void tail(int nlines, FILE *file)
{
    if (!nlines) return;

    int now = 0;//Kolik bylo nacteno radku
    char new[LINE_LIMIT] = {0};
    char last[nlines][LINE_LIMIT];//Pole stringu pro pamatovani poslednich 'nlines' radku
    //Vynulovani pole stringu
    for (int i = 0; i < nlines; ++i)
        for (int j = 0; j < LINE_LIMIT; ++j)
            last[i][j] = 0;
    //Nacitani radku do stringu new
    while (fgets(new, LINE_LIMIT, file) != NULL)
    {   //Kontrola zda byl nacten cely radek
        for (int i = 0; i < LINE_LIMIT - 1; ++i)
        {
            if (new[i] == '\0')
            {
                new[i] = '\n';
                new[i+1] = '\0';
            }

            if (new[i] == '\n') break;

            if (i == LINE_LIMIT-2)
            {   //Vynechavani nadbytecnych znaku
                while (fgetc(file) != '\n');
                new[LINE_LIMIT-2] = '\n';
            }
        }
        //Zaznamenani posledniho radku do pole, pripadny prepis jiz neplatneho radku
        strcpy(last[now % nlines], new);
        ++now;
    }
    //Vypis pro nacteni mene radku, nez je chteny vypis
    if (now < nlines)
        for (int i = 0; i < now; ++i)
            printf("%s", last[i]);
    //Vypis poslednich 'nlines' radku ze streamu
    else
        for (int i = 0; i < nlines && i <= now; ++i)
            printf("%s", last[(now + i) % nlines]);
}


int main(int argc, char *argv[])
{
    int num = 10;//Pocet vypisovanych radku
    int n = 0;//Pripadna pozice prepinace '-n'

    if (argc >= 5)
    {
        fprintf(stderr, "Error: Zadany neplatne argumenty.\n");
        return 1;
    }
    //Zpracovani argumentu
    if (argc >= 3)
    {
        if (!strcmp(argv[argc-2], "-n")) n = argc - 2;

        else if (argc == 4)
        {
            if (!strcmp(argv[argc-3], "-n")) n = argc - 3;

        } else {
            fprintf(stderr, "Error: Zadany neplatne argumenty.\n");
            return 1;
        }

        char *endptr;
        num = strtol(argv[n+1], &endptr, 10);
           
        if (num < 0 || *endptr != '\0')
        {
            fprintf(stderr, "Error: Zadany neplatne argumenty.\n");
            return 1;
        }
    }

    FILE *file;

    if (argc == 1 || argc == 3) file = stdin;

    else if (n == 1) file = fopen(argv[3], "r");

    else file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Zadany soubor se nepodarilo nacist.\n");
        return 1;
    }

    tail(num, file);

    fclose(file);

    return 0;
}
