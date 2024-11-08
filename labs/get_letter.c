//Steve Yang z5374603
#include <stdio.h>

struct index_To_Letter
{
    int index;
    char lower;
    char upper;
};

int upper_case(char c)
{
    if (c == 'y')
        return 1;
    else
        return 0;
}

int main(void)
{
    char c;
    struct index_To_Letter dictionary;
    
    printf("Uppercase: ");
    scanf("%c", &c);
    if (c != 'y' && c !='n')
    {
        printf("You need to enter 'y' or 'n'\n");
        printf("Exiting the program with error code 1\n");
        return 0;
    }

    printf("Index: ");
    scanf("%d", &dictionary.index);
    if (dictionary.index >= 1 && dictionary.index <= 26)
    {
        dictionary.lower = 96 + dictionary.index;
        dictionary.upper = 64 + dictionary.index;
        if (upper_case(c) == 1)
            printf("the letter is %c\n", dictionary.upper);
        else
            printf("The letter is %c\n", dictionary.lower);
    }
    else
    {
        printf("You need to enter a number between 1 and 26 inclusive\n");
        printf("Exiting the program with error code 2\n");
        return 0;
    }
    
    
    return 0;
}