#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //if no cmd line arguments, or more than 1, return error and message
    if (argc != 2)  //argc = 2 when 2 arguments (file name + 1 input) given.
    {
        printf("%s\n", "Usage: ./caesar key\n");    //print error and end script with return 1
        return 1;
    }

//every char in argv[1]  must be a non negative decimal digit

    string key = argv[1];
    for (int i = 0; i < strlen(argv[1]); i++)   //iterate from 0 to length of string in argv[1] (key)
    {
        if (!isdigit(argv[1][i]))      //if the i char in argv[1] is NOT a digit
        {
            printf("Usage: ./caesar key\n");    //print error
            return 1;   //end script
        }
    }


//Ask user for plaintext:
    string plaintext = get_string("plaintext:  ");

//convert argv[1] from a string to an int
    int k = atoi(key);      //integer k is string "key" converted to integer
    printf("ciphertext:  ");

    //obtain ciphertext
    for (int i = 0; i < strlen(plaintext); i++)     //iterate from 0 to length of plaintext
    {
        if (isupper(plaintext[i]))  //if letter is uppercase
        {
            printf("%c", ((plaintext[i] - 65 + k) % 26) + 65);    //print character using formula (ascii of letter - 65 (to get position of letter) + key) mod26 (gets new position of letter) + 65 (converts back to ascii)
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 97 + k) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[i]);     //if it is not uppercase or lowercase letter, print the plaintext char
        }
    }
    printf("\n");
    return 0;
}