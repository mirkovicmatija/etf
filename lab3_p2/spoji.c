#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int saberi(int a, int b) { return a + b; }

char *dodaj(char *a, char *b)
{
    char *r = (char *)calloc(strlen(a) + strlen(b) + 1, sizeof(char));
    strcpy(r, a);
    strcat(r, b);
    return r;
}

void spoji_saberi(int argc, char *argv[], char *(*dodaj)(char *, char *),
                  int (*saberi)(int, int))
{
    char *b = 0, *s = 0;
    int suma = 0, i;

    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-b") == 0)
        {
            i++;
            do
            {

                if (strcmp(argv[i], "-s") == 0)
                {
                    i--;
                    break;
                }
                int num = atoi(argv[i]);
                suma = (*saberi)(suma, num);
                i++;
            } while (i < argc);

            printf("Suma brojeva je %d. ", suma);
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            i++;
            s = (char *)calloc(1, 1);
            do
            {

                if (strcmp(argv[i], "-b") == 0)
                {
                    i--;
                    break;
                }

                strcpy(s, (*dodaj)(s, argv[i]));
                i++;

            } while (i < argc);

            printf("String je '%s'. ", s);
        }
        else
            return;
    }
}

int main(int argc, char *argv[])
{
    spoji_saberi(argc, argv, &dodaj, &saberi);

    return 0;
}