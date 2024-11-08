//Steve Yang z5374603
// CSE Valley
// cse_valley.c
//
// This program was written by Steve Yang (z5374603)
// on October 6th.
//
// Version 1.0.0 (2021-10-04): Assignment Released.
//
// Farming game(1511 ass_1)

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 50
#define MAX_NUM_SEED_TYPES 26
#define LAND_SIZE 8
#define NO_SEED ' '
#define TRUE 1
#define FALSE 0

struct land {
    int is_watered;
    char seed_name;
    int die;
};

struct seeds {
    char name;
    int amount;
};

struct farmer {
    int curr_col;
    int curr_row;
    char curr_dir;
};


void print_land(struct land farm_land[LAND_SIZE][LAND_SIZE], struct farmer cse_farmer);
struct farmer initialise_farmer(struct farmer cse_farmer);
void initialise_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES]);
void initialise_land(struct land farm_land[LAND_SIZE][LAND_SIZE]);
void print_top_row(struct land farm_land[LAND_SIZE][LAND_SIZE], int row);
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE], struct farmer cse_farmer);
void plant_1(struct land farm_land[LAND_SIZE][LAND_SIZE],
             struct farmer cse_farmer,
             struct seeds seed_collection[MAX_NUM_SEED_TYPES],
             int k,
             char name);
void plant_all(struct land farm_land[LAND_SIZE][LAND_SIZE],
               struct farmer cse_farmer,
               struct seeds seed_collection[MAX_NUM_SEED_TYPES],
               int k,
               char name);
void square_water(struct land farm_land[LAND_SIZE][LAND_SIZE],
                  struct farmer cse_farmer,
                  int square_num);
void harvest(struct land farm_land[LAND_SIZE][LAND_SIZE],
             struct farmer cse_farmer,
             struct seeds seed_collection[MAX_NUM_SEED_TYPES]);
void next_day(struct land farm_land[LAND_SIZE][LAND_SIZE]);
void print_single_seed (int num_1, char name, struct seeds seed_collection[MAX_NUM_SEED_TYPES]);
void droughts(struct land farm_land[LAND_SIZE][LAND_SIZE]);
void wind_storms(struct land farm_land[LAND_SIZE][LAND_SIZE]);
void droughts_print(struct land farm_land[LAND_SIZE][LAND_SIZE], int k, int j, int num_1, int num_2);
void wind_print(struct land farm_land[LAND_SIZE][LAND_SIZE], int k, int j, int num_1, int num_2);
struct farmer move_right(struct farmer cse_farmer);
struct farmer move_down(struct farmer cse_farmer);
struct farmer move_left(struct farmer cse_farmer);
struct farmer move_up(struct farmer cse_farmer);
int find_seed(struct seeds seed_collection[MAX_NUM_SEED_TYPES], char name);
int h_seed(char name, struct seeds seed_collection[MAX_NUM_SEED_TYPES]);
int trade(struct seeds seed_collection[MAX_NUM_SEED_TYPES], char trade_2, int trade_num, int k, int num_1);
int valid_letter(char trade);
int plants_around(struct land farm_land[LAND_SIZE][LAND_SIZE], int k, int j);

