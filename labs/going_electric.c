//Steve Yang z5374603
#include <stdio.h>

int main(void)
{
    int station[10000];
    int battery = 0;
    int passed = 0; 
    //how long the car passsed + 1
    int i = 0;  
    //road length
    int n = 0; 
    //times of the car should stop
    while (scanf("%d", &station[i]) != EOF)
    {
        i++;
    }
    while (passed < i - 1)
    {
        if (battery < i - passed - 1)
        //If the battery doesn't go the rest of the way
        {
            battery += station[passed];
            if (station[passed] != 0)
                n++;
        }
        passed++;
        battery--;
        if (battery < 0)
        {
            n = 0;
            break;;
        }
    }
    printf("%d\n", n);
    
    return 0;
}
