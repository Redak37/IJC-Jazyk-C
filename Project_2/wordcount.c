#include "htab.h"
#include "io.h"

//strukturoavny vypis urceny pro volani pomooci funkce htab_foreach
void print(const char *str, unsigned *num)
{
    printf("%s\t%u\n", str, *num);
}


int main()
{
    htab_t t = htab_init(20);

    if (!t)
    {
        fprintf(stderr, "Error: nepodarilo se alokovat pamet pro tabulku.\n");
        return 1;
    }

    char word[128] = {0};
    unsigned maxsize = 320;//hodnota pro maximalni pocet zaznamu v tabulce pred jejim zvetsenim
    int size = get_word(word, 128, stdin);
    struct htab_listitem *ctrl;
    //Postupne nacitani slov ze stdin a dynamicke alokovani stringu pro ne
    while (size != EOF)
    {
        char *key = malloc(sizeof(char) * (size + 1));

        if (!key)
        {
            fprintf(stderr, "Error: nepodarilo se alokovat pamet pro retezec.\n");
            return 1;
        }
        //Experimentalne vyzkousena a odhadnuta efektivita presunu do nove tabulky na textu odpovidajici 800 strankove knize
        if (htab_size(t) > maxsize)
        {
            htab_t t2 = htab_move(htab_bucket_count(t) << 2, t);

            if (!t2)
                fprintf(stderr, "Error: nepodarilo se alokovat pamet pro vetsi tabulku, bude pracovano se starou\n");
            else {
            htab_free(t);
            t = t2;
            }

            maxsize = htab_bucket_count(t) << 3;
        }

        strcpy(key, word);
        ctrl = htab_lookup_add(t, key);

        if (!ctrl)
        {
            fprintf(stderr, "Error: nepodarilo se pridat polozku do seznamu\n");
            htab_free(t);
            return 1;
        }

        size = get_word(word, 128, stdin);
    }

    htab_foreach(t, &print);
    htab_free(t);

    return 0;
}
