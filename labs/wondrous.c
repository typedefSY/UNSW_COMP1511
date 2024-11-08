//Steve Yang z5374603
#include<stdio.h>

int main(void)
{
    int num;
    
    printf("What number would you like to see: ");
    scanf("%d", &num);
    
    while (num != 1)
    {
        for (int i = 0; i < num; i++)
        {
            printf("*");
        }
        printf("\n");
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
            num = 3 * num + 1;
    }
    
    
    
    
    return 0;
}
