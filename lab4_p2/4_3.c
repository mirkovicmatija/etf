#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *ispis;

    int n;
    printf("n = ");
    scanf("%d", &n);

    if (argc != 2)
    {
        return 1;
    }
    ispis = fopen(argv[1], "w");
    if (ispis == NULL)
    {
        fclose(ispis);
        return 1;
    }

    fputs("=== ===== ==================== ======\n", ispis);
    fputs("RB. SIFRA NAZIV                CIJENA\n", ispis);
    fputs("=== ===== ==================== ======\n", ispis);

    char sifra[6];
    char naziv[21];
    float cijena;

    for (int i = 1; i <= n; i++)
    {
        printf("%d. artikal: ", i);
        scanf("%s %s %f", sifra, naziv, &cijena);
        fprintf(ispis, "%2d. %5s %20s %6.2f\n", i, sifra, naziv, cijena);
    }

    fclose(ispis);
    return 0;
}
