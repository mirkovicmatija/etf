#include <stdio.h>
int main()
{
    int n, niz[100], indeks, maks, pozitivni = 0;
    do
    {
        scanf("%d", &n);
    } while (n < 2 || n > 100);
    for (unsigned short i = 0; i < n; i++)
    {
        printf("-->: ");
        scanf("%d", &niz[i]);
    }
    maks = 0;
    for (unsigned short i = 0; i < n; i++)
    {
        if (niz[i] > 0)
        {
            pozitivni++;
        }
        else
        {
            maks = (maks < pozitivni) ? pozitivni : maks;
            pozitivni = 0;
            indeks = i;
        }
    }

    for (unsigned short i = indeks - maks; i < indeks; i++)
    {
        printf("%d ", i);
    }

    return 0;
}