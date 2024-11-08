//Steve Yang z5374603
#include <stdio.h>

int main (void)
{
    int boxes;
    printf("How many boxes: ");
    scanf("%d", &boxes);
    int size = (boxes * 3) + (boxes - 1);   //the length of whole boxes
    int i = 1; // Row counter
    int j = 1; // Column counter
    int mid_row = boxes * 2;

    // For printing each row
    while (i <= size)
    {
        //restart column counter
        j = 1;
        if (i < mid_row)
        {
            // For printing each column
            while (j <= size)
            {
                // If the current row is odd
                if ((i % 2) != 0)
                {
                    // If the current column is odd
                    if ((j % 2) != 0)
                        printf("*");
                    else
                    {
                        // If the current column is even
                        if ((j < i) || ((size - j) < i))
                            printf("-");
                        else
                            printf("*");
                    }
                }
                // If the current row is even
                else
                {
                    // If the current column is odd
                    if ((j % 2) != 0)
                    {
                        if ((j < i) || ((size - j) < i))
                            printf("*");
                        else
                            printf("-");
                    }
                    else
                        // If the current column is even
                        printf("-");
                }
                j++;
            }
        }
        else if (i == mid_row)
        {
            while (j <= size)
            {
                if ((j % 2) != 0)
                    printf("*");
                else
                    printf("-");
                j++;
            }
        }
        else
        {
            // For printing each column
            while (j <= size)
            {
                // If the current row is odd
                if ((i % 2) != 0)
                {
                    // If the current column is odd
                    if ((j % 2) != 0)
                        printf("*");
                    else
                    {
                        // If the current column is even
                        if ((j > i) || ((size - j) >= i))
                            printf("-");
                        else
                            printf("*");
                    }
                }
                // If the current row is even
                else
                {
                    // If the current column is odd
                    if ((j % 2) != 0)
                    {
                        if ((j > i) || ((size - j) >= i))
                            printf("*");
                        else
                            printf("-");
                    }
                    else
                        // If the current column is even
                        printf("-");
                }
                j++;
            }
        }
        printf("\n");
        i++;
    }

    return 0;
}
