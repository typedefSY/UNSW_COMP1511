//Steve Yang z5374603
#include <stdio.h>

int addition(int s, int t)
{
    int sum;
    sum = s + t;
    return sum;
}

int main(void)
{
    int stu, tut;
    
    printf("Please enter the number of students and tutors: ");
    scanf("%d %d", &stu, &tut);
    printf("%d + %d = %d\n", stu, tut, addition(stu, tut));
    
    return 0;
}
