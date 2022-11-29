#include <stdio.h>

int main()
{
    int k;
    double x;
    do
    {
        scanf("%lf %d", &x, &k);
    } while (k < 1);

    double z1 = x, z2 = x + 1, zk;
    int fakt = 1;
    for (int i = 2; i <= k; i++)
    {
        double p = 1;
        fakt *= i;

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            p *= i;
        }
        zk += (p * z1) / (fakt * z2);
        z1 = z2;
        z2 = zk;
    }
    printf("%lf", zk);

    return 0;
}