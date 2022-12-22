#include <stdio.h>
#include <math.h>

int main()
{
    int n, c[100], b[100], a[100], udaljenost = 0;
    do
    {
        scanf("%d", &n);
    } while (n < 2);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        c[i] = b[i] - a[i];
        udaljenost += c[i] * c[i];
    }
    printf("%f", sqrt(udaljenost));
    return 0;
}