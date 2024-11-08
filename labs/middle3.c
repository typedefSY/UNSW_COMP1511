// Program to scan in three integers and print out the middle one.
//z5374603 Steve Yang
#include <stdio.h>

struct numbers {
    int first;
    int second;
    int third;
};

int main(void) {
    // DO NOT CHANGE CODE BELOW HERE
    struct numbers nums;
    printf("Enter integer: ");
    scanf("%d", &nums.first);

    printf("Enter integer: ");
    scanf("%d", &nums.second);

    printf("Enter integer: ");
    scanf("%d", &nums.third);
    
    if (nums.first >= nums.second && nums.first <= nums.third)
        printf("Middle: %d\n", nums.first);
    else if (nums.first >= nums.third && nums.first <= nums.second)
        printf("Middle: %d\n", nums.first);
    else if (nums.second >= nums.first && nums.second <= nums.third)
        printf("Middle: %d\n", nums.second);
    else if (nums.second >=nums.third && nums.second <= nums.first)
        printf("Middle: %d\n", nums.second);
    else
        printf("Middle: %d\n", nums.third);

    return 0;
}
