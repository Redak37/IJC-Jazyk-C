/*
 *  Soubor:      tail2.cc
 *  Řešení:      IJC-DU2
 *  Autor:       Radek Duchoň - xducho07, VUT FIT 1BIT 2017/18
 *  Přeloženo:   gcc 6.4.0
 *  Datum:       23.4.2018
 */


#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include "tail2.h"
using namespace std;

//Vypise poslednich 'nlines' radku z cin
void tail(int nlines)
{
    if (!nlines) return;

    int now = 0;//Kolik je nacteno radku
    queue <string> last;//Kontejner na stringy
    string newstr;//novy string

    //nacita radky z cin do newstr, ten pushuje do kontejneru a popuje nadbytecne polozky
    while (getline(cin, newstr))
    {
        last.push(newstr);
        if (++now > nlines) last.pop();
    }

    //vypis poslednich 'nlines' radku
    for (int i = 0; i < nlines && i < now; ++i)
    {
        cout << last.front() << '\n';
        last.pop();
    }
}


int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    int num = 10;//Pocet vypisovanych radku
    int n = 0;//Pripadna pozice prepinace "-n" v argumentech
    string argn = "-n";

    if (argc >= 5)
    {
        fprintf(stderr, "Error: Zadan neplatny pocet agumentu.\n");
        return 1;
    }
    //Zpracovani argumentu
    if (argc >= 3)
    {
        if (!argn.compare(argv[argc-2])) n = argc - 2;

        else if (argc == 4)
        {
            if(!argn.compare(argv[argc-3])) n = argc - 3;

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

    ifstream mystream;//stream pro cteni

    if (argc != 1 && argc != 3)
    {
        if (n == 1) mystream.open(argv[3]);
        else mystream.open(argv[1]);
    }

    if (!mystream.is_open() && argc != 1 && argc != 3)
    {
        fprintf(stderr, "Error: Zadany soubor se nepodarilo nacist.\n");
        return 1;
    }
    //Presmerovani streamu do cin
    if (mystream.is_open()) cin.rdbuf(mystream.rdbuf());
    
    tail(num);

    mystream.close();

    return 0;
}
