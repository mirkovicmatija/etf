#include <stdio.h>

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    int *pa = &a;
    int *pb = &b;

    if (b < a)
    {
        int p = *pa;
        *pa = *pb;
        *pb = p;
    }

    printf("%d %d", a, b);

    for (int i = a; i <= b; i++)
    {
        int del_br = 0;
        for (int del = 2; del <= i / 2; del++)
            del_br += (i % del) ? 0 : 1;
        if (del_br > 4)
            printf("%d \n", i);
    }

    return 0;
}