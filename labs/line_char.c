// z5374603 Steve Yang
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int main(void)
{
    int character;
    int i = 0;
    int n;
    char letter[257];
    character = getchar();
    while (character != '\n')
    {
        letter[i++] = character;
        character = getchar();
    }
    scanf(" %d", &n);
    printf("The character in position %d is '%c'\n", n, letter[n]);
    
    return 0;
}