int main(void) {

    struct farmer cse_farmer = {};
    cse_farmer = initialise_farmer(cse_farmer);

    struct land farm_land[LAND_SIZE][LAND_SIZE];
    initialise_land(farm_land);

    struct seeds seed_collection[MAX_NUM_SEED_TYPES];
    initialise_seeds(seed_collection);
    
    int num_1;
    //The number of different kinds of seeds
    int num_seeds = 0;
    int day = 1;
    int square_num;
    int trade_num;
    char trade_1;
    char trade_2;
    char command;
    char name;
    //seed's name
    char operation;
    char disaster;

    printf("Welcome to CSE Valley, farmer!\n");
    printf("Congratulations, you have received 60 seeds.\n");
    printf("How many different seeds do you wish to have? ");
    scanf("%d", &num_1);
    printf("Enter the names of the seeds to be given:\n");
    for (int i = 0; i < num_1; i++)
    {
        scanf(" %c", &seed_collection[i].name);
        seed_collection[i].amount = 60 / num_1;
    }
    printf("Game Started!\n");

    printf("Enter command: ");
    while (scanf(" %c", &command) != EOF)
    {
        if (command == 'a')
        {
            printf("  Seeds at your disposal:\n");
            for (int i = 0; i < num_1; i++)
            {
                printf("  - %d seed(s) with the name '%c'\n",
                        seed_collection[i].amount, seed_collection[i].name);
            }
        }
        else if (command == 's')
        {
            scanf(" %c", &name);
            print_single_seed(num_1, name, seed_collection);
        }
        else if (command == 'l')
            print_land(farm_land, cse_farmer);
        else if (command == '>')
            cse_farmer = move_right(cse_farmer);
        else if (command == 'v')
            cse_farmer = move_down(cse_farmer);
        else if (command == '<')
            cse_farmer = move_left(cse_farmer);
        else if (command == '^')
            cse_farmer = move_up(cse_farmer);
        else if (command == 'o')
        {
            scanf(" %c", &operation);
            if (operation == 'w')
            {
                //check the direction if farm and water
                if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col != LAND_SIZE - 1)
                    farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1].is_watered
                    = TRUE;
                else if (cse_farmer.curr_dir == 'v' && cse_farmer.curr_row != LAND_SIZE - 1)
                    farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col].is_watered
                    = TRUE;
                else if (cse_farmer.curr_dir == '<' && cse_farmer.curr_col != 0)
                    farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1].is_watered
                    = TRUE;
                else if (cse_farmer.curr_dir == '^' && cse_farmer.curr_row != 0)
                    farm_land[cse_farmer.curr_row - 1][cse_farmer.curr_col].is_watered
                    = TRUE;
            }
            else if (operation == 'p')
            {
                scanf(" %c", &name);
                num_seeds = find_seed(seed_collection, name);
                if (num_seeds == MAX_NUM_SEED_TYPES)
                    printf("  There is no seed with the name '%c'\n", name);
                else if(name < 'a' || name >'z')
                    printf("  Seed name has to be a lowercase letter\n");
                else
                    plant_1(farm_land, cse_farmer, seed_collection, num_seeds, name);
            }
            num_seeds = 0;
        }
        else if (command == 'p')
        {
            scanf(" %c", &name);
            if (name < 'a' || name > 'z')
                printf("  Seed name has to be a lowercase letter\n");
            else
                plant_all(farm_land, cse_farmer, seed_collection, num_seeds, name);
        }
        else if (command == 'w')
        {
            scanf(" %d", &square_num);
            if (square_num < 0)
                printf("  The size argument needs to be a non-negative integer\n");
            square_water(farm_land, cse_farmer, square_num);
        }
        else if (command == 'h')
            harvest(farm_land, cse_farmer, seed_collection);
        else if (command == 'n')
        {
            next_day(farm_land);
            day++;
            cse_farmer.curr_col = 0;
            cse_farmer.curr_row = 0;
            cse_farmer.curr_dir = '>';
            printf("  Advancing to the next day... Day %d, let's go!\n", day);
        }
        else if (command == 't')
        {
            num_seeds = 0;
            scanf(" %c", &trade_1);
            scanf(" %d", &trade_num);
            scanf(" %c", &trade_2);
            while (seed_collection[num_seeds].name != trade_1 && 
                   num_seeds < MAX_NUM_SEED_TYPES - 1)
                num_seeds++;
            //check for validity
            if (valid_letter(trade_1) == FALSE || valid_letter(trade_2) == FALSE)
                printf("  Seed name has to be a lowercase letter\n");
            else if (trade_num < 0)
                printf("  You can't trade negative seeds\n");
            else if (num_seeds == MAX_NUM_SEED_TYPES - 1)
                printf("  You don't have the seeds to be traded\n");
            else if (trade_num > seed_collection[num_seeds].amount)
                printf("  You don't have enough seeds to be traded\n");
            //if every commands are valid
            else
                num_1 = trade(seed_collection, trade_2, trade_num, num_seeds, num_1);
        }
        else if (command == 'd')
        {
            scanf(" %c", &disaster);
            if (disaster == 'd')
                droughts(farm_land);
            else if (disaster == 'w')
                wind_storms(farm_land);
        }
        
        printf("Enter command: ");
    }
    
    return 0;
}


