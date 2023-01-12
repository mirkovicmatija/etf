#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *naziv, *zanr;
} FILM;

// pomocne funkcije
int duzina(char *s)
{
    int d = -1;
    while (s[++d])
        ;
    return d;
}

void kopiraj(char *o, char *k)
{
    while (*k++ = *o++)
        ;
}

int komparacija(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] && s1[i] == s2[i]; i++)
        ;
    return s1[i] - s2[i];
}

// zadane funkcije
FILM ucitaj()
{
    char n[128], z[16];
    FILM f;
    scanf("%s %s", n, z);
    f.naziv = calloc(duzina(n) + 1, sizeof(char));
    f.zanr = calloc(duzina(z) + 1, sizeof(char));
    kopiraj(n, f.naziv);
    kopiraj(z, f.zanr);
    return f;
}

FILM *kreirajNiz(int *pn)
{
    scanf("%d", pn);
    FILM *niz = calloc(*pn, sizeof(FILM));
    for (int i = 0; i < *pn; i++)
    {
        niz[i] = ucitaj();
    }
    return niz;
}

void sortiraj(FILM *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (komparacija((f + j)->naziv, (f + i)->naziv) < 0 && komparacija((f + j)->naziv, (f + i)->naziv) < 0)
            {
                FILM temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    FILM *film = kreirajNiz(&n);
    sortiraj(film, n);
    for (int i = 0; i < n; i++, printf("\n"))
    {
        printf("%d %s %s", i, film[i].naziv, film[i].zanr);
        free(film[i].naziv);
        free(film[i].zanr);
    }
    free(film);
    return 0;
}
