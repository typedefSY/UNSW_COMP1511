// Find the largest sum of numbers in a z shape.
//Steve Yang z5374603
#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 100

int largest_z_sum(int size, int array[MAX_SIZE][MAX_SIZE]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    int array[MAX_SIZE][MAX_SIZE];

    // Get the array size.
    int size;
    printf("Enter 2D array side length: ");
    scanf("%d", &size);
    assert(size >= 3);

    // Scan in values for the array.
    printf("Enter 2D array values:\n");
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            assert(scanf("%d", &array[i][j]) == 1);
            j++;
        }
        i++;
    }

    printf("The largest z sum is %d.\n", largest_z_sum(size, array));

    return 0;
}

// Return the largest sum of numbers in a z shape.
int largest_z_sum(int size, int array[MAX_SIZE][MAX_SIZE])
{
    int sum[MAX_SIZE] = {0};
    int num = 0;
    int row = 0;
    int col = 0;
    int big = 0;
    while (num <= size - 3)
    {
        col = num;
        row = 0;
        while (col < size)
        {
            sum[num] += array[row][col];
            col++;
        }
        col -= 2;
        row += 1;
        while (row < size - num)
        {
            sum[num] += array[row][col];
            col--;
            row++;
        }
        row -= 1;
        col += 2;
        while (col < size)
        {
            sum[num] += array[row][col];
            col++;
        }
        num++;
    }
    
    //bubble sort, let sum[0] becomes the biggest one
    for (int n = 0; n < num; n++)
    {
        for (int j = 0; j < num - n; j++)
        {
            if (sum[j + 1] > sum[j])
            {
                big = sum[j + 1];
                sum[j +1 ] = sum[j];
                sum[j] = big;
            }
        }
    }
    
    return sum[0];
}
