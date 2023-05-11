#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MAX2 30
typedef struct red
{
    int niz[MAX];
    int f, r;
} RED;
typedef struct stek
{
    int n;
    struct stek *sljedeci;
} STEK;

int isFull(RED *bafer);
int isEmpty(RED *bafer);
int dodaj(RED *bafer, int podatak);
int brisi(RED *bafer, int *podatak);
int pisi(RED *bafer);
int pop(STEK **tos, int *n);
void push(STEK **tos, int *n);
void pisi_stek(STEK **tos);

int main()
{
    RED bafer;
    bafer.f = bafer.r = -1;
    int n = 0;
    char c;
    int broj;
    STEK *tos = 0;

    do
    {
        printf("===================================================\n");
        printf("Dodavanje[D], brisanje [B], prikaz [P], kraj [0]? ");
        scanf("\n%c", &c);
        if (c == 'D')
        {
            printf("  Unesite broj: ");
            scanf("%d", &broj);
            if (dodaj(&bafer, broj) == 0)
                printf("  Bafer je pun!\n");
            else
            {
                (push(&tos, &broj));
                n++;
            }
        }
        else if (c == 'B')
        {
            if (brisi(&bafer, &broj))
                printf("  Obrisan je broj: %d\n", broj);
            else
                printf("  Bafer je prazan!\n");
        }
        else if (c == 'P')
        {
            printf("  Sadrzaj bafera: ");
            if (pisi(&bafer) == 0)
                printf("\n  Bafer je prazan!\n");
            else
                printf("\n");
        }
        else if (c != '0')
            printf("  Nepoznata opcija - '%c'.\n", c);
    } while (c != '0');
    printf("Nakon skidanja svih brojeva sa steka: \n");
    pisi_stek(&tos);
    printf("KRAJ!\n");
    return 0;
}

int dodaj(RED *bafer, int podatak)
{
    if (isFull(bafer))
        return 0;
    if (bafer->f == -1)
        bafer->f = 0;
    bafer->r = (bafer->r + 1) % MAX;
    bafer->niz[bafer->r] = podatak;
    return 1;
}
int isFull(RED *bafer) { return (bafer->r + 1) % MAX == bafer->f; }
int isEmpty(RED *bafer) { return bafer->f == -1; }
int brisi(RED *bafer, int *podatak)
{
    if (isEmpty(bafer))
        return 0;
    *podatak = bafer->niz[bafer->f];
    if (bafer->f == bafer->r)
        bafer->f = bafer->r = -1;
    else
        bafer->f = (bafer->f + 1) % MAX;
    return 1;
}
int pisi(RED *bafer)
{
    if (isEmpty(bafer))
        return 0;
    int i = bafer->f;
    if (bafer->f <= bafer->r)
    {
        while (i <= bafer->r)
            printf("%d ", bafer->niz[i++]);
    }
    else
    {
        while (i <= MAX - 1)
            printf("%d ", bafer->niz[i++]);
        i = 0;
        while (i <= bafer->r)
            printf("%d ", bafer->niz[i++]);
    }
    return 1;
}

int pop(STEK **tos, int *art)
{
    if (*tos == 0)
        return 0;
    STEK *p = *tos;
    *art = p->n;
    *tos = p->sljedeci;
    free(p);
    return 1;
}

void push(STEK **tos, int *n)
{
    STEK *novi = (STEK *)malloc(sizeof(STEK));
    novi->n = *n;
    novi->sljedeci = *tos;
    *tos = novi;
}
void pisi_stek(STEK **tos)
{
    int n;
    while (pop(tos, &n))
        printf("%d ", n);
}