void print_single_seed (int num_1, char name,
                        struct seeds seed_collection[MAX_NUM_SEED_TYPES])
{
    for (int num_seeds = 0; num_seeds < num_1; num_seeds++)
    {
        if (name < 'a' || name > 'z')
        {
            printf("  Seed name has to be a lowercase letter\n");
            break;
        }
        if (name == seed_collection[num_seeds].name)
        {
            printf("  There are %d seeds with the name '%c'\n",
                    seed_collection[num_seeds].amount, seed_collection[num_seeds].name);
            break;
        }
        else if(num_seeds == num_1 - 1 && name != seed_collection[num_seeds].name)
            printf("  There is no seed with the name '%c'\n", name);
    }
}


struct farmer move_right(struct farmer cse_farmer)
{
    if (cse_farmer.curr_dir != '>')
        cse_farmer.curr_dir = '>';
    else if (cse_farmer.curr_col == LAND_SIZE - 1)
        cse_farmer.curr_col = LAND_SIZE - 1;
    else
        cse_farmer.curr_col++;
    return cse_farmer;
}

struct farmer move_down(struct farmer cse_farmer)
{
    if (cse_farmer.curr_dir != 'v')
        cse_farmer.curr_dir = 'v';
    else if (cse_farmer.curr_row == LAND_SIZE - 1)
        cse_farmer.curr_row = LAND_SIZE - 1;
    else
        cse_farmer.curr_row++;
    return cse_farmer;
}

struct farmer move_left (struct farmer cse_farmer)
{
    if (cse_farmer.curr_dir != '<')
        cse_farmer.curr_dir = '<';
    else if (cse_farmer.curr_col == 0)
        cse_farmer.curr_col = 0;
    else
        cse_farmer.curr_col--;
    return cse_farmer;
}

struct farmer move_up (struct farmer cse_farmer)
{
    if (cse_farmer.curr_dir != '^')
        cse_farmer.curr_dir = '^';
    else if (cse_farmer.curr_row == 0)
        cse_farmer.curr_row = 0;
    else
        cse_farmer.curr_row--;
    return cse_farmer;
}

int valid_letter (char trade)
{
    //check the input letter
    if (trade < 'a' || trade > 'z')
        return FALSE;
    else
        return TRUE;
}

int find_seed (struct seeds seed_collection[MAX_NUM_SEED_TYPES], char name)
{
    int num_seeds = 0;
    while (seed_collection[num_seeds].name != name && num_seeds < MAX_NUM_SEED_TYPES - 1)
        num_seeds++;
    return num_seeds;
}

int h_seed (char name, struct seeds seed_collection[MAX_NUM_SEED_TYPES])
{
    int num_seeds = 0;
    while (seed_collection[num_seeds].name != name &&
           seed_collection[num_seeds].name != name + 32 &&
           num_seeds < MAX_NUM_SEED_TYPES - 1)
        num_seeds++;
    return num_seeds;
}

void plant_1 (struct land farm_land[LAND_SIZE][LAND_SIZE],
              struct farmer cse_farmer,
              struct seeds seed_collection[MAX_NUM_SEED_TYPES],
              int num_seeds,
              char name)
{
    if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col != LAND_SIZE - 1)
    {
        if (seed_collection[num_seeds].amount > 0)
        {
            farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1].seed_name = name;
            seed_collection[num_seeds].amount--;
        }
    }
    else if (cse_farmer.curr_dir == 'v' && cse_farmer.curr_row != LAND_SIZE - 1)
    {
        if (seed_collection[num_seeds].amount > 0)
        {
            farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col].seed_name = name;
            seed_collection[num_seeds].amount--;
        }
    }
    else if (cse_farmer.curr_dir == '<' && cse_farmer.curr_col != 0)
    {
        if (seed_collection[num_seeds].amount > 0)
        {
            farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1].seed_name = name;
            seed_collection[num_seeds].amount--;
        }
    }
    else if (cse_farmer.curr_dir == '^' && cse_farmer.curr_row != 0)
    {
        if (seed_collection[num_seeds].amount > 0)
        {
            farm_land[cse_farmer.curr_row - 1][cse_farmer.curr_col].seed_name = name;
            seed_collection[num_seeds].amount--;
        }
    }
}

