#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char str[100]; // informacioni sadrzaj
    struct node *left, *right;
} NODE;

NODE *new(char *data)
{
    NODE *n = malloc(sizeof(NODE));
    n->left = NULL;
    n->right = NULL;
    strcpy(n->str, data);
    return n;
}

NODE *addLeft(NODE *n, char *data)
{
    NODE *ne = new (data);
    if (n->left)
        n->left = ne->left;
    n->left = ne;
    return ne;
}

NODE *addRight(NODE *n, char *data)
{
    NODE *ne = new (data);
    if (n->right)
        n->right = ne->right;
    n->right = ne;
    return ne;
}

void preorder(NODE *root)
{
    if (root)
    {
        printf("%s", root->str);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE *root)
{
    if (root)
    {

        inorder(root->left);
        printf("%s", root->str);
        inorder(root->right);
    }
}

void postorder(NODE *root)
{
    if (root)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%s", root->str);
    }
}
void delete(NODE *root)
{
    if (root)
    {
        delete (root->left);
        delete (root->right);
        free(root);
    }
}

int broj_cvorova(NODE *root)
{
    if (root == 0)
        return 0;
    return broj_cvorova(root->left) + 1 + broj_cvorova(root->right);
}

int broj_listova(NODE *root)
{
    if (root == 0)
        return 0;
    if (root->left == 0 && root->right == 0)
        return 1;
    return broj_listova(root->left) + broj_listova(root->right);
}

int dubina(NODE *root)
{
    if (root == 0)
        return 0;
    int dl = dubina(root->left), dd = dubina(root->right);
    return 1 + (dl > dd ? dl : dd);
}

int main(int argc, char const *argv[])
{

    NODE
        *korijen = new ("A"),
        *B, *C, *D, *E, *F, *G, *H, *I, *J;

    B = addLeft(korijen, "B");
    C = addRight(korijen, "C");
    D = addLeft(B, "D");
    E = addRight(B, "E");
    F = addRight(C, "F");
    G = addLeft(D, "G");
    H = addRight(E, "H");
    I = addLeft(F, "I");
    J = addLeft(H, "J");

    printf("--- PREORDER:  ");
    preorder(korijen);
    printf("\n");
    printf("--- INORDER:   ");
    inorder(korijen);
    printf("\n");
    printf("--- POSTORDER: ");
    postorder(korijen);
    delete (korijen);

    return 0;
}
