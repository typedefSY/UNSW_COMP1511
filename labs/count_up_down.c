//Steve Yang z5374603
#include <stdio.h>

int main(void)
{
    int num, i;
    i = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    if (num >= 0)
    {
        while (i <= num)
        {
            printf("%d\n", i);
            i++;
        }
    }
    else
    {
        while (i >= num)
        {
            printf("%d\n", i);
            i--;
        }
    }
    return 0;
}