void plant_all (struct land farm_land[LAND_SIZE][LAND_SIZE],
                struct farmer cse_farmer,
                struct seeds seed_collection[MAX_NUM_SEED_TYPES],
                int num_seeds,
                char name)
{
    int col = 0;
    num_seeds = find_seed(seed_collection, name);
    if (num_seeds == MAX_NUM_SEED_TYPES - 1)
        printf("  There is no seed with the name '%c'\n", name);
    else
    {
        if (cse_farmer.curr_dir == '^' || cse_farmer.curr_dir == '<')
            printf("  You cannot scatter seeds ^ or <\n");
        else if (cse_farmer.curr_dir == '>')
        {
            col = cse_farmer.curr_col;
            while (col < LAND_SIZE && seed_collection[num_seeds].amount > 0)
            {
                farm_land[cse_farmer.curr_row][col].seed_name = name;
                seed_collection[num_seeds].amount--;
                col++;
            }
        }
        else if (cse_farmer.curr_dir == 'v')
        {
            col = cse_farmer.curr_row;
            while (col < LAND_SIZE && seed_collection[num_seeds].amount > 0)
            {
                farm_land[col][cse_farmer.curr_col].seed_name = name;
                seed_collection[num_seeds].amount--;
                col++;
            }
        }
    }
}

void square_water (struct land farm_land[LAND_SIZE][LAND_SIZE],
                   struct farmer cse_farmer,
                   int square_num)
{
    int row = 0;
    int col = 0;
    int square_row;
    int square_col;
    while (cse_farmer.curr_row - square_num + row <= cse_farmer.curr_row + square_num)
    {
        col = 0;
        while (cse_farmer.curr_col - square_num + col <= cse_farmer.curr_col + square_num)
        {
            square_row = cse_farmer.curr_row - square_num + row;
            square_col = cse_farmer.curr_col - square_num + col;
            if (square_row < 0)
                square_row = 0;
            else if (square_row >= LAND_SIZE)
                square_row = LAND_SIZE - 1;
            if (square_col < 0)
                square_col = 0;
            else if (square_col >= LAND_SIZE)
                square_col = LAND_SIZE - 1;
            farm_land[square_row][square_col].is_watered = TRUE;
            col++;
        }
        row++;
    }
}

void harvest (struct land farm_land[LAND_SIZE][LAND_SIZE],
              struct farmer cse_farmer,
              struct seeds seed_collection[MAX_NUM_SEED_TYPES])
{
    int num_seeds;
    char name;
    if (cse_farmer.curr_dir == '>' && cse_farmer.curr_col != LAND_SIZE - 1)
    {
        name = farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1].seed_name;
        num_seeds = h_seed(name, seed_collection);
        if (name >= 'A' && name <= 'Z')
        {
            printf("  Plant '%c' was harvested, resulting in 5 '%c' seed(s)\n",
                    name, seed_collection[num_seeds].name);
            seed_collection[num_seeds].amount += 5;
        }
    }
    else if (cse_farmer.curr_dir == 'v' && cse_farmer.curr_row != LAND_SIZE - 1)
    {
        name = farm_land[cse_farmer.curr_row + 1][cse_farmer.curr_col].seed_name;
        num_seeds = h_seed(name, seed_collection);
        if (name >= 'A' && name <= 'Z')
        {
            printf("  Plant '%c' was harvested, resulting in 5 '%c' seed(s)\n",
                    name, seed_collection[num_seeds].name);
            seed_collection[num_seeds].amount += 5;
        }
    }
    else if (cse_farmer.curr_dir == '<' && cse_farmer.curr_col != 0)
    {
        name = farm_land[cse_farmer.curr_row][cse_farmer.curr_col - 1].seed_name;
        num_seeds = h_seed(name, seed_collection);
        if (name >= 'A' && name <= 'Z')
        {
            printf("  Plant '%c' was harvested, resulting in 5 '%c' seed(s)\n",
                     name, seed_collection[num_seeds].name);
            seed_collection[num_seeds].amount += 5;
        }
    }
    else if (cse_farmer.curr_dir == '^' && cse_farmer.curr_row != 0)
    {
        name = farm_land[cse_farmer.curr_row - 1][cse_farmer.curr_col].seed_name;
        num_seeds = h_seed(name, seed_collection);
        if (name >= 'A' && name <= 'Z')
        {
            printf("  Plant '%c' was harvested, resulting in 5 '%c' seed(s)\n",
                     name, seed_collection[num_seeds].name);
            seed_collection[num_seeds].amount += 5;
        }
    }
    farm_land[cse_farmer.curr_row][cse_farmer.curr_col + 1].seed_name = NO_SEED;
}

