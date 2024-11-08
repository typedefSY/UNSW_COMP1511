// z5374603 Steve Yang
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cipher(char character[27], int ch);

int main(int argc, const char * argv[])
{
    char index[27];
    strcpy(index, argv[1]);
    int cipher_ch = 0;
    int ch = getchar();
    while (ch != EOF)
    {
        while (ch != '\n')
        {
            cipher_ch = cipher(index, ch);
            printf("%c", cipher_ch);
            ch = getchar();
            if (ch == '\n')
                printf("\n");
            if (ch == EOF)
                break;
        }
        ch = getchar();
    }

    return 0;
}

int cipher(char character[27], int ch)
{
    int cipher_ch = 0;
    int i = 0;
    int lower_ch = 0;
    if (ch >= 'a' && ch <= 'z')
    {
        while (ch != character[i])
            i++;
        cipher_ch = 'a' + i;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        lower_ch = ch + 32;
        while (lower_ch != character[i])
            i++;
        cipher_ch = 'a' + i - 32;
    }
    else
        cipher_ch = ch;
    
    return cipher_ch;
}