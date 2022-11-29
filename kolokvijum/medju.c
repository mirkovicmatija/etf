#include <stdio.h>

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
    } while (n < 1);

    int p = 2;

    for (int i = 3; i < n; i++)
    {
        int br = 0;
        for (int j = 2; j <= i / 2; j++)
        {
            br += i % j ? 0 : 1;
        }
        if (!br)
        {
            printf("Medjuprosti broj je %d\n", (i + p) / 2);
            p = i;
        }
    }

    return 0;
}