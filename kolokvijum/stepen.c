#include <stdio.h>

int main()
{
    int d;
    do
    {
        scanf("%d", &d);
    } while (d < 1);
    int a = d, brc = 0, b = d, s = 0;
    while (a)
    {
        brc++;
        a /= 10;
    }

    for (int i = 0; i < brc; i++)
    {
        int cifra = b % 10;
        int p = 1;
        if (!cifra)
        {
            s++;
            continue;
        }
        for (int j = 0; j < cifra; j++)
        {
            p *= cifra;
        }
        s += p;
        b /= 10;
    }

    if (s == d)
    {
        printf("Uslov ispunjen");
    }

    return 0;
}