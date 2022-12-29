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

    int n;
    printf("Unesite broj elemenata niza: ");
    scanf("%d", &n);
    DOKU *niz = formiraj(&n);
    for (int i = 0; i < n; i++)
    {
        ispisi(niz[i]);
    }
    free(niz);
    return 0;
}
