#include <stdio.h>
#include <stdlib.h>

int sizeOfString(char *str)
{
    int i = -1;
    while (str[++i])
        ;
    return i;
}

int strDiff(char *str1, char *str2)
{
    int i;
    for (i = 0; str1[i] && str1[i] == str2[i]; i++)
        ;
    return str1[i] - str2[i];
}

char **str2arr(char *str)
{
    char **matrica = calloc(sizeOfString(str) + 1, sizeof(char *));
    int i = 0;
    while (str[i])
    {
        matrica[i] = calloc(1, sizeof(char));
        matrica[i][0] = str[i];
        printf("%c", matrica[i][0]);
        i++;
    }
    return matrica;
}

char *arr2str(char **niz, int n)
{
    char *str = (char *)calloc(n, sizeof(char));
    for (int i = 0; i <= n; i++)
    {
        str[i] = niz[i][0];
        printf("%c", niz[i][0]);
    }
    return str;
}

int main(int argc, char const *argv[])
{
    char input[100];
    scanf("%s", input);
    char **m = str2arr(input);

    char *output = arr2str(m, sizeOfString(input));

    printf("%d", strDiff(input, output) ? 0 : 1);

    for (int i = 0; i < sizeof(input); i++)
    {
        free(m[i]);
    }
    free(m);
    free(output);
    return 0;
}
