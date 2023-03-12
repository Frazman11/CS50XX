#include <cs50.h>
#include <stdio.h>

int main(void)
{
// prompt user for card number
    long card;
    do
    {
        card = get_long("Enter Credit Card Number:");
    }
    while (card < 0);    //card number must be >0

//determine whether card number is valid

    long card0 = card;
    int total = 0;
    int total2 = 0;
    int counter = 1;

    while (card0 > 0)
    {
        //if counter is even, multiply by 2 and add digits (//take every other digit from card number using % and counters)

        if (counter % 2 == 0)   //remainder of (even# / 2) rounded up = 0
        {
            int num2 = card0 % 10 * 2;       //num2 = even digit*2
            total = total + num2 % 10;      //add last digit of num2 to total
            total = total + num2 / 10 % 10; //add first digit (if there is one) of num2 to total
        }
        else if (counter % 2 == 1)          // remainder of (odd# / 2) rounded up (because integer) = 1
        {
            int num3 = card0 % 10;      //num3 is the digit of the card number
            total2 = total2 + num3;     //total2 is sum of num3's
        }
        card0 = card0 / 10;         //remove last digit by diving by 10
        counter ++;         //increase counter by 1
    }

    int totalf = total + total2;
    if (totalf % 10 != 0)           // if last digit of sum is 0, it is valid.
    {
        printf("INVALID\n");
        return 0;
    }


    //determine whether card is Amex, Mastercard or Visa

    int length = 0;
    long Visa = card;
    long Amex = card;
    long Mastercard = card;

    while (card > 0)
    {
        card = card / 10;
        length++;
    }

    //is it a Visa?

    while (Visa >= 10)
    {
        Visa /= 10;
    }
    if ((Visa == 4) && (length == 13 || length == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }



    //Is it Amex?

    while (Amex >= 10000000000000)
    {
        Amex /= 10000000000000;
    }
    if ((length == 15) && (Amex == 34 || Amex == 37))
    {
        printf("%s\n", "AMEX");
        return 0;
    }

    //Is it Mastercard?

    while (Mastercard >= 100000000000000)
    {
        Mastercard /= 100000000000000;
    }
    if (length == 16 && (Mastercard == 51 || Mastercard == 52 || Mastercard == 53 || Mastercard == 54 || Mastercard == 55))
    {
        printf("%s\n", "MASTERCARD");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
    }

}
