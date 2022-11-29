#include <stdio.h>

int main()
{
    float x, s = 0;
    int n;
    do
    {
        scanf("%f %d", &x, &n);
    } while (n < 1);

    s = 1 - x;
    int fakt = 1;

    for (int i = 2; i <= n; i++)
    {
        float stepen = 1;
        fakt *= i;

        for (int j = 0; j < i; j++)
        {
            stepen *= x;
        }
        int jedan = i % 2 ? -1 : 1;
        s += jedan * stepen / fakt;
        printf("%d %f %d %d %f\n", i, stepen, fakt, jedan, s);
    }
    printf("%f", s);
    return 0;
}