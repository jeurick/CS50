#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    // get credit card
    int doubledDigit;
    char* input = printf("Credit Card: ");
    int digit = input[strlen(input)];
    int sum = digit;

    // do formula

    for (int i = 0, j = (strlen(input) - 1); i <= j; i++)
    {
        if (j % 2 == 0)
        {
            if ((j - i) % 2 != 0 && (j - i) != j)
            {
                digit = input[j - i] % 48;
                doubledDigit = digit * 2;
                if (doubledDigit >= 10)
                {
                    sum += (1 + doubledDigit % 10);
                }
                else
                {
                    sum += doubledDigit;
                }
            }
            else
            {
                digit = input[j - i] % 48;
                sum += digit;
            }
        }
        if (j % 2 != 0)
        {
            if ((j - i) % 2 == 0 && (j - i) != j)
            {
                digit = input[j - i] % 48;
                doubledDigit = digit * 2;
                if (doubledDigit >= 10)
                {
                    sum += (1 + doubledDigit % 10);
                }
                else
                {
                    sum += doubledDigit;
                }
            }
            else
            {
                digit = input[j - i] % 48;
                sum += digit;
            }
        }
    }
    // check card restrictions
    int AMEX = 0;
    int MASTERCARD = 0;
    int VISA = 0;
    if (input[0] % 48 == 5)
    {
        if (input [1] % 48 == 0 || input[1] % 48 > 5)
        {
            MASTERCARD++;
        }
    }

    if (input[0] % 48 == 3)
    {
        if (input[1] % 48 != 4 && input[1] % 48 != 7)
        {
            AMEX++;
        }
    }

    if (input[0] % 48 == 4)
    {
        if (strlen(input) != 13 && strlen(input) != 16)
        {
            VISA++;
        }
    }
    // print answer
    if (AMEX == 0 && input[0] % 48 == 3 && sum % 10 == 0 && strlen(input) == 15)
    {
        printf("AMEX\n");
    }
    else if (VISA == 0 && input[0] % 48 == 4 && sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else if (input[0] % 48 == 5 && MASTERCARD == 0 && input[1] != 0 && sum % 10 == 0 && strlen(input) == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
