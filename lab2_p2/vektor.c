
#include <stdio.h>
#include <stdlib.h>

void saberi(double *vektor_a, double *vektor_b, double *vektor_rez, int n)
{
    if (n == 0)
        return;
    vektor_rez[n - 1] = vektor_a[n - 1] + vektor_b[n - 1];
    saberi(vektor_a, vektor_b, vektor_rez, n - 1);
}

double *vetor(int n)
{
    double *niz = calloc(n, sizeof(double));
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", (niz + i));
    }

    return niz;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    double *a = vetor(n);
    double *b = vetor(n);
    double *niz = calloc(n, sizeof(double));
    saberi(a, b, niz, n);
    for (int i = 0; i < n; i++)
    {
        printf("%lf\n", niz[i]);
    }

    return 0;
}
