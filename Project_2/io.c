/*
 *  Soubor:      io.c
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       21.4.2018
 */


#include "io.h"

//Zpise jedno slovo maximalni delky max-1 ze streamu do rezezce s, kde slovo je vse oddelene pomoci white-space a vrati jeho delku, pripadne EOF
int get_word(char *s, int max, FILE *f)
{
    static bool ctrl = false;//pamatuje si, jestli jiz bylo vypsano chybove hlaseni
    int i = 0;//aktualni index pro zapis do retezce

    if (!s)
    {
        fprintf(stderr, "Error: nelze ulozit data.\n");
        return 0;
    }

    if (max <= 1)
    {
        fprintf(stderr, "Error: maximum znaku je prilis nizke.\n");
        return 0;
    }

    if (!f)
    {
        fprintf(stderr, "Error: maximum znaku je prilis nizke.\n");
        return 0;
    }

    s[0] = fgetc(f);

    while(isspace(s[0])) s[0] = fgetc(f); //Rusi white-spacy na zacatku streamu

    if (s[0] == EOF) return EOF; //Vraci EOF, pokud nastal konec streamu
    //Nacita slovo do maximalni delky nebo white-spacu
    while(!isspace(s[i]) && i < max - 1)
        s[++i] = fgetc(f);
    //Kontrola zda bylo nacteno cele slovo a pripadny orez
    if (i == max - 1)
    {
        if (!isspace(s[max-1]) && s[max+1] != EOF)
        {
            if (!ctrl)
            {
                fprintf(stderr, "Error: Slovo je prilis dlouhe.\n");
                ctrl = true;
            }

            while (!isspace(s[max-1]) && s[max-1] != EOF)
            {
                s[max-1] = fgetc(f);
            }
        }
    }
    
    s[i] = '\0'; //Zapise konec retezce za nactene slovo

    return i;
}
