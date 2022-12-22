#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, k;
    do
    {
        scanf("%d %d", &n, &k);
    } while ((k < 10) && (n < 1));
    int suma = 0;
    for (int i = 1; i <= n; i++)
    {
        int stepen = 1;
        for (int j = 0; j < k; j++)
        {
            stepen *= i;
        }
        int kopija = stepen, sp = 0;
        while (kopija)
        {
            sp += (kopija % 2) ? 0 : kopija % 10;
            kopija /= 10;
        }
        suma += sp;
        printf("%d %d %d %d %d\n", i, stepen, kopija, sp, suma);
    }
    printf("%d\n", suma);

    return 0;
}
