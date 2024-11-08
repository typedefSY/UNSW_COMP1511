//Steve Yang z5374603
#include<stdio.h>

int main(void)
{
    int size;
    int row = 1;
    int col = 1;
    
    printf("Enter size: ");
    scanf("%d", &size);

    while (row <= size)
    {
        col = 1;
        while (col <= size)
        {
            if (row % 2 != 0 && row <= size / 2 + 1 && col <= size - row && col >= row - 1)
            { 
                //Line going to the right
                printf("*");
            }
            else if (row % 2 != 0 && row > size / 2 + 1 && col > size - row && col <= row)
            {
                 //Line going to the left
                printf("*");
            }
            else if (col < (size + 1) / 2 && col % 2 != 0 && row >= col + 2 && row <= size - col + 1)
            { 
                //Line going upwards
                printf("*");
            }
            else if (col >= (size + 1) / 2 && col % 2 != 0 && row <= col && row >= size - col + 1)
            { 
                //Line going downwards
                printf("*");
            }
            else
            { 
                // Not part of any line
                printf("-");
            }
            col++;
        }
        printf("\n");
        row++;
    }

    return 0;
}