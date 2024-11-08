//Steve Yang z5374603
#include<stdio.h>

int main(void)
{
    int zero_array[36];
    int num;
    for (int i = 0; i < 36; i++)
    {
        zero_array[i] = 0;
    }
    while (scanf("%d", &num) == 1)
    {
        zero_array[num] = 1;
    }
    for (int j = 0; j < 36; j++)
    {
        printf("%d ", zero_array[j]);    
    }
    printf("\n");
    
    return 0;
}
