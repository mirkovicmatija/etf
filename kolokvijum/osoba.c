#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int broj_poste;
    char naziv[20];
} MJESTO;

typedef struct
{
    char ime[20], prezime[20];
    MJESTO mjesto_rodjenja;
} OSOBA;

OSOBA *ucitaj(int *pn)
{

    do
    {
        scanf("%d", pn);
    } while (*pn < 1);

    OSOBA *pv = (OSOBA *)calloc(*pn, sizeof(OSOBA));
    if (pv == NULL)
        return NULL;
    for (int i = 0; i < *pn; i++)
    {
        scanf("%s", pv[i].ime);
        scanf("%s", (pv + i)->prezime);
        scanf("%d", &pv[i].mjesto_rodjenja.broj_poste);
        scanf("%s", pv[i].mjesto_rodjenja.naziv);
    }

    return pv;
}

void ispisi(OSOBA *niz, int n, int broj_poste)
{
    for (int i = 0; i < n && niz[i].mjesto_rodjenja.broj_poste == broj_poste; i++)
    {
        printf("%s %s %s %d", (niz + i)->ime, (niz + i)->prezime, (niz + i)->mjesto_rodjenja.naziv, (niz + i)->mjesto_rodjenja.broj_poste);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    OSOBA *os;

    os = ucitaj(&n);
    ispisi(os, n, 78000);
    free(os);
    return 0;
}
