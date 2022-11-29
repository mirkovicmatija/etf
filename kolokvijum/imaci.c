#include <stdio.h>

int main()
{
    int a, b, c;
    do
    {
        scanf("%d %d %d", &a, &b, &c);
    } while (b < a);

    int br_sa_ciframa = 0;
    for (int i = a; i < b; i++)
    {
        int brc = 0, br = 0, kopija_a = i, kopija_b = i;
        while (kopija_a)
        {
            brc++;
            kopija_a /= 10;
        }
        for (int j = 0; j < brc; j++)
        {
            if (kopija_b % 10 == c)
            {
                br++;
                kopija_b /= 10;
            }
        }
        if (br)
        {
            br_sa_ciframa++;
            printf("%d\n", i);
            continue;
        }
    }
    printf("%d\n", br_sa_ciframa);
    return 0;
}