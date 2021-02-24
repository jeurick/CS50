#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int coins = 0;

    do
    {
        dollars = get_float("Change owed: "); // prompt dollars
    }
    while (dollars < 0);

    int cents = round(dollars * 100); // convert to change

    while (cents >= quarter) // quarters required
    {
        cents -= quarter;
        coins++;
    }

    while (cents >= dime) // dimes required
    {
        cents -= dime;
        coins++;
    }

    while (cents >= nickel) // nickels required
    {
        cents -= nickel;
        coins++;
    }

    while (cents >= penny) // pennies required
    {
        cents -= penny;
        coins++;
    }
    while (true) // print amount of coins
    {
        printf("%i\n", coins);
        break;
    }
}
