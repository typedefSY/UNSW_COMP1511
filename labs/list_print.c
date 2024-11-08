// z5374603 Steve Yang
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    struct node *next;
    int          data;
};

void print(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    print(head);

    return 0;
}


// print a linked list in this format:
// 17 -> 34 -> 51 -> 68 -> X
void print(struct node *head)
{
    if (head == NULL)
    {
        printf("X\n");
        return;
    }
        
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("X\n");
}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[])
{
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1)
    {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