void next_day (struct land farm_land[LAND_SIZE][LAND_SIZE])
{
    int row = 0;
    int col = 0;
    while (row < LAND_SIZE)
    {
        col = 0;
        while (col < LAND_SIZE)
        {
            if (farm_land[row][col].seed_name >= 'a' &&
                farm_land[row][col].seed_name <= 'z' &&
                farm_land[row][col].is_watered == TRUE)
            {
                farm_land[row][col].seed_name -= 32;
            }
            else
            {
                farm_land[row][col].seed_name = NO_SEED;
            }
            farm_land[row][col].is_watered = FALSE;
            col++;
        }
        row++;
    }
}

int trade (struct seeds seed_collection[MAX_NUM_SEED_TYPES],
           char trade_2, int trade_num, int seed_num, int num_1)
{
    int num_seeds = 0;
    while (seed_collection[num_seeds].name != trade_2 && 
           num_seeds < MAX_NUM_SEED_TYPES - 1)
        num_seeds++;
    if (num_seeds == MAX_NUM_SEED_TYPES - 1)
    {
        for (int num = num_1; num >= 0; num--)
        {
            seed_collection[num + 1].name = seed_collection[num].name;
            seed_collection[num + 1].amount = seed_collection[num].amount;
        }
        seed_collection[0].name = trade_2;
        seed_collection[0].amount = trade_num;
        seed_collection[seed_num + 1].amount -= trade_num;
        num_1 += 1;
    }
    else
    {
        seed_collection[num_seeds].amount += trade_num;
        seed_collection[seed_num].amount -= trade_num;
    }
    
    return  num_1;
}

void droughts(struct land farm_land[LAND_SIZE][LAND_SIZE])
{
    int num_1;
    //the class of disaster
    int num_2;
    //how many plants around the PLANT
    int row = 0;
    int col = 0;
    scanf(" %d", &num_1);
    while (row < LAND_SIZE)
    {
        col = 0;
        while (col < LAND_SIZE)
        {
            if (farm_land[row][col].seed_name != NO_SEED)
            {
                num_2 = plants_around(farm_land, row, col);
                droughts_print(farm_land, row, col, num_1, num_2);
            }
            col++;
        }
        row++;
    }
}

void droughts_print(struct land farm_land[LAND_SIZE][LAND_SIZE],
                    int row, int col, int num_1, int num_2)
{
    if (num_2 >= num_1)
     {
        farm_land[row][col].seed_name = NO_SEED;
        farm_land[row][col].die = TRUE;
    }
}

void wind_storms(struct land farm_land[LAND_SIZE][LAND_SIZE])
{
    int num_1;
    //the class of disaster
    int num_2;
    //how many plants around the PLANT
    int row = 0;
    int col = 0;
    scanf(" %d", &num_1);
    while (row < LAND_SIZE)
    {
        col = 0;
        while (col < LAND_SIZE)
        {
            if (farm_land[row][col].seed_name != NO_SEED)
            {
                num_2 = plants_around(farm_land, row, col);
                wind_print(farm_land, row, col, num_1, num_2);
            }
            col++;
        }
        row++;
    }
}

void wind_print(struct land farm_land[LAND_SIZE][LAND_SIZE],
                int row, int col, int num_1, int num_2)
{
    if (num_2 < num_1)
     {
        farm_land[row][col].seed_name = NO_SEED;
        farm_land[row][col].die = TRUE;
    }
}

