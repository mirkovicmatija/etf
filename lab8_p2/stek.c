#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//process
typedef struct proces
{
    char naziv[10];
    int v;
} PROCES;

typedef struct cvor
{
    PROCES p;
    struct cvor *sljedeci;
} CVOR;
void dodaj(CVOR **pf, CVOR **pr, PROCES *p);
int brisi(CVOR **pf, CVOR **pr, PROCES *s);
void brisi_red(CVOR **pf, CVOR **pr);

int main()
{
    int n;
    printf("Unesite broj procesa: ");
    scanf("%d", &n);
    time_t t;
    CVOR *f = 0, *r = 0;
    srand(time(&t));
    PROCES p;
    char start[6];
    for (int i = 0; i < n; i++)
    {
        char ime[20] = "proces";
        char c[8];
        CVOR p;
        itoa(i + 1, c, 10);
        strcat(ime, c);
        strcpy(p.p.naziv, ime);
        p.p.v = rand() % (5 + 1 - 1) + 1;
        printf("%d: %s - %ds\n", i + 1, p.p.naziv, p.p.v);
        dodaj(&f, &r, &p);
    }
    do
    {
        printf("Unesite START za izrvsavanje procesa: ");
        scanf("%s", start);
    } while (strcmp(start, "START"));
    int i = 0;
    while (brisi(&f, &r, &p))
    {
        i++;
        printf("naziv_procesa:%s ; vrijeme_izvrsavanja: %d [s].\n", p.naziv, p.v);
        sleep(p.v);
    }
    return 0;
}

void dodaj(CVOR **pf, CVOR **pr, PROCES *p)
{
    CVOR *novi = (CVOR *)malloc(sizeof(CVOR));
    novi->p = *p;
    novi->sljedeci = 0;
    if (*pf == 0)
        *pf = *pr = novi;
    else
    {
        (*pr)->sljedeci = novi;
        *pr = novi;
    }
}
int brisi(CVOR **pf, CVOR **pr, PROCES *s)
{
    if (*pf == 0)
        return 0;
    CVOR *p = *pf;
    *s = p->p;
    if (*pf == *pr)
        *pf = *pr = 0;
    else
        *pf = p->sljedeci;
    free(p);
    return 1;
}
void brisi_red(CVOR **pf, CVOR **pr)
{
    PROCES pom;
    while (brisi(pf, pr, &pom))
        ;
}
