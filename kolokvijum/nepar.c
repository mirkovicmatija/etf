#include <stdio.h>

int main()
{
    int a;

    scanf("%d", &a);

    for (int i = a; i <= 2 * a; i++)
    {
        int del_br = 0;
        for (int del = 3; del <= i / 2; del += 2)
            del_br += (i % del) ? 0 : 1;
        if (del_br >= 3)
            printf("%d \n", i);
    }

    return 0;
}