#include <stdio.h>
#include <stdlib.h>

typedef struct file
{
    char name[128], extension[4];
    int size;
} DOKU;

DOKU *formiraj(int *n)
{
    DOKU *niz = (DOKU *)calloc(*n, sizeof(DOKU));
    for (int i = 0; i < *n; i++)
    {
        scanf("%s", (niz + i)->name);
        scanf("%s", (niz + i)->extension);
        scanf("%d", &(niz + i)->size);
    }
    return niz;
};

void ispisi(DOKU d)
{
    printf("%s.%s | %d\n", d.name, d.extension, d.size);
}

int main(int argc, char const *argv[])
{

    int n, vel;
    printf("Unesite broj elemenata niza: ");
    scanf("%d", &n);
    DOKU *niz = formiraj(&n);
    scanf("%d", &vel);
    for (int i = 0; i < n; i++)
    {
        if (niz[i].size > vel)
            ispisi(niz[i]);
    }
    free(niz);
    return 0;
}
