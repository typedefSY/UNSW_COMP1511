//Steve Yang z5374603
#include <stdio.h>

int main(void)
{
    float sides, rolling_num, max;
    double average;
    int MIN, MAX;
    
    printf("Enter the number of sides on your dice: ");
    scanf("%f", &sides);
    printf("Enter the number of dice being rolled: ");
    scanf("%f", &rolling_num);
    if (sides <= 0 || rolling_num <= 0)
    {
        printf("These dice will not produce a range.\n");
        return 0;
    }
    max = rolling_num * sides;
    MAX = (int)max;
    MIN = (int)rolling_num;
    average = (rolling_num + max) / 2;
    printf("Your dice range is %d to %d.\n", MIN, MAX);
    printf("The average value is %.6f\n", average);
    return 0;
}