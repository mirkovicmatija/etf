#include <stdio.h>
#define MAKS 10

void ucitaj(int matrica[][MAKS], int red, int kolona)
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            scanf("%d", &matrica[i][j]);
        }
    }
}

void ispisi(int matrica[][MAKS], int red, int kolona)
{
    for (int i = 0; i < red; i++, printf("\n"))
    {
        for (int j = 0; j < kolona; j++)
        {
            printf("%d ", matrica[i][j]);
        }
    }
}

void pomnozi(int matrica1[][MAKS], int matrica2[][MAKS], int matrica3[][MAKS], int red1, int kolona1, int red2, int kolona2)
{
    if (red2 != kolona1)
        return;
    for (int i = 0; i < red1; i++)
    {
        for (int j = 0; j < kolona2; j++)
        {
            matrica3[i][j] = 0;
            for (int k = 0; k < red2; k++)
            {
                matrica3[i][j] += matrica1[i][k] * matrica2[k][j];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int r1, k1, r2, k2;
    scanf("%d %d %d %d", &r1, &k1, &r2, &k2);
    int m1[r1][MAKS], m2[r2][MAKS];
    ucitaj(m1, r1, k1);
    ucitaj(m2, r2, k2);
    ispisi(m1, r1, k1);
    ispisi(m2, r2, k2);

    int m3[r1][MAKS];

    pomnozi(m1, m2, m3, r1, k1, r2, k2);
    ispisi(m3, r1, k2);
    return 0;
}
