#include <stdio.h>
#include <math.h>

int main()
{
    int n, niz[100], temp, s = 0, indeks;
    float art, nblizi;
    do
    {
        scanf("%d", &n);
    } while (n < 2);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &niz[i]);
        s += niz[i];
    }
    art = (float)s / n;

    printf("%f\n", art);

    indeks = 0;
    nblizi = niz[0];
    for (int i = 0; i < n; i++)
    {
        if (fabs(art - (float)niz[i]) < fabs(art - (float)nblizi))
        {
            indeks = i;
            nblizi = niz[i];
        }
    }
    printf("%d\n", (int)nblizi);

    for (int i = 0; i < indeks; i++)
    {
        for (int j = 0; j < indeks; j++)
        {
            if (niz[i] < niz[j])
            {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
    for (int i = indeks + 1; i < n; i++)
    {
        for (int j = indeks + 1; j < n; j++)
        {
            if (niz[i] > niz[j])
            {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", niz[i]);
    }

    return 0;
}