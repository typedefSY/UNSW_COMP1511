//Steve Yang z5374603
#include<stdio.h>

void change(int num)
{
    if (num == 1)
        printf("one ");
    else if (num == 2)
        printf("two ");
    else if (num == 3)
        printf("three ");
    else if (num == 4)
        printf("four ");
    else if (num == 5)
        printf("five ");
    else if (num == 6)
        printf("six ");
    else if (num == 7)
        printf("seven ");
    else if (num == 8)
        printf("eight ");
    else if (num == 9)
        printf("nine ");
    else if (num == 10)
        printf("ten ");
    else if (num == -1)
        printf("negative one ");
    else if (num == -2)
        printf("negative two ");
    else if (num == -3)
        printf("negative three ");
    else if (num == -4)
        printf("negative four ");
    else if (num == -5)
        printf("negative five ");
    else if (num == -6)
        printf("negative six ");
    else if (num == -7)
        printf("negative seven ");
    else if (num == -8)
        printf("negative eight ");
    else if (num == -9)
        printf("negative nine ");
    else if (num == -10)
        printf("negative ten ");
    else
        printf("%d ", num);
}

int main(void)
{
    int num_1, num_2, sum;
    printf("Please enter two integers: ");
    scanf("%d %d", &num_1, &num_2);
    sum = num_1 + num_2;
    change(num_1);
    printf("+ ");
    change(num_2);
    printf("= ");
    change(sum);
    printf("\n");
    return 0;
}
