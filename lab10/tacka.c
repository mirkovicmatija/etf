#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct
{
    double x, y;
    char oznaka;
} TACKA;

typedef struct
{
    TACKA a, b, c;
} TROUGAO;

double udaljenost(TACKA t1, TACKA t2)
{
    return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}

void citaj(TACKA *t)
{
    scanf("%lf %lf %c", &t->x, &t->y, &t->oznaka);
}

int provjera(TACKA *t)
{
    return t[0].x * (t[1].y - t[2].y) + t[1].x * (t[2].y - t[0].y) + t[2].x * (t[0].y - t[1].y);
}

TROUGAO trougao(TACKA *t)
{
    TROUGAO tr;
    tr.a.x = t[0].x;
    tr.a.y = t[0].y;
    tr.a.oznaka = t[0].oznaka;
    tr.b.x = t[1].x;
    tr.b.y = t[1].y;
    tr.b.oznaka = t[1].oznaka;
    tr.c.x = t[2].x;
    tr.c.y = t[2].y;
    tr.c.oznaka = t[2].oznaka;
    return tr;
}

double obim(TROUGAO t)
{
    return udaljenost(t.a, t.b) + udaljenost(t.a, t.c) + udaljenost(t.b, t.c);
}

TACKA *teziste(TROUGAO *t)
{
    TACKA *tac = (TACKA *)malloc(sizeof(TACKA));
    tac->x = (t->a.x + t->b.x + t->c.x) / 3;
    tac->y = (t->a.y + t->b.y + t->c.y) / 3;
    tac->oznaka = 'T';
    return tac;
}

int main(int argc, char const *argv[])
{
    TACKA a[3];
    for (int i = 0; i < 3; i++)
    {
        citaj(&a[i]);
    }
    if (!provjera(a))
    {
        printf("Nije moguce konstruisati trougao");
    }
    else
    {
        TROUGAO tr = trougao(a);
        TACKA *tacka = teziste(&tr);
        printf("%lf", tacka->x);
        printf(" %lf ", obim(tr));
    }
    return 0;
}
