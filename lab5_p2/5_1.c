
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct osoba
{
    char ime[20], prezime[40], broj[12];
} OSOBA;

int main(int argc, char const *argv[])
{
    printf("Opcije: 1 - Unos u imenik\n\t 2 - Citanje iz imenika\nUnos: ");
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

        printf("Broj osoba: ");
        int o;
        scanf("%d", &o);
        OSOBA ob;

        for (int i = 0; i < o; i++)
        {
            printf("%d.: ", i);
            scanf("%s %s %s", ob.ime, ob.prezime, ob.broj);
            fwrite(&ob, sizeof(OSOBA), 1, f_buffer);
        }
        fclose(f_buffer);
    }

    if (n == 2)
    {
        char file_name[32];
        OSOBA ob;
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
        while (fread(&ob, sizeof(file_name), 1, f_buffer))
        {
            printf("%s %s %s\n", 20, ob.ime, 40, ob.prezime, 12, ob.broj);
        }
        fclose(f_buffer);
    }

    return 0;
}
