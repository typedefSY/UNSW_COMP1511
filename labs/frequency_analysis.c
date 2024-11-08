// z5374603 Steve Yang
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

int main(void)
{
    char sentense[MAX_LENGTH] = {0};
    int ch = 0;
    int i = 0;
    float num = 0;
    float frequency = 0;
    ch = getchar();
    while (ch != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
            sentense[i++] = ch;
        else if (ch >= 'A' && ch <= 'Z')
            sentense[i++] = ch + 32;
        ch = getchar();
    }
        
    for (int j = 'a'; j <= 'z'; j++)
    {
        num = 0;
        for (int index = 0; index < i; index++)
        {
            if (sentense[index] == j)
                num++;
        }
        frequency = num / i;
        printf("'%c' %.6f %.0f\n", j, frequency, num);
    }

    return 0;
}
