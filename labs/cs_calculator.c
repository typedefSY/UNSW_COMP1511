//Steve Yang z5374603
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int instruction;
    int num_1;
    int num_2;
    
    printf("Enter instruction: ");
    while (scanf("%d", &instruction) != EOF)
    {
        if (instruction == 1)
        {
            scanf("%d", &num_1);
            printf("%d\n", num_1 * num_1);
        }
        else
        {
            scanf("%d %d", &num_1, &num_2);
            num_1 = pow(num_1, num_2);
            printf("%d\n", num_1);
        }
        printf("Enter instruction: ");
    }
    return 0;
}
