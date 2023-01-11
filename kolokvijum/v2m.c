#include <stdio.h>
#include <stdlib.h>

char v2m(char z)
{
    return (z > 0x40 && z < 0x5b) ? z + 0x20 : z;
}

int duzina(char *s)
{
    int d = -1;
    while (s[++d])
        ;
    return d;
}

void konvertuj(char **niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; niz[i][j]; j++)
        {
            niz[i][j] = v2m(niz[i][j]);
        }
    }
}

void kopiraj(char *s1, char *s2)
{
    while (*s1++ = *s2++)
        ;
}

int main(int argc, char const *argv[])
{

    char **niz = calloc(5, sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        char temp[100];
        scanf("%s", temp);
        niz[i] = calloc(duzina(temp) + 1, sizeof(char));
        kopiraj(niz[i], temp);
    }
    konvertuj(niz, 5);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; niz[i][j]; j++)
        {
            printf("%c", niz[i][j]);
        }
        printf("\n");
        free(niz[i]);
    }
    free(niz);
    return 0;
}
