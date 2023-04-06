
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortiranje(int *niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (niz[i] < niz[j])
            {
                int pom = niz[j];
                niz[j] = niz[i];
                niz[i] = pom;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    printf("Opcije: 1 - Unos tekst\n\t 2 - Citanje iz fila\nUnos: ");
    int n;
    scanf("%d", &n);

    if (n == 1)
    {

        FILE *f_buffer;

        if (argc != 2)
        {
            return 1;
        }

        f_buffer = fopen(argv[1], "w");
        if (f_buffer == NULL)
        {
            fclose(f_buffer);
            return 1;
        }

        int n;
        printf("Broj clanova: ");
        scanf("%d", &n);

        int *niz = calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
        {
            printf("Unesi %d. ", i);
            scanf("%d", (niz + i));
        }
        sortiranje(niz, n);

        fwrite(niz, sizeof(int) * 64, 1, f_buffer);
        fclose(f_buffer);
    }

    if (n == 2)
    {
        char file_name[32];

        printf("Ime fajla: ");
        scanf("%s", file_name);

        if (file_name[0] == '#')
        {
            strcpy(file_name, argv[1]);
        }
        FILE *f_buffer = fopen(file_name, "r");
        if (f_buffer == NULL)
        {
            fclose(f_buffer);
            return 1;
        }
        int n[32];
        fread(n, sizeof(file_name) * 32, 1, f_buffer);

        for (int i = 0; i < sizeof(n) / sizeof(int) && n[i]; i++)
        {
            printf("%d\n", n[i]);
        }

        fclose(f_buffer);
    }

    return 0;
}
