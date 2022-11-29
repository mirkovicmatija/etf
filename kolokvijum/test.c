#include <stdio.h>

int main()
{
    float z, zk;
    int k;
    do
    {
        scanf("%f %d", &z, &k);
    } while (k < 1);
    float z1 = z + 1, z2 = z;
    for (int i = 2; i <= k; i++)
    {
        int fakt = 1, step = 1;
        for (int j = 0; j < 2 * i - 3; j++)
        {
            step *= (k - 1);
        }
        for (int j = 1; j <= i - 1; j++)
        {
            fakt *= j;
        }

        zk += (z2 * step) / (z1 * fakt);
        z2 = z1;
        z1 = zk;
        printf("%d %f %f %f %d %d \n", i, zk, z1, z2, fakt, step);
    }
    printf("%f", zk);
    return 0;
}