//Steve Yang z5374603
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;
void play(int bet)
{
    int temp;
    int i;
    int player_guess;
    char *C = malloc(3 * sizeof(char));
    
    *C = 'J';
    *(C + 1) = 'Q';
    *(C + 2) = 'K';
    printf("shuffling...\n");
    srand((int) time(NULL));
    for (i = 0; i < 5; i++)
    {
        //Mod random numbers so that x and y are in the range of 0,1,2
        int x = rand() % 3; 
        int y = rand() % 3;
        temp = C[x];
        C[x] = C[y];
        C[y] = temp;    
        //Do five random shuffles
    }
    printf("What's the position of Queen 1, 2 or 3? ");
    scanf("%d", &player_guess);
    player_guess -= 1;
    if (C[player_guess] == 'K')
    {
        cash += 3 * bet;
        printf("You win ! Result = %c %c %c Total cash = %d\n", C[0], C[1], C[2], cash);
        printf("***********************************************\n");
    }
    else
    {
        cash -= bet;
        printf("You loose ! Result = %c %c %c Total cash = %d\n", C[0], C[1], C[2], cash);
        printf("***********************************************\n");
    }
    free(C);
}

int main(void) {
    // TODO: Put any setup code here
    int bet;
    // This code will make anything in the brackets run forever
    printf("You have $100 at first and you need to guess the possition of King.\n");
    printf("You will get three times of the bet as prize.\n");
    while (cash > 0) {
        // TODO: Fill this in with the game
        printf("What's your bet? $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash)
        {
            break;
        }
        play(bet);
    }
    
    return 0;
}
