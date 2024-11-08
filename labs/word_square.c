//z5374603 Steve Yang
#include <stdio.h>

#define MAX_LENGTH 1024

int main(void)
{
    char string[MAX_LENGTH] = {0};
    int i = 0;
    int character;
    int j = 0;
    
    printf("Input word: ");
    character = getchar();
    while (character != '\n')
    {
        string[i++] = character;
        character = getchar();
    }
    printf("\n");
    while (string[j] != '\0')
        j++;
    printf("Word square is:\n");
    for (int m = 0; m < j; m++)
    {
        for (int k = 0; k < j; k++)
        {
            printf("%c", string[k]);
        }
        printf("\n");
    }
    
    
    return 0;
}