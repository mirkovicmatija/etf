#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    do
    {
        scanf("%d %d", &a, &b);
    } while (a > b);

    for (int i = a; i <= b; i++)
    {
        int kopija = i, br = 0;
        while (kopija)
        {
            br += (kopija % 2) ? 1 : 0;
            kopija /= 2;
        }
        if (br > 2)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
