#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double el[50][50];
    int n, m;
} MAT;

MAT *ucitaj()
{
    MAT *matrica = malloc(sizeof(MAT));

    scanf("%d %d", &matrica->m, &matrica->n);

    for (int i = 0; i < matrica->m; i++)
    {
        for (int j = 0; j < matrica->n; j++)
        {
            scanf("%lf", &matrica->el[i][j]);
        }
    }
    return matrica;
}

void pisi(const MAT *a)
{
    for (int i = 0; i < a->m; i++, printf("\n"))
    {
        for (int j = 0; j < a->n; j++, printf("\t"))
        {
            printf("%lf", a->el[i][j]);
        }
    }
}

MAT *transponuj(const MAT *a)
{
    MAT *t = malloc(sizeof(MAT));
    t->m = a->n;
    t->n = a->m;
    for (int i = 0; i < t->n; i++)
    {
        for (int j = 0; j < t->m; j++)
        {
            t->el[i][j] = a->el[j][i];
        }
    }
    return t;
}

MAT *saberi(const MAT *a, const MAT *b)
{

    if (a->n != b->m)
    {
        return NULL;
    }
    MAT *c = malloc(sizeof(MAT));
    c->m = a->m;
    c->n = b->n;
    for (int i = 0; i < c->m; i++)
    {
        for (int j = 0; j < c->n; j++)
        {
            (*c).el[i][j] = 0;
            for (int k = 0; k < a->n; k++)
            {
                (*c).el[i][j] += (*a).el[i][k] * (*b).el[k][j];
            }
        }
    }

    return c;
}

int main(int argc, char const *argv[])
{
    MAT *m = ucitaj();
    pisi(m);
    MAT *tm = transponuj(m);
    pisi(tm);
    MAT *z = saberi(m, tm);
    pisi(z);

    free(m);
    free(tm);
    free(z);

    return 0;
}
