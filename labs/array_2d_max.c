//z5374603 Steve Yang
#include <stdio.h>
#define TEST_ARRAY_SIZE 100

// Return the largest number in a 2D square array
// with sides of length side_length.
int array_max(int array[TEST_ARRAY_SIZE][TEST_ARRAY_SIZE], int side_length)
{
    int row = 0;
    int col = 0;
    int num = 0;
    while (row < side_length)
    {
        col = 0;
        while (col < side_length)
        {
            if (num < array[row][col])
            {
                num = array[row][col];
            }
            col++;
        }
        row++;
    }
    
    return num;
}

// This is a simple main function which could be used
// to test your array_max function.
// It will not be marked.

int main(void) {
    int test_array[TEST_ARRAY_SIZE][TEST_ARRAY_SIZE] = {
        { 1,    2,   3,    4  },
        {-1,  -11, -111, -111},
        { 0,   0,   0,    0  },
        { 22, -22,  2,    2  }
    };

    int result;

    result = array_max(test_array, 1);
    printf("Largest value in 1x1 array: %d\n", result);

    result = array_max(test_array, 2);
    printf("Largest value in 2x2 array: %d\n", result);

    result = array_max(test_array, 3);
    printf("Largest value in 3x3 array: %d\n", result);

    result = array_max(test_array, 4);
    printf("Largest value in 4x4 array: %d\n", result);

    return 0;
}
