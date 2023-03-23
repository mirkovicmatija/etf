#include <stdio.h>

int suma_cifara(int n)
{
    return (n < 10) ? n : n % 10 + suma_cifara(n / 10);
}

int main(int argc, char const *argv[])
{
    int b;
    scanf("%d", &b);
    printf("%d", suma_cifara(b));
    return 0;
}
