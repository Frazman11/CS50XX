#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//introduce prototypes
int count_letters(string text);
int count_words(string text);
int count_sent(string text);

int main(void)
{
    string text = get_string("Text: ");
    float l = count_letters(text);
    float w = count_words(text);
    float s = count_sent(text);
//Calculate L and S
    float L = ((l / w) * 100);
    float S = ((s / w) * 100);

    float index = ((0.0588 * L - 0.296 * S - 15.8));
    int index_rounded = round(index);
//code print behaviour
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index_rounded);
    }

}


int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))       //if letter is alpha, add one to letters
        {
            letters ++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)      //iterate from 0-->strlen over each letter
    {
        if (text[i] == ' ')     //if letter is a space
        {
            words ++;
        }
    }
    return words;
}

int count_sent(string text)
{
    int sent = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sent ++;
        }
    }
    return sent;
}
