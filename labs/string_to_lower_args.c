//Steve Yang z5374603
#include<stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    char low_letter[100][100] = {0};
     while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            low_letter[i][j] = argv[i][j];
            j++;
        }
        i++;
    }
    j = 0;
    while (j < argc)
    {
        k = 0;
        while (low_letter[j][k] != '\0')
        {
            if (low_letter[j][k] >= 'A' && low_letter[j][k] <= 'Z')
                low_letter[j][k] += 32;
            k++;
        }
        j++;
    }
    i = 1;
    while (i < argc)
    {
        printf("%s ", low_letter[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}


