#include <stdio.h>

int main()
{
    int k, x;
    do
    {
        scanf("%d %d", &x, &k);
    } while (k < 2);

    double s = -1;

    for (int i = 2; i <= k; i++)
    {
        double p = 1;
        int fakt = 1;
        for (int j = 1; j <= x; j++)
        {
            p *= 2 * i - 1;
        }

        for (int l = 1; l < 2 * i - 1; l++)
        {
            fakt *= l;
        }

        int jedan = i % 2 ? -1 : 1;
        s += jedan * p / fakt;
    }

    printf("%lf", s);
    return 0;
}