#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //Ask for name

    string name = get_string("What is your name?");

    //Print name
    
    printf("Hello, %s!\n", name);
}