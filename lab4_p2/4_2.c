
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float povrsina(float f) { return f * f * 3.14; }

int main(int argc, char const *argv[])
{
    FILE *f_buffer;

    if (argc != 2)
    {
        return 1;
    }

    f_buffer = fopen(argv[1], "r");
    if (f_buffer == NULL)
    {
        fclose(f_buffer);
        return 1;
    }

    float x, y, r, P;
    char max[100];

    while (fscanf(f_buffer, "(%f,%f,%f)\n", &x, &y, &r) == 3)
    {
        if (r > P)
        {
            P = r;
            sprintf(max, "(%.3f,%.3f,%.3f)", x, y, r);
        }
    }
    printf("Najvecu povrsinu (P = %f ) ima krug: %s \n", povrsina(P), max);
    fclose(f_buffer);
    return 0;
}
