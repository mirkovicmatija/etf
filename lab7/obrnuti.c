#include <stdio.h>

int main()
{
    int n, niz[100], temp;
    do
    {
        scanf("%d", &n);
    } while (n < 2);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &niz[i]);
    }
    for (int i = 0; i <= n / 2; i++)
    {
        temp = niz[i];
        niz[i] = niz[n - i - 1];
        niz[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", niz[i]);
    }

    return 0;
}