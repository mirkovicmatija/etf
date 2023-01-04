#include <stdio.h>
#include <stdlib.h>

char v2m(char z)
{
    return (z > 0x60 && z < 0x7b) ? z - 0x20 : z;
}

void konvertuj(char **niz, int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%c", *niz[i]);
    }
}

int main(int argc, char const *argv[])
{
    char rijec = 'd';
    char r = v2m(rijec);
    printf("%c", r);
    return 0;
}