int plants_around(struct land farm_land[LAND_SIZE][LAND_SIZE], 
                  int current_row, int current_col)
{
    int num = 0;
    int row = current_row - 1;
    int col = current_col - 1;
    if (row < 0)
        row = 0;
    if (col < 0)
        col = 0;
    while (row <= current_row + 1 && row < LAND_SIZE)
    {
        col = current_col - 1;
        if (col < 0)
            col = 0;
        while (col <= current_col + 1 && col < LAND_SIZE)
        {
            if (farm_land[row][col].seed_name != NO_SEED ||
                farm_land[row][col].die == TRUE)
                num++;
            col++;
        }
        row++;
    }
    num -= 1;
    
    return num;
}





////////////////////////////////
//     Provided Functions     //
////////////////////////////////

// Prints the structs land (including locating where the
// farmer is)
// You will need this function in Stage 2.

void print_land (struct land farm_land[LAND_SIZE][LAND_SIZE], struct farmer cse_farmer)
{
    printf("|---|---|---|---|---|---|---|---|\n");
    int i = 0;
    while (i < LAND_SIZE) {
        print_top_row(farm_land, i);
        // only prints mid and bottom row when the farmer
        // is in that row
        if (i == cse_farmer.curr_row) {
            print_farmer_row(farm_land, cse_farmer);
        }
        printf("|---|---|---|---|---|---|---|---|\n");
        i++;
    }
}

// NOTE: You do not need to directly call any of the functions
// below this point. You are allowed to modify them, but you
// do not need to.

// Initialises struct farmer to its default state upon starting
// in which the farmer will be on the top left of the farm
// facing to the right (as noted by '>')
struct farmer initialise_farmer(struct farmer cse_farmer) {
    cse_farmer.curr_col = 0;
    cse_farmer.curr_row = 0;
    cse_farmer.curr_dir = '>';
    return cse_farmer;
}

// Initialises a 2d array of struct land to its default state
// upon starting, which is that all land is unwatered and
// contains no seed
void initialise_land(struct land farm_land[LAND_SIZE][LAND_SIZE]) {
    int i = 0;
    while (i < LAND_SIZE) {
        int j = 0;
        while (j < LAND_SIZE) {
            farm_land[i][j].is_watered = FALSE;
            farm_land[i][j].seed_name = NO_SEED;
            farm_land[i][j].die = FALSE;
            j++;
        }
        i++;
    }
}

// Initialises struct farmer to its default state upon starting,
// which that all names are initialised as NO_SEED and its
// amount is 0
void initialise_seeds(struct seeds seed_collection[MAX_NUM_SEED_TYPES]) {
    int i = 0;
    while (i < MAX_NUM_SEED_TYPES) {
        seed_collection[i].amount = 0;
        seed_collection[i].name = NO_SEED;
        i++;
    }
}

////////////////////////////////
//      Helper Functions      //
////////////////////////////////

// prints the top row of a particular struct land
void print_top_row(struct land farm_land[LAND_SIZE][LAND_SIZE], int row) {
    int j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        printf("%c", farm_land[row][j].seed_name);
        printf(" ");
        if (farm_land[row][j].is_watered == TRUE) {
            printf("W");
        } else {
            printf(" ");
        }
        j++;
    }
    printf("|");
    printf("\n");
}

// prints the 2 additional row when a farmer is in
// a particular row
void print_farmer_row(struct land farm_land[LAND_SIZE][LAND_SIZE],
                      struct farmer cse_farmer)  {
    int j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        if (j == cse_farmer.curr_col) {
            if (cse_farmer.curr_dir == '<') {
                printf("<");
            } else {
                printf(" ");
            }
            if (cse_farmer.curr_dir == '^') {
                printf("^");
            } else {
                printf("f");
            }
            if (cse_farmer.curr_dir == '>') {
                printf(">");
            } else {
                printf(" ");
            }
        } else {
            printf("   ");
        }
        j++;
    }
    printf("|");
    printf("\n");
    j = 0;
    while (j < LAND_SIZE) {
        printf("|");
        if (j == cse_farmer.curr_col) {
            printf(" ");
            if (cse_farmer.curr_dir == 'v') {
                printf("v");
            } else if (cse_farmer.curr_dir == '^') {
                printf("f");
            } else {
                printf(" ");
            }
            printf(" ");
        } else {
            printf("   ");
        }
        j++;
    }
    printf("|");
    printf("\n");
}
