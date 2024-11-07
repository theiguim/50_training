#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;

    do
    {
        change = get_int("Change owed (in cents): ");
    }
    while (change < 1);

    int coin_count = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    while (change >= quarter)
    {
        change -= quarter;
        coin_count++;
    }

    while (change >= dime)
    {
        change -= dime;
        coin_count++;
    }

    while (change >= nickel)
    {
        change -= nickel;
        coin_count++;
    }

    while (change >= penny)
    {
        change -= penny;
        coin_count++;
    }

    printf("%i\n", coin_count);
}
