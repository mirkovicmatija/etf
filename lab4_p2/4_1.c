#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *prvi, *drugi;

    if (argc != 3)
    {
        return 1;
    }
    prvi = fopen(argv[1], "r");
    if (prvi == NULL)
    {
        fclose(prvi);
        return 1;
    }

    drugi = fopen(argv[2], "w");
    if (drugi == NULL)
    {
        fclose(drugi);
        return 1;
    }

    char buffer[100];
    int max = 0, br = 0;
    char maxR[100] = "";

    while (fscanf(prvi, "%s", buffer) != EOF)
    {
        fprintf(drugi, "%s\n", buffer);
        if (strlen(buffer) > strlen(maxR))
        {
            strcpy(maxR, buffer);
            max = br;
        }
        br++;
    }
    printf("Najduza rijec je: %s ", maxR);

    fclose(drugi);
    fclose(prvi);
    return 0;
}
