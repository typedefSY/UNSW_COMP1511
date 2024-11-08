//Steve Yang z5374603
#include <stdio.h>

int main(void)
{
    int num_1, num_2, num_3;
    printf("Enter instruction: ");
    scanf("%d %d %d", &num_1, &num_2, &num_3);
    if (num_1 == 1)
        printf("%d\n", num_2 + num_3);
    else if (num_1 == 2)
        printf("%d\n", num_2 - num_3);
    else
        return 1;
    return 0;
}