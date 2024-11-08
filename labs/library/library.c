//z5374603 Steve Yang
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"

///////////////////////////////////////////////////////////////////////////////
///////////            DO NOT EDIT THIS FUNCTION            ///////////////////
///////////////////////////////////////////////////////////////////////////////
struct library *create_library(void)
{
    struct library *new = malloc(sizeof(struct library));

    new->genres = NULL;
    return new;
}

///////////////////////////////////////////////////////////////////////////////
///////////            DO NOT EDIT THIS FUNCTION            ///////////////////
///////////////////////////////////////////////////////////////////////////////
void add_genre(struct library *lib, char *genre) {
    struct genre *new = malloc(sizeof(struct genre));
    strcpy(new->name, genre);
    new->books = NULL;
    new->next = NULL;

    new->next = lib->genres;
    lib->genres = new;
}


///////////////////////////////////////////////////////////////////////////////
///////////         EDIT ALL FUNCTIONS BELOW HERE           ///////////////////
///////////////////////////////////////////////////////////////////////////////

int add_book_to_genre(
    struct library *lib,
    char *genre,
    char *title,
    char *author,
    int n_pages
)
{
    if (lib->genres == NULL)
        return NOT_FOUND;
    struct genre *temp_1 = lib->genres;
    while (temp_1 != NULL)
    {
        if (strcmp(temp_1->name, genre) == 0)
        {
            temp_1->books = insert_book(temp_1->books, title, author, n_pages);
            break;
        }
        temp_1 = temp_1->next;
        if (temp_1 == NULL)
            return NOT_FOUND;
    }
    
    return SUCCESS;
}

void print_books_in_genre(struct library *lib, char *genre)
{
    if (lib->genres == NULL)
        printf("No books\n");
    struct genre *temp = lib->genres;
    while (temp != NULL)
    {
        if (strcmp(temp->name, genre) == 0)
        {
            print_books(temp->books);
            break;
        }
        temp = temp->next;
        if (temp == NULL)
            printf("No books\n");
    }
}
