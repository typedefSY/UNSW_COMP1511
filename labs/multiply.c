//Steve Yang z5374603
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main(void)
{
    int num_1;
    int num_2;
    int ans;

    scanf("%d", &num_1);
    scanf("%d", &num_2);
    ans = abs(num_1) * abs(num_2);
    if(ans == 0)
        printf("zero\n");
    else
        printf("%d\n", ans);

    return 0;
}