#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    void *data;
    struct node *prev, *next;
} NODE;

int cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

void write_one(const void *x)
{
    printf("%s\n", (char *)x);
}

NODE *search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *))
{
    if (!head)
    {
        return 0;
    }
    while ((*cmp)(head->data, data) < 0 && (*cmp)(tail->data, data) > 0)
    {
        head = head->next;
        tail = tail->prev;
    }
    if (!(*cmp)(head->data, data))
    {
        return head;
    }
    if (!(*cmp)(tail->data, data))
    {
        return tail;
    }
    return 0;
}

void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    if (search(*phead, *ptail, data, (*cmp)))
    {
        return;
    }
    NODE *p, *q, *new = calloc(1, sizeof(NODE));
    new->data = data;
    if (*phead == 0)
    {
        *phead = *ptail = new;
    }
    else if ((*cmp)((*phead)->data, data) > 0)
    {
        new->next = *phead;
        (*phead)->prev = new;
        *phead = new;
    }
    else if ((*cmp)((*ptail)->data, data) < 0)
    {
        new->prev = *ptail;
        (*ptail)->next = new;
        *ptail = new;
    }
    else
    {
        for (p = *phead, q = *ptail; (*cmp)((p)->data, data) < 0 && (*cmp)((q)->data, data) > 0; p = p->next, q = q->prev)
        {
            if ((*cmp)(q->data, data) < 0)
            {
                p = q;
            }
            new->next = p->next;
            new->prev = p;
            (p->next)->prev = new;
            p->next = new;
        }
    }
}

void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    NODE *p = search(*phead, *ptail, data, (*cmp));
    if (!p)
        return;
    if (p == *phead && p == *ptail)
    {
        *phead = *ptail = 0;
    }
    else if (p == *phead)
    {
        *phead = (*phead)->next;
        (*phead)->prev = 0;
    }
    else if (p == *ptail)
    {
        *ptail = (*ptail)->prev;
        (*ptail)->next = 0;
    }
    else
    {
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;
    }
    free(p->data);
    free(p);
}

void write(NODE *head, void (*write_one)(const void *))
{
    while (head)
    {
        (*write_one)(head->data);
        head = head->next;
    }
}

void delete_list(NODE **phead, NODE **ptail)
{
    NODE *p = *phead;
    while (*phead)
    {
        p = (*phead)->next;
        free(*phead);
        *phead = p;
    }
}

int main(int argc, char const *argv[])
{
    NODE *head = 0, *tail = 0;
    char *s1 = (char *)calloc(strlen("ponedjeljak") + 1, sizeof(char));
    strcpy(s1, "ponedjeljak");
    char *s2 = (char *)calloc(strlen("utorak") + 1, sizeof(char));
    strcpy(s2, "utorak");
    char *s3 = (char *)calloc(strlen("srijeda") + 1, sizeof(char));
    strcpy(s3, "srijeda");
    char *s4 = (char *)calloc(strlen("cetvrtak") + 1, sizeof(char));
    strcpy(s4, "cetvrtak");
    char *s5 = (char *)calloc(strlen("petak") + 1, sizeof(char));
    strcpy(s5, "petak");
    char *s6 = (char *)calloc(strlen("subota") + 1, sizeof(char));
    strcpy(s6, "subota");
    add(&head, &tail, s1, &cmp);
    add(&head, &tail, s2, &cmp);
    add(&head, &tail, s3, &cmp);
    add(&head, &tail, s4, &cmp);
    add(&head, &tail, s5, &cmp);
    add(&head, &tail, s6, &cmp);
    write(head, write_one);
    delete (&head, &tail, "subota", cmp);
    printf("\nNakon brisanja:\n\n");
    write(head, write_one);
    delete_list(&head, &tail);
    return 0;
}
