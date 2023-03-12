#include <cs50.h>
#include <stdio.h>

int main(void)
{




    //Set Height Variable and Ask for Height

    int Height;

    //Make it loop while numbers are invalid

    do
    {
        Height = get_int("Choose the Height of the Pyramids (1-8)?");
    }
    while (Height < 1 || Height > 8);

    //Make Master for Loop

    for (int layer = 0; layer < Height; layer++)
    {
        //Print spaces
        for (int spaces = layer + 1; spaces < Height; spaces++)
        {printf(" ");}

        //Print Left Pyramid
        for (int hashes = Height + layer + 1; hashes > Height; hashes--)
        {printf("#");}

        //Print two spaces after first hashes
        printf("  ");

        //print right pyramid
        for (int hashes = Height + layer + 1; hashes > Height; hashes--)
        {printf("#");}

        printf("\n");

    }




}