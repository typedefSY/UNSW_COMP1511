//Steve Yang z5374603
#include <stdio.h>

#define MAX_ROOMS 50

struct hotel_room
{
    int room_num;
    int ppl_num;
    double price;
};

// Prints the room in the correct format when given the room_number, capacity
// and price of it.
void print_room(int room_number, int capacity, double price);

int main(void)
{
    int num;
    int ppl;
    
    printf("How many rooms? ");
    scanf("%d", &num);
    struct hotel_room hotel[num];
    
    printf("Enter hotel rooms:\n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d %lf", &hotel[i].room_num, &hotel[i].ppl_num, &hotel[i].price);
    }

    printf("How many people? ");
    scanf("%d", &ppl);
    
    printf("Rooms that fit your group:\n");
    for (int j = 0; j < num; j++)
    {
        if (hotel[j].ppl_num == ppl || hotel[j].ppl_num > ppl)
        {
            print_room(hotel[j].room_num, hotel[j].ppl_num, hotel[j].price);
        }
    }

    return 0;
}

// Prints the room in the correct format when given the room_number, capacity
// and price of it.
//
// Takes in:
// - `room_number` -- The hotel room's room number.
// - `capacity` -- How many people the hotel room can fit.
// - `price` -- How much the hotel room costs.
//
// Returns: nothing.
void print_room(int room_number, int capacity, double price)
{
    printf("Room %d (%d people) @ $%.2lf\n", room_number, capacity, price);
    return;
}
