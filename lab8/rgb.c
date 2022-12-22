#include <stdio.h>

int main()
{
    int n;
    unsigned char rgb[10][10][3];
    do
    {
        scanf("%d", &n);
    } while (n < 2 || n > 10);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("%d %d %d:", i, j, k);
                scanf("%d", &rgb[i][j][k]);
            }
        }
    }
    for (int i = 0; i < n; i++, printf("\n"))
    {
        for (int j = 0; j < n; j++)
        {
            printf("#%02x%02x%02x ", rgb[i][j][0], rgb[i][j][1], rgb[i][j][2]);
        }
    }
    return 0;
}