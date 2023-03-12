#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //if no cmd line arguments, or more than 1, return error and message
    if (argc != 2)  //argc = 2 when 2 arguments (file name + 1 input) given.
    {
        printf("%s\n", "Usage: ./substituation key\n");    //print error and end script with return 1
        return 1;
    }

//every char in argv[1]  must be alpha, there must be 26

    string key = argv[1];
    for (int i = 0; i < strlen(argv[1]); i++)   //iterate from 0 to length of string in argv[1] (key)
    {
        if (!isalpha(argv[1][i]))      //if the i char in argv[1] is NOT alphabetical
        {
            printf("Usage: ./substitution key\n");    //print error
            return 1;   //end script
        }
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");    //print error
        return 1;   //end script
    }
    //make sure key only has unique letters (no repeats)
    //compare letter key[i] to rest of key ( key[j]) where j = n+1
    int n = strlen(key);
    for (int i = 0; i < n ; i++)
    {

        for (int j = i + 1; j < n ; j ++)
        {
            if ((key[i]) == (key[j]))
            {
                printf("Usage: ./substitution key\n");    //print error
                return 1;   //end script
            }
        }
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]) != 0)
        {
            int letter = plaintext[i] - 97;  //make new variable int letter, to change letter (plaintext[i]) ascii value to alphabetical index
            printf("%c", tolower(key[letter])); //print character from key (forced to lowercase) corresponding to letter's alpha index
        }
        else if (isupper(plaintext[i]) != 0)
        {
            int letter = plaintext[i] - 65;
            printf("%c", toupper(key[letter]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;

}