
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SHIFT 3
char *cezar(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = ((s[i] >= 'A' && s[i] < 'X') || (s[i] >= 'a' && s[i] < 'x')) ? s[i] + SHIFT : (s[i] >= 'X' && s[i] <= 'Z') ? (s[i] - 26 + SHIFT)
                                                                                                                          : (s[i] - 26 + SHIFT);
    }
    return s;
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

        char s[100], *cs;
        printf("Unos teksta: ");
        scanf("%s", s);
        cs = cezar(s);
        fwrite(cs, strlen(cs) + 1, 1, f_buffer);
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
        char s1[32];
        fread(s1, sizeof(file_name) * 32, 1, f_buffer);

        printf("%s\n", s1);

        fclose(f_buffer);
    }

    return 0;
}
