// COMP1511 Week 7 Test: Interject
//
// This program was written by Steve Yang (z5374603)
// on 29th. October
//
// This program adds interjections to strings.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1002

void interject(char *str, char *interject, int index);
int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    return 0;
}

void interject(char *str, char *interject, int index)
{
    int length_interject = (int)strlen(interject);
    int length_str = (int)strlen(str);
    int num = 0;
    int end;
    end = length_str + length_interject;
    str[end] = '\0';
    for (int i = length_str - 1; i >= index; i--)
    {
        str[i + length_interject] = str[i];
    }
    for (int j = index; j < length_interject + index; j++)
    {
        str[j] = interject[num++];
    }
}