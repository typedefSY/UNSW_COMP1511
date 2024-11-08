//z5374603 Steve Yang
#include <stdio.h>

int is_vowel(int character);

int main(void)
{
    int ch = getchar();
    while (ch != EOF)
    {
        if (is_vowel(ch) == 1)
            ch = ' ';       
        else
            putchar(ch);
        ch = getchar();
    }
    
    return 0;
}

int is_vowel(int character)
{
    if (character == 'a' || character == 'e'
        || character == 'i' || character == 'o' || character == 'u')
        return 1;
    else
        return 0;
}
