#include <stdio.h>

int clan(int n)
{
    return (n < 4) ? n : clan(n - 1) + clan(n - 2) + clan(n - 3);
}

int main(int argc, char const *argv[])
{
    int b;
    scanf("%d", &b);
    printf("%d", clan(b));
    return 0;
}
