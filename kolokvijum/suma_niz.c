#include <stdio.h>
#include <stdlib.h>

int suma(int n)
{
    int t = n, s = 0;
    if (n < 0)
        t = -n;
    while (t)
    {
        s += t % 10;
        t /= 10;
    }
    return s;
}

void formiraj(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = suma(a[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n = 5;
    int a[5] = {23, 54, -23, 567, 90}, b[5];
    formiraj(a, b, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    return 0;
}
