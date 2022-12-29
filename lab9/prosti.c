#include <stdio.h>

int prost(int broj)
{
    int i = 2;
    while (i <= broj / 2)
    {
        if (!(broj % i))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    short n;
    int niz[100];
    do
    {
        scanf("%hd", &n);
    } while (n < 2 || n > 100);
    for (short i = 0; i < n; i++)
    {
        printf("--> ");
        scanf("%d", &niz[i]);
    }
    for (short i = 0; i < n; i++)
    {
        if (prost(niz[i]))
            printf("%d ", niz[i]);
    }

    return 0;
}
