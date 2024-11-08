//Steve Yang z5374603
#include<stdio.h>

int main(void)
{
    char letter_1;
    char letter_2;
    char letter_3;
    
    printf("Please enter three characters: ");
    scanf("%c ", &letter_1);
    scanf("%c ", &letter_2);
    scanf("%c", &letter_3);
    
    if (letter_1 < letter_2 && letter_2 < letter_3)
        printf("up\n");
    else if(letter_1 > letter_2 && letter_2 > letter_3)
        printf("down\n");
    else
        printf("neither\n");
    
    return 0;
}
