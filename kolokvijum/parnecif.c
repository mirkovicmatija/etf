#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (b < a)
    {
        int p = a;
        a = b;
        b = p;
    }

    for (int i = a; i <= b; i++)
    {
        int brc = 0, kopija = i;
        while (kopija)
        {
            brc++;
            kopija /= 10;
        }

        int sp = 0, sn = 0, dkopija = i;

        for (int j = 1; j <= brc; j++)
        {
            (j % 2) ? (sn += dkopija % 10) : (sp += dkopija % 10);

            dkopija /= 10;
        }
        if (sn == sp)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}