#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("What is the height of the pyramid?");
    }
    while (height < 1 || height > 8);
//Print layers 0 --> H

    for (int l = 0; l < height; l++)
    {
        //Print spaces
        for (int s = l + 1; s < height; s++)
        {
            printf(" ");
        }


        //Print hashes
        for (int h = height + l + 1; h > height; h--)
        {
            printf("#");
        }
        printf("\n");

    }

}