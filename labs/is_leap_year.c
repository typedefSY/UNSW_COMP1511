//Steve Yang z5374603
#include <stdio.h>

int leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else return 0;
}

int main(void)
{
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    if (leap_year(year) == 1)
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year.\n", year);
    
    return 0;
}