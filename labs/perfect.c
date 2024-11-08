//Steve Yang z5374603
#include<stdio.h>

int main(void)
{
    int num;
    int factor = 1;
    int sum = 0;
    int real_fac;
    
    printf("Enter number: ");
    scanf("%d", &num);
    printf("The factors of %d are: \n", num);
    while (factor <= num )
    {
        if (num % factor == 0)
        {
            sum += factor;
            printf("%d\n", factor);
        }
        factor++;
    }
    
    printf("Sum of factors = %d\n", sum);
    real_fac = sum - num;
    if (real_fac == num)
    {
        printf("%d is a perfect number\n", num);
    }
    else
        printf("%d is not a perfect number\n", num);
    return 0;
}
