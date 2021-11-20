#include <stdio.h>

int main()
{
    int height = 0;
    while(1)
    {
        printf("Height: ");
        scanf("%d", &height);
        if(height > 0 && height < 9) break;
        else while(getchar() != '\n');
    }
    for(int i = 1; i <= height; i++)
    {
        for(int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        for(int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        printf("\n");
    }

}