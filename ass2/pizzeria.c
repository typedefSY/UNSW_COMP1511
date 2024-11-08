//
// Assignment 2 21T3 COMP1511: CS Pizzeria
// pizzeria.c
//
// This program was written by Steve Yang (z5374603)
// on 3th. November
//
// Comp1511 Ass2
//This is a cse game about online pizzeria, 
//where you can order pizza and add ingredients. 
//This program is really helpful to control whole
//pizzeria. You can input 'h' for help.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: add any extra #includes your code needs here.

#include "pizzeria.h"
#include "save_string.h"

// TODO: add your own #defines here.
#define STR_LENGTH 200
#define TRUE 1
#define FALSE 0

struct ingredient
{
    char name[MAX_STR_LENGTH];
    int amount;
    double price;
    struct ingredient *next;
    struct ingredient *prev;
};

struct order
{
    char customer[MAX_STR_LENGTH];
    char pizza[MAX_STR_LENGTH];
    int time;
    double price;
    struct order *next;
    struct order *prev;
    struct ingredient *ingredients;
};

struct pizzeria
{
    struct ingredient *stock;
    struct order *selected;
    struct order *orders;
};

// TODO: add any other structs you define here.

//////////////////////////////////////////////////////////////////////

// TODO: add prototypes for any helper functions you create here.

// Prints a single order
void print_order
 (
    int num,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed
);

// Prints an ingredient given the name, amount and price in the required format.
// This will be needed for stage 2.
void print_ingredient(char *name, int amount, double price);
//print out all ingredients
int compare(struct ingredient *order, struct ingredient *stock);
//compare two ingredients
void clear_order(struct pizzeria *pizzeroa);
//free all orders
////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////


struct pizzeria *create_pizzeria(void)
{
    // Allocates memory to store a `struct pizzeria` and returns a pointer to
    // it. The variable `new` holds this pointer!
    struct pizzeria *new = malloc(sizeof(struct pizzeria));
    new->stock = NULL;
    new->selected = NULL;
    new->orders = NULL;

    // TODO: this function has already been implemented for the current
    // struct pizzeria. When you decide to change struct pizzeria, change
    // this function as well.

    return new;
}

int add_order
 (
    struct pizzeria *pizzeria,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed
)
{
    if (price < 0)
        return INVALID_PRICE;
    if (time_allowed <= 0)
        return INVALID_TIME;
    
    struct order *new_order = (struct order *) malloc (sizeof(struct order));
    //store a new order struct in heap
    strcpy(new_order->customer, customer);
    //copy customer to struct
    strcpy(new_order->pizza, pizza_name);
    //copy pizza name to struct
    new_order->price = price;
    new_order->time = time_allowed;
    new_order->next = NULL;
    new_order->prev = NULL;
    new_order->ingredients = NULL;
    struct order *add = pizzeria->orders;
    if (pizzeria->orders == NULL)
        //if it is a empty link list
    {
        pizzeria->orders = new_order;
        new_order->prev = NULL;
        return SUCCESS;
    }
    while (add->next != NULL)
        add = add->next;
    //go to the last node of link list
    add->next = new_order;
    //insert the new node
    new_order->prev = add;
    new_order->next = NULL;

    return SUCCESS;
}

void print_all_orders(struct pizzeria *pizzeria)
{
    struct order *temp = pizzeria->orders;
    int num = 1;
    //num th. order
    while (temp != NULL)
    {
        print_order(num, temp->customer, temp->pizza, temp->price, temp->time);
        num++;
        temp = temp->next;
    }
    
    print_selected_order(pizzeria);
    return;
}

int next_deadline(struct pizzeria *pizzeria)
{
    if (pizzeria->orders == NULL)
        return INVALID_CALL;
    int ddl = 0;
    //the deadline
    struct order *temp = pizzeria->orders;
    while (temp != NULL)
    {
        if (ddl == 0)
            ddl = temp->time;
        else if (ddl > temp->time)
            ddl = temp->time;
        temp = temp->next;
    }

    return ddl;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////


void select_next_order(struct pizzeria *pizzeria)
{
    if (pizzeria->selected == NULL)
        pizzeria->selected = pizzeria->orders;
    else
        pizzeria->selected = pizzeria->selected->next;

    return;
}

void select_previous_order(struct pizzeria *pizzeria)
{
    struct order *last = pizzeria->orders;
    while (last->next != NULL)
        last = last->next;
    //ptr last is the tail pointer of orders
    if (pizzeria->selected == NULL)
        pizzeria->selected = last;
    else
        pizzeria->selected = pizzeria->selected->prev;
        
    return;
}

void print_selected_order(struct pizzeria *pizzeria)
{
    if (pizzeria->selected == NULL)
        printf("\nNo selected order.\n");
    else
    {
        printf("\nThe selected order is %s's %s pizza ($%.2lf) due in %d minutes.\n",
               pizzeria->selected->customer, pizzeria->selected->pizza,
               pizzeria->selected->price, pizzeria->selected->time);
        if (pizzeria->selected->ingredients != NULL)
        {
            struct ingredient *temp = pizzeria->selected->ingredients;
            while (temp != NULL)
            {
                print_ingredient(temp->name, temp->amount, temp->price);
                temp = temp->next;
            }
        }
    }
}

int add_ingredient
 (
    struct pizzeria *pizzeria,
    char *ingredient_name,
    int amount,
    double price
)
{
    //Invalid !
    if (pizzeria->selected == NULL)
        return INVALID_ORDER;
    else if (price <= 0)
        return INVALID_PRICE;
    else if (amount < 0)
        return INVALID_AMOUNT;
    
    struct ingredient *ingredients =
           (struct ingredient *) malloc (sizeof(struct ingredient));
    strcpy(ingredients->name, ingredient_name);
    ingredients->price = price;
    ingredients->amount = amount;
    ingredients->next = NULL;
    ingredients->prev = NULL;
    struct ingredient *temp_1 = pizzeria->selected->ingredients;
    if (pizzeria->selected->ingredients == NULL)
    {
        pizzeria->selected->ingredients = ingredients;
    }
    else
    {
        while (temp_1 != NULL)
        {
            if (strcmp(ingredient_name, temp_1->name) == 0)
            {
                temp_1->amount += ingredients->amount;
                free(ingredients);
                break;
            }
            else if (pizzeria->selected->ingredients == temp_1 &&
                     strcmp(temp_1->name,ingredient_name) > 0)
            {
                pizzeria->selected->ingredients = ingredients;
                ingredients->next = temp_1;
                ingredients->prev = pizzeria->selected->ingredients;
                break;
            }
            else if (temp_1->next == NULL)
            {
                temp_1->next = ingredients;
                ingredients->prev = temp_1;
                break;
            }
            
            else if (strcmp(temp_1->name,ingredient_name) < 0 &&
                     strcmp(temp_1->next->name, ingredient_name) > 0)
            {
                ingredients->next = temp_1->next;
                temp_1->next = ingredients;
                ingredients->prev = temp_1;
                break;
            }
            temp_1 = temp_1->next;
        }
    }
    return SUCCESS;
}

double calculate_total_profit(struct pizzeria *pizzeria)
{
    double profit;
    if (pizzeria->selected == NULL)
        return INVALID_ORDER;
    struct ingredient *temp = pizzeria->selected->ingredients;
    profit = pizzeria->selected->price;
    while (temp != NULL)
    {
        profit = profit - temp->amount * temp->price;
        temp = temp->next;
    }

    return profit;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////


int cancel_order(struct pizzeria *pizzeria)
{
    if (pizzeria->selected == NULL)
        return INVALID_ORDER;
    struct order *temp = pizzeria->selected;
    pizzeria->selected = temp->next;
    if (temp == pizzeria->orders && pizzeria->orders->next != NULL)
        //if selected one is the first one in long link list
    {
        pizzeria->orders = temp->next;
        temp->next->prev = NULL;
    }
    else if (temp->next == NULL && temp == pizzeria->orders)
        //if selected one is the first one in the link list,which only has one element
    {
        pizzeria->orders = NULL;
    }
    else if (temp->next == NULL)
        //if selected one is the last one in link list
    {
        temp->prev->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    struct ingredient *temp_1 = temp->ingredients;
    while (temp_1 != NULL)
    {
        struct ingredient *temp_2;
        temp_2 = temp_1->next;
        free(temp_1);
        temp_1 = temp_2;
    }
    free(temp);

    return SUCCESS;
}

void free_pizzeria(struct pizzeria *pizzeria)
{
    struct order *temp_1 = pizzeria->orders;
    while (temp_1 != NULL)
    {
        struct ingredient *temp_3 = temp_1->ingredients;
        pizzeria->orders = temp_1->next;
        while (temp_3 != NULL)
        {
            temp_1->ingredients = temp_3->next;
            free(temp_3);
            temp_3 = temp_1->ingredients;
        }
        free(temp_1);
        temp_1 = pizzeria->orders;
    }
    struct ingredient *temp_2 = pizzeria->stock;
    while (temp_2 != NULL)
    {
        pizzeria->stock = temp_2->next;
        free(temp_2);
        temp_2 = pizzeria->stock;
    }

    free(pizzeria);

    return;
}

int refill_stock
(
    struct pizzeria *pizzeria,
    char *ingredient_name,
    int amount,
    double price
)
{
    if (price < 0)
        return INVALID_PRICE;
    else if (amount <= 0)
        return INVALID_AMOUNT;
    
    struct ingredient *ingredients =
           (struct ingredient *) malloc (sizeof(struct ingredient));
    strcpy(ingredients->name, ingredient_name);
    ingredients->price = price;
    ingredients->amount = amount;
    ingredients->next = NULL;
    ingredients->prev = NULL;
    struct ingredient *temp_1 = pizzeria->stock;
    if (pizzeria->stock == NULL)
        //add first ingredient
    {
        pizzeria->stock = ingredients;
        ingredients->prev = NULL;
    }
    else
    {
        while (temp_1 != NULL)
        {
            if (strcmp(ingredient_name, temp_1->name) == 0)
            {
                temp_1->amount += ingredients->amount;
                free(ingredients);
                break;
            }
            else if (pizzeria->stock == temp_1 &&
                     strcmp(temp_1->name,ingredient_name) > 0)
                //add at head
            {
                pizzeria->stock = ingredients;
                ingredients->next = temp_1;
                temp_1->prev = ingredients;
                ingredients->prev = NULL;
                break;
            }
            else if (temp_1->next == NULL)
                //add at tail
            {
                temp_1->next = ingredients;
                ingredients->prev = temp_1;
                break;
            }
            else if (strcmp(temp_1->name,ingredient_name) < 0 &&
                     strcmp(temp_1->next->name, ingredient_name) > 0)
                //add in middle
            {
                ingredients->next = temp_1->next;
                temp_1->next->prev = ingredients;
                temp_1->next = ingredients;
                ingredients->prev = temp_1;
                break;
            }
            temp_1 = temp_1->next;
        }
    }

    return SUCCESS;
}

void print_stock(struct pizzeria *pizzeria)
{
    printf("The stock contains:\n");
    struct ingredient *temp = pizzeria->stock;
    while (temp != NULL)
    {
        print_ingredient(temp->name, temp->amount, temp->price);
        temp = temp->next;
    }
    
    return;
}

int can_complete_order(struct pizzeria *pizzeria)
{
    if (pizzeria->selected == NULL || pizzeria->selected->ingredients == NULL)
        return INVALID_ORDER;
    struct ingredient *order_ingredients = pizzeria->selected->ingredients;
    struct ingredient *stock_ingredients = pizzeria->stock;
    int order_num = 0;
    int equal_num = 0;
    while (order_ingredients != NULL)
    {
        order_num++;
        order_ingredients = order_ingredients->next;
    }
    order_ingredients = pizzeria->selected->ingredients;
    while (order_ingredients != NULL)
    {
        stock_ingredients = pizzeria->stock;
        while (stock_ingredients != NULL)
        {
            if (compare(order_ingredients, stock_ingredients) == TRUE)
                equal_num++;
            stock_ingredients = stock_ingredients->next;
        }
        order_ingredients = order_ingredients->next;
    }
    if (equal_num == order_num)
        return SUCCESS;
    else
        return INSUFFICIENT_STOCK;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

int complete_order(struct pizzeria *pizzeria)
{
    if (pizzeria->selected == NULL || pizzeria->selected->ingredients == NULL)
        return INVALID_ORDER;
    if (can_complete_order(pizzeria) != SUCCESS)
        return INSUFFICIENT_STOCK;
    struct ingredient *order_ingredients = pizzeria->selected->ingredients;
    struct ingredient *stock_ingredients = pizzeria->stock;
    struct ingredient *temp;
    while (order_ingredients != NULL)
    {
        stock_ingredients = pizzeria->stock;
        while (stock_ingredients != NULL)
        {
            if (strcmp(stock_ingredients->name, order_ingredients->name) == 0)
                stock_ingredients->amount -= order_ingredients->amount;
            stock_ingredients = stock_ingredients->next;
        }
        order_ingredients = order_ingredients->next;
    }
    stock_ingredients = pizzeria->stock;
    while (stock_ingredients != NULL)
    {
        if (stock_ingredients->amount == 0)
        {
            if (stock_ingredients == pizzeria->stock &&
                stock_ingredients->next == NULL)
            {
                pizzeria->stock = NULL;
                free(stock_ingredients);
            }
            else if (stock_ingredients->next == NULL)
            {
                stock_ingredients->prev->next = NULL;
                free(stock_ingredients);
            }
            else
            {
                stock_ingredients->prev->next = stock_ingredients->next;
                stock_ingredients->next->prev = stock_ingredients->prev;
                temp = stock_ingredients;
                stock_ingredients = stock_ingredients->next;
                free(temp);
            }
        }
        else
            stock_ingredients = stock_ingredients->next;
    }
    clear_order(pizzeria);
    
    return SUCCESS;
}

int save_ingredients(struct pizzeria *pizzeria, char *file_name)
{
    if (pizzeria->selected == NULL)
        return INVALID_ORDER;
    struct ingredient *current = pizzeria->selected->ingredients;
    char string[MAX_SAVE_LENGTH] = {0};
    char string_temp[STR_LENGTH];
    while (current != NULL)
    {
        sprintf (string_temp, "%d %lf %s ",
                 current->amount, current->price, current->name);
        strcat (string, string_temp);
        current = current->next;
    }
    save_string(file_name, string);
    return SUCCESS;
}

int load_ingredients(struct pizzeria *pizzeria, char *file_name)
{
    if (pizzeria->selected == NULL)
        return INVALID_ORDER;
    int amount;
    double price;
    char name[MAX_STR_LENGTH];
    char string[MAX_SAVE_LENGTH];
    int round = 0;
    int read_char_count = 0;
    char *string_temp = load_string(file_name);
    //this pointer points to heap (have to free)
    strcpy (string, string_temp);
    while (sscanf (string + round, "%d %lf %s %n",
                   &amount, &price, name, &read_char_count) == 3)
    {
        add_ingredient(pizzeria, name, amount, price);
        round += read_char_count;
    }
    free(string_temp);
    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

// Prints a single order
//
// `print_order` will be given the parameters:
// - `num` -- the integer that represents which order it is sequentially.
// - `customer` -- the name of the customer for that order.
// - `pizza_name` -- the pizza the customer ordered.
// - `price` -- the price the customer is paying for the pizza.
// - `time_allowed` -- the time the customer will wait for the order.
//
// `print_order` assumes all parameters are valid.
//
// `print_order` returns nothing.
//
// This will be needed for Stage 1.
void print_order(
    int num,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed
) {

    printf("%02d: %s ordered a %s pizza ($%.2lf) due in %d minutes.\n",
        num, customer, pizza_name, price, time_allowed);

    return;
}

// Prints a single ingredient
//
// `print_ingredient` will be given the parameters:
// - `name` -- the string which contains the ingredient's name.
// - `amount` -- how many of the ingredient we either need or have.
// - `price` -- the price the ingredient costs.
//
// `print_ingredient` assumes all parameters are valid.
//
// `print_ingredient` returns nothing.
//
// This will be needed for Stage 2.
void print_ingredient(char *name, int amount, double price) {
    printf("    %s: %d @ $%.2lf\n", name, amount, price);
}

//this function will return 0 if two ingredients are not the same
//or order amount is more than stock has. And return TRUE iff
//these two ingredients are the same and order amount is less than stock has.
int compare(struct ingredient *order, struct ingredient *stock)
{
    if (strcmp(order->name, stock->name) == 0)
    {
        if (order->amount <= stock->amount)
            return TRUE;
        else
            return FALSE;
    }
    else
        return FALSE;
}

//This function will return nothing but free all orders
void clear_order(struct pizzeria *pizzeria)
{
    struct order *temp = pizzeria->selected;
    pizzeria->selected = temp->next;
    if (temp == pizzeria->orders && pizzeria->orders->next != NULL)
        //if selected one is the first one in long link list
    {
        pizzeria->orders = temp->next;
        temp->next->prev = NULL;
    }
    else if (temp->next == NULL && temp == pizzeria->orders)
    //if selected one is the first one in the link list,which only has one element
    {
        pizzeria->orders = NULL;
    }  
    else if (temp->next == NULL)
    //if selected one is the last one in link list
    {
        temp->prev->next = NULL;
    }
        
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    struct ingredient *temp_1 = temp->ingredients;
    while (temp_1 != NULL)
    {
        struct ingredient *temp_2;
        temp_2 = temp_1->next;
        free(temp_1);
        temp_1 = temp_2;
    }
    free(temp);
}
