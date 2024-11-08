//Steve Yang z5374603
#include <stdio.h>

char *negative(int n)   
{
    if (n < 0)  
        return "Don't be so negative!\n";
    else if (n > 0)
        return "You have entered a positive number.\n";
    else
        return "You have entered zero.\n";
}

int main(void)
{
    int num;

    scanf("%d", &num);
    
    printf("%s", negative(num));
    return 0;
}