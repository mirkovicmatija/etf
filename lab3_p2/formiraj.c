#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *formiraj(int n, ...)
{
    char *niz = calloc(1, sizeof(char));
    int k = 0, j;
    va_list lista;
    va_start(lista, n);
    for (int i = 1; i <= n; i++)
    {
        int kopija = va_arg(lista, int);
        char *buff = calloc(1, sizeof(char));
        j = 0;
        while (kopija)
        {
            buff[j] = (char)(kopija % 10 + 0x30);
            buff = realloc(buff, 1);
            j++;
            kopija /= 10;
        }
        for (int i = strlen(buff) - 1; i > -1; i--)
        {
            niz[k] = buff[i];
            niz = realloc(niz, 1);
            k++;
        }

        free(buff);
    }
    va_end(lista);
    return niz;
}

int main()
{
    char *s = formiraj(3, 123, 456, 789);
    printf("%s", s);
    free(s);
    return 0;
}