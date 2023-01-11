#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *broj_indeksa, *ime, *prezime;
} STUDENT;

typedef struct
{
    char *sifra;
    STUDENT *studenti;
    int n;
} FAKULTET;

int duzina(char *s)
{
    int d = -1;
    while (s[d++])
        ;
    return d;
}

void kopiraj(char *s, char *kopija)
{
    while (*s++ = *kopija++)
        ;
}

int brisi(FAKULTET *f)
{
    free(f->studenti);
    return (f->studenti = NULL) ? 0 : 1;
}

FAKULTET *dodaj_studente(FAKULTET *f)
{

    STUDENT *novi_stud = (STUDENT *)calloc(f->n, sizeof(STUDENT));
    for (int i = 0; i < f->n; i++, printf("\n"))
    {
        char broj[8], ime[32], prezime[32];
        printf("%d -> ", i);
        scanf("%s", broj);
        scanf("%s", ime);
        scanf("%s", prezime);

        (novi_stud + i)->broj_indeksa = calloc(duzina(broj) + 1, sizeof(char));
        kopiraj((novi_stud + i)->broj_indeksa, broj);

        (novi_stud + i)->ime = calloc(duzina(ime) + 1, sizeof(char));
        kopiraj((novi_stud + i)->ime, ime);

        (novi_stud + i)->prezime = calloc(duzina(prezime) + 1, sizeof(char));
        kopiraj((novi_stud + i)->prezime, prezime);
    }

    if (brisi(f))
        f->studenti = novi_stud;

    return f;
}

int main(int argc, char const *argv[])
{
    FAKULTET *faks;
    int n;
    scanf("%d", &n);
    faks = calloc(n, sizeof(FAKULTET));
    for (int i = 0; i < n; i++, printf("\n"))
    {
        char sifra[16];
        printf("%d -> ", i);
        scanf("%s", sifra);
        scanf("%d", &(faks + i)->n);

        (faks + i)->sifra = calloc(duzina(sifra) + 1, sizeof(char));
        kopiraj((faks + i)->sifra, sifra);

        STUDENT *stud = (STUDENT *)calloc(faks->n, sizeof(STUDENT));
        for (int j = 0; j < faks->n; j++, printf("\n"))
        {
            char broj[8], ime[32], prezime[32];
            printf("%d -> ", j);
            scanf("%s", broj);
            scanf("%s", ime);
            scanf("%s", prezime);

            (stud + j)->broj_indeksa = calloc(duzina(broj) + 1, sizeof(char));
            kopiraj((stud + j)->broj_indeksa, broj);

            (stud + j)->ime = calloc(duzina(ime) + 1, sizeof(char));
            kopiraj((stud + j)->ime, ime);

            (stud + j)->prezime = calloc(duzina(prezime) + 1, sizeof(char));
            kopiraj((stud + j)->prezime, prezime);
        }
        (faks + i)->studenti = stud;
    }

    dodaj_studente(faks);
    free(faks);
    return 0;
}
