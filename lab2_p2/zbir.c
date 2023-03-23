#include <stdio.h>
#include <stdlib.h>

int suma(int *niz, int n)
{
    return (n) ? niz[n - 1] + suma(niz, n - 1) : 0;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int *niz = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (niz + i));
    }
    printf("%d", suma(niz, n));
    return 0;
}
