//Steve Yang z5374603
#include <stdio.h>
#include <stdlib.h>

int *reverse(int *array_1, int n);
void print(int *array, int n);
int main(void)
{
    int array_1[100];
    int i = 0;
    printf("Enter numbers forwards:\n");
    while (scanf("%d", &array_1[i]) != EOF)
    {
        i++;
    }
    
    print(reverse(array_1, i), i);
    
    return 0;
}

int *reverse(int *array_1, int n)
{
    int i = n - 1;
    int j = 0;
    int *array = (int *) malloc (n * sizeof(int));
    while (i >= 0)
    {
        array[j] = array_1[i];
        j++;
        i--;
    }
    
    return array;
}

void print(int *array, int n)
{
    int i = 0;
    printf("Reversed:\n");
    while (i < n)
    {
        printf("%d\n", array[i]);
        i++;
    }
}
