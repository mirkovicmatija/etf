#include <stdio.h>

int main()
{
    int n, mat[20][20], glavna = 0, sporedna = 0;
    do
    {
        scanf("%d", &n);
    } while (n < 2 && n > 20);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
            glavna += (i == j) ? mat[i][j] : 0;
            sporedna += (i + j == n - 1) ? mat[i][j] : 0;
        }
    }
    printf("%d %d", glavna, sporedna);
    return 0;
}