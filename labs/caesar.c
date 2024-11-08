// z5374603 Steve Yang
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cipher(int character, int shift);

int main(int argc, const char * argv[])
{
    int shift = atoi(argv[1]);
    int ch = getchar();
    int ceasar_ch;
    while (ch != EOF)
    {
        while (ch != '\n')
        {
            ceasar_ch = cipher(ch, shift);
            printf("%c", ceasar_ch);
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
int cipher(int character, int shift)
{
    int ceasar_character;
    if (character >= 'A' && character <= 'Z')
    {
        ceasar_character = character + shift % 26;
        if (ceasar_character > 'Z')
            ceasar_character = ceasar_character - 'Z' + 'A' - 1;
        else if (ceasar_character < 'A')
            ceasar_character = ceasar_character + 'Z' - 'A' + 1;
        return ceasar_character;
    }
    else if (character >= 'a' && character <= 'z')
    {
        ceasar_character = character + shift % 26;
        if (ceasar_character > 'z')
            ceasar_character = ceasar_character - 'z' + 'a' - 1;
        else if (ceasar_character < 'a')
            ceasar_character = ceasar_character + 'z' - 'a' + 1;
        return ceasar_character;
    }
    else
        return character;
}
