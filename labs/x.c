//Steve Yang z5374603
#include <stdio.h>

int main(void)
{
    int row, col, n;
    int size;
    printf("Enter size: ");
    scanf("%d", &n);
    size = n/2 + 1;
    for(row = 0; row <= size-1; row++)
    {
        for(col = 0; col < row; col++)
        {
            printf("-");
        }
        printf("*");
        for(col = 1; col < 2 * (size - row - 1); col++)
        {
            printf("-");
        }
        if (row < size-1)
            printf("*");
        for(col = 0;col < row; col++)
        {
            printf("-");
        }
        printf("\n");
    }
    //After middle*
    for(row = size - 1; row > 0; row--)
    {
        for(col = 0; col < row-1; col++)
        {
            printf("-");
        }
        printf("*");
        for(col = 0; col < 2 * (size - row) - 1; col++)
        {
            printf("-");
        }
        printf("*");
        for(col = 0; col < row - 1; col++)
        {
            printf("-");
        }
        printf("\n");
    }
    return 0;
}

