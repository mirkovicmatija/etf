#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct film
{
    char naziv[64];
    char zanr[16];
    char reziser[32];
    char glumci[512];
    int godina;
} FILM;

typedef struct cvor
{
    FILM data;
    struct cvor *left, *right;
} CVOR;

int filmNazivCmp(char *nazivKorijen, char *nazivFilm)
{

    char str1[64], str2[64];

    strcpy(str1, nazivKorijen);
    strcpy(str2, nazivFilm);

    for (int i = 0; str1[i] != '\0'; i++)
        str1[i] = (char)toupper((int)(str1[i]));

    for (int i = 0; str2[i] != '\0'; i++)
        str2[i] = (char)toupper((int)(str2[i]));

    return strcmp(nazivKorijen, nazivFilm);
}

CVOR *addNode(FILM f)
{
    CVOR *novi = malloc(sizeof(CVOR));
    novi->left = NULL;
    novi->right = NULL;
    novi->data = f;
    return novi;
}

CVOR *addToTree(CVOR *root, FILM f)
{
    if (root == NULL)
    {
        return addNode(f);
    }

    int c = filmNazivCmp(root->data.naziv, f.naziv);
    if (c < 0)
    {
        root->left = addToTree(root->left, f);
    }
    if (c > 0)
    {
        root->right = addToTree(root->right, f);
    }
    else
    {
        root->data.godina = f.godina;
        strcpy(root->data.zanr, f.zanr);
        strcpy(root->data.reziser, f.reziser);
        strcpy(root->data.glumci, f.glumci);
        return root;
    }
    return root;
}

FILM *search(CVOR *root, char *key)
{
    if (root == NULL)
    {
        return NULL;
    }
    int c = filmNazivCmp(root->data.naziv, key);
    if (c == 0)
    {
        return &(root->data);
    }
    if (c < 0)
    {
        return search(root->left, key);
    }
    if (c > 0)
    {
        return search(root->right, key);
    }
    return &(root->data);
}

CVOR *deleteMovie(CVOR *root, char *key)
{
    if (root == NULL)
    {
        return NULL;
    }
    int c = filmNazivCmp(root->data.naziv, key);
    if (c < 0)
    {
        deleteMovie(root->left, key);
    }
    else if (c > 0)
    {
        deleteMovie(root->right, key);
    }
    else if (!root->left && !root->right)
    {
        free(root);
        return NULL;
    }
    else if (root->left == NULL)
    {
        CVOR *q = root->right;
        free(root);
        return q;
    }
    else if (root->right == NULL)
    {
        CVOR *q = root->left;
        free(root);
        return q;
    }
    else
    {
        CVOR *max = root->left;
        while (max->right)
        {
            max = max->right;
        }
        root->data.godina = max->data.godina;
        strcpy(root->data.zanr, max->data.zanr);
        strcpy(root->data.naziv, max->data.naziv);
        strcpy(root->data.reziser, max->data.reziser);
        strcpy(root->data.glumci, max->data.glumci);
        root->left = deleteMovie(root->left, max->data.naziv);
    }
    return root;
}

void printTree(CVOR *root)
{
    if (root)
    {
        printf("%s", root->data.naziv);
        printTree(root->left);
        printTree(root->right);
    }
}

void deleteTree(CVOR *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main(int argc, char const *argv[])
{
    CVOR *korijen = NULL;

    FILM f, *pretraga;

    short opcija;

    short running = 1;
    while (running)
    {

        printf("=== MENI \n");
        printf("=== 1 - Unesi u stablo\n");
        printf("=== 2 - Pretrazi stablo\n");
        printf("=== 3 - Brisi cvor\n");
        printf("=== 4 - Ispisi stablo (u rastucem redoslijedu)\n");
        printf("=== 5 - Brisi cijelo stablo\n");
        printf("=== 6 - Izadji\n");

        printf("===> OPCIJA: ");
        scanf("%hd", &opcija);

        switch (opcija)
        {

        case 1:
            printf("===> NAZIV FILMA:    ");
            scanf("%s", f.naziv);
            printf("===> ZANR FILMA:     ");
            scanf("%s", f.zanr);
            printf("===> REZISER FILMA:  ");
            scanf("%s", f.reziser);
            printf("===> GLUMCI U FILMU: ");
            scanf("%s", f.glumci);
            printf("===> GODINA OBJAVE:  ");
            scanf("%d", &(f.godina));
            korijen = addToTree(korijen, f);
            break;

        case 2:
            printf("===> NAZIV FILMA: ");
            scanf("%s", f.naziv);
            pretraga = search(korijen, f.naziv);
            printf("Adresa filma: %p\n", pretraga);
            break;

        case 3:
            printf("===> NAZIV FILMA: ");
            scanf("%s", f.naziv);
            deleteMovie(korijen, f.naziv);
            break;

        case 4:
            printf("--- Ispis zapocet...\n");
            printTree(korijen);
            printf("--- Ispis gotov!\n");
            break;

        case 5:
            printf("--- Brisanje zapoceto...\n");
            deleteTree(korijen);
            printf("--- Brisanje gotovo!\n");
            break;

        case 6:
            printf("--- Dovidjenja!\n");
            running = 0;
            break;

        default:
            printf("--- GRESKA: OPCIJA NIJE U MENIJU!\n");
            break;
        }
    }

    return 0;
}
