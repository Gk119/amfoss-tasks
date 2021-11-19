#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float owed;
    while(1)
    {
        owed = get_float("Change owed: ");
        if(owed >= 0) break;
    }
    int cents = round(owed * 100);
    int coins = 0;
    while(cents - 25 >= 0)
    {
        coins++;
        cents -= 25;
    }
    //printf("%d\n",coins);
    while(cents - 10 >= 0)
    {
        coins++;
        cents -= 10;
    }
    while(cents - 5 >= 0)
    {
        coins++;
        cents -= 5;
    }
    while(cents - 1 >= 0)
    {
        coins++;
        cents -= 1;
    }
    printf("%d\n",coins);
    return 0;
}