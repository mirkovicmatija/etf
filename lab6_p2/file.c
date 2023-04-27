#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char *ime, *prezime, *indeks;
} STUDENT;

typedef struct cvor
{
    STUDENT stu;
    struct cvor *next;
} CVOR;

CVOR *add(CVOR **phead)
{
    char ibuff[32], pbuff[32], inbuff[16];
    CVOR *new = malloc(sizeof(CVOR));
    printf("Unesi: ");
    scanf("%s %s %s", ibuff, pbuff, inbuff);

    new->stu.ime = calloc(strlen(ibuff) + 1, sizeof(char));
    strcpy(new->stu.ime, ibuff);

    new->stu.prezime = calloc(strlen(pbuff) + 1, sizeof(char));
    strcpy(new->stu.prezime, pbuff);

    new->stu.indeks = calloc(strlen(inbuff) + 1, sizeof(char));
    strcpy(new->stu.indeks, inbuff);

    new->next = *phead;
    *phead = new;
    return new;
}

void ispis(CVOR *head)
{
    while (head)
    {
        printf("%s %s %s \n", head->stu.ime, head->stu.prezime, head->stu.indeks);
        head = head->next;
    }
}

void ispisFile(CVOR *head, FILE *file)
{
    if (file)
    {

        fprintf(file, "====================== ====================== ==========\n");
        fprintf(file, "         IME                  PREZIME           INDEKS  \n");
        fprintf(file, "====================== ====================== ==========\n");
        while (head)
        {
            fprintf(file, "%s %s %s \n", head->stu.ime, head->stu.prezime, head->stu.indeks);
            head = head->next;
        }
        fprintf(file, "====================== ====================== ==========\n");
    }
    else
    {
        printf("Datoteka nije otvorena.");
    }
}

void delete(CVOR **phead)
{
    while (*phead)
    {
        CVOR *p = (*phead)->next;
        free(*phead);
        *phead = p;
    }
}

int main(int argc, char const *argv[])
{
    FILE *file;
    file = fopen("outFile.txt", "w");

    CVOR *glava = 0;
    CVOR *prvi = add(&glava);
    CVOR *drugi = add(&glava);

    CVOR *zamjena = glava;
    CVOR *zamjena1 = glava;

    ispis(zamjena);

    ispisFile(zamjena1, file);

    delete (&glava);
    fclose(file);
    return 0;
}
