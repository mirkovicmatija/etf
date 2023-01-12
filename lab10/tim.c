#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pogodci, primljeni, bodovi;
    char naziv[32];
} TIM;

void ucitaj(TIM *t)
{
    printf("naziv: ");
    scanf("%s", t->naziv);
    scanf("%d", &t->pogodci);
    scanf("%d", &t->primljeni);
    scanf("%d", &t->bodovi);
}

TIM *formiraj(int *ptr)
{
    TIM *niz = (TIM *)calloc(*ptr, sizeof(TIM));
    for (int i = 0; i < *ptr; i++)
    {
        ucitaj(niz + i);
    }
    return niz;
}

void sortiraj(TIM *t, int br)
{
    for (int i = 0; i < br; i++)
    {
        for (int j = i; j < br; j++)
        {
            if (((t + i)->bodovi < t[j].bodovi) || (t[i].bodovi == t[j].bodovi && t[i].pogodci - t[i].primljeni < t[j].pogodci - t[j].primljeni) || ((t[i].bodovi == t[j].bodovi && t[i].pogodci - t[i].primljeni == t[j].pogodci - t[j].primljeni) && t[i].pogodci < t[j].pogodci))
            {
                TIM p = t[i];
                t[i] = t[j];
                t[j] = p;
            }
        }
    }
}

void ispisi(TIM *tim, int br)
{
    printf("               NAZIV               GPO GPR GR BOD\n");
    for (int i = 0; i < br; i++)
    {
        printf("%d: %-32s %2d %3d %2d %3d\n", i + 1, tim[i].naziv, tim[i].pogodci, tim[i].primljeni, tim[i].pogodci - tim[i].primljeni, tim[i].bodovi);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Unesite broj timova: ");
    scanf("%d", &n);
    TIM *niz = formiraj(&n);
    sortiraj(niz, n);
    ispisi(niz, n);
    free(niz);
    return 0;
}
