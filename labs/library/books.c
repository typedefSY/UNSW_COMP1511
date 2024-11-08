//
// Author: Steve Yang (z5374603)
// Date: Nov 10th.
//
// Description:
// books
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "books.h"

struct book
{
    char title[MAX_STR_LENGTH];
    char author[MAX_STR_LENGTH];
    int num_page;
    struct book *next;
};

struct book *insert_book(struct book *head, char *title, char *author, int num_pages)
{
    struct book *new = (struct book*)malloc(sizeof(struct book));
    strcpy(new->title, title);
    strcpy(new->author, author);
    new->num_page = num_pages;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
        return head;
    }
    struct book *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = NULL;
        
    return head;
}

void print_books(struct book *head)
{
    if (head == NULL)
        return;
    struct book *temp = head;
    while (temp != NULL)
    {
        printf("%s by %s (%dpages)\n",
                temp->title, temp->author, temp->num_page);
        temp = temp->next;
    }

    return;
}
