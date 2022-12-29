#include <stdio.h>

#define MAX 100

/* === DEFINICIJA STRUCT-A POLINOM === */

typedef struct
{

    int stepen;
    int koef[MAX];

} POLINOM;

/* === FUNKCIJE === */

POLINOM citaj()
{

    short st;
    POLINOM pr;

    do
    {
        printf("Stepen polinoma (0 < n < %d): ", MAX);
        scanf("%hd", &st);
    } while (st < 0 || st >= MAX);

    pr.stepen = st;

    for (int i = 0; i < MAX; i++)
        pr.koef[i] = 0;

    for (int i = 0; i < st; i++)
    {
        printf("x^%d: ", i);
        scanf("%d", &pr.koef[i]);
    }

    return pr;
}

void ispisi(POLINOM p)
{

    for (int i = MAX - 1; i >= 0; i--)
    {

        if (p.koef[i] != 0)
        {

            printf("%dx^%d", p.koef[i], i);

            if (i != 0)
                printf(" + ");
        }
    }

    printf("\n");
}

POLINOM saberi(POLINOM p1, POLINOM p2)
{

    POLINOM pr;

    for (int i = 0; i < MAX; i++)
        pr.koef[i] = p1.koef[i] + p2.koef[i];

    return pr;
}

POLINOM pomnozi(POLINOM p1, POLINOM p2)
{

    POLINOM pr;

    for (int i = 0; i < MAX; i++)
        pr.koef[i] = 0;

    if (p1.stepen + p2.stepen >= 100)
    {
        printf("GRESKA: Nije moguce mnoziti polinome stepena vecih og 49.\n");
        return pr;
    }

    for (int i1 = 0; i1 < p1.stepen; i1++)
        for (int i2 = 0; i2 < p2.stepen; i2++)
            pr.koef[i1 + i2] += p1.koef[i1] * p2.koef[i2];

    return pr;
}

/* === KRAJ FUNKCIJA === */

int main()
{

    POLINOM p1, p2, prm;

    p1 = citaj();
    p2 = citaj();

    ispisi(p1);
    ispisi(p2);

    printf("\nRezultat mnozenja:\n\n");
}