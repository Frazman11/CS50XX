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

        while(Visa >= 10)
        {
            Visa /= 10;
        }
        if((Visa == 4) && (length == 13 || length == 16))
        {
        printf("%s\n", "VISA");
        return 0;
        }



    //Is it Amex?

        while (Amex >= 10000000000000)
        {
            Amex /= 10000000000000;
        }
        if((length == 15) && (Amex == 34 || Amex == 37))
        {
            printf("%s\n", "AMEX");
            return 0;
        }

    //Is it Mastercard?

        while (Mastercard >= 100000000000000)
        {
            Mastercard /= 100000000000000;
        }
        if(length == 16 && (Mastercard == 51 || Mastercard == 52 || Mastercard == 53 || Mastercard == 54 || Mastercard == 55 ))
        {
            printf("%s\n", "MASTERCARD");
            return 0;
        }
        else
        printf("%s\n", "Invalid!");
}
