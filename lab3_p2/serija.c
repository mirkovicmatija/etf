#include <stdio.h>
#include <stdlib.h>

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina)
{
    int br = 0, start = 0;
    *duzina = 0;
    for (int i = 0; i < n; i++)
    {
        if ((*s)(niz[i]))
        {
            br++;
            if (br > *duzina)
            {
                *duzina = br;
                start = i + 1 - *duzina;
            }
        }
        else
            br = 0;
    }
    *pocetak = niz + start;
}

int paran(int x)
{
    if (x % 2 == 0)
        return 1;
    else
        return 0;
}

int pozitivan(int x)
{
    if (x >= 0)
        return 1;
    else
        return 0;
}

int main()
{

    unsigned n;
    int *niz, *pocetak = NULL, duzina;

    do
    {
        printf("Broj clanova niza: ");
        scanf("%u", &n);
    } while (n < 1);

    niz = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("%d. clan: ", i + 1);
        scanf("%d", &niz[i]);
    }

    serija(niz, n, &pozitivan, &pocetak, &duzina);
    if (duzina != 0)
    {
        printf("Najduza serija pozitivnih je %d i to: ", duzina);
        for (int i = 0; i < duzina; i++)
            printf("%d ", pocetak[i]);
    }
    printf("\n");

    serija(niz, n, &paran, &pocetak, &duzina);
    if (duzina != 0)
    {
        printf("Najduza serija parnih je %d i to: ", duzina);
        for (int i = 0; i < duzina; i++)
            printf("%d ", pocetak[i]);
    }
    printf("\n");

    free(niz);

    return 0;
}