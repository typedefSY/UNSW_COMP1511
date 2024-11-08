//z5374603 Steve Yang
#include<stdio.h>
int main(void)
{
    int sum = 0;
    int num = 0;
    int number = 0;
    int i = 0;
    printf("How many numbers: ");
    scanf("%d", &num);
    while (i < num)
    {
        scanf("%d", &number);
        sum += number;
        i++;
    }
    printf("The sum is: %d\n", sum);
    
    return 0;
}
