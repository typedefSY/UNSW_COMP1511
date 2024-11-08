//Steve Yang z5374603
#include <stdio.h>

int main(void)
{
    int height, length, row, col;
    row = 0;
    col = 0;
    
    printf("Please enter the height of the sawtooth: ");
    scanf("%d", &height);
    printf("Please enter the length of the sawtooth: ");
    scanf("%d", &length);
    
    while (row <= height - 1)
    {
        col = 0;
        while (col <= length - 1)
        {
            if (col == length - 1 && col % height == row % height)
                printf("*\n");
            else if (col % height == row % height || col % height == 0)
            {
                printf("*");
            }
            else if(col == length - 1)
                printf("\n");
            else
                printf(" ");
            col += 1;
        }
        row += 1;
    }
    
    return 0;
}
