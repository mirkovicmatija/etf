#include <stdio.h>
#include <stdlib.h>

// pomocne

int duzina(char *s)
{
    int d = 0;
    while (s[d++])
        ;
    return d;
}

void kopiraj(char *o, char *k)
{
    while (*k++ = *o++)
        ;
}
// zadane

char rot3(char c)
{
    if ((c >= 'a' && c <= 'w') || (c >= 'A' && c <= 'W'))
    {
        return c + 3;
    }
    if ((c >= 'x' && c <= 'z') || (c >= 'X' && c <= 'Z'))
    {
        return c - 23;
    }

    return c;
}

void strrot(char *str)
{
    for (int i = 0; i < duzina(str); i++)
    {
        str[i] = rot3(str[i]);
    }
}

void rot_all(char *s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        strrot(s[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char **niz = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        char string[128];
        scanf("%s", string);
        niz[i] = calloc(duzina(string) + 1, sizeof(char));
        kopiraj(string, niz[i]);
    }
    rot_all(niz, n);
    for (int i = 0; i < n; i++, printf("\n"))
    {
        printf("%s", niz[i]);
        free(niz[i]);
    }
    free(niz);
    return 0;
}
