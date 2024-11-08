// z5374603 Steve Yang
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print(int ch_1, int ch_2);
int main(void)
{
    int ch_1 = 0;
    int ch_2 = 0;
    
    while (1)
    {
        ch_1 = getchar();
        if (ch_1 == EOF)
            break;
        ch_2 = getchar();
        if (ch_2 == EOF)
            break;
        print(ch_1, ch_2);
    }
    printf("\n");
    
    return 0;
}

void print(int ch_1, int ch_2)
{
    if (ch_1 <= ch_2)
        putchar(ch_1);
    else
        putchar(ch_2);
}