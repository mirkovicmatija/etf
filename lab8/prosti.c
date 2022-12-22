#include <stdio.h>

int main()
{
    int n, mat[20][20], prost;
    do
    {
        scanf("%d", &n);
    } while (n < 2 && n > 20);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            prost = 0;
            for (int k = 2; k < mat[i][j] / 2 + 1; k++)
            {
                prost += (mat[i][j] % k) ? 0 : 1;
            }
            if (!prost)
                printf("%d ", mat[i][j]);
        }
    }

    return 0;
}