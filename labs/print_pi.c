//Steve Yang z5374603
// Prints the first n digits of pi, where n is specified
// by the user

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n;
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &n);
    if (n == 1)
        printf("3\n");
    else
    {
        printf("3.");
        for (int i = 1; i < n; i++)
        {
            printf("%d", pi[i]);
        }
        printf("\n");
    }
    return 0;
}
