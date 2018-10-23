#include <stdio.h>
#include <cs50.h>

int count = 0;

// Count how many quarters are needed
int quarters(i)
{
    while ((i > 0) && (i >= 25))
    {
        i -= 25;
        count++;
    }
    return i;
}

// Count how many dimes are needed
int dimes(i)
{
    while ((i > 0) && (i >= 10))
    {
        i -= 10;
        count++;
    }
    return i;
}

// Count how many nickels are needed
int nickels(i)
{
    while ((i > 0) && (i >= 5))
    {
        i -= 5;
        count++;
    }
    return i;
}

int pennies(i)
{
    while ((i > 0) && (i >= 1))
    {
        i -= 1;
        count++;
    }
    return i;
}

int main(void)
{
    // Get user input for change amount
    float inputAmount = get_float("Change owed: $");
    inputAmount += 0.0001;

    //Separate the amount of bills from the amount of coins -- NEVERMIND CAUSE APPARENTLY IT WANTS THE DOLLARS BACK IN FUCKING CHANGE TOO UGH
    // int dollars = (int)inputAmount;
    // float changeSum = inputAmount - dollars;

    if (inputAmount > 0)
    {
        int change = inputAmount * 100;
        pennies(nickels(dimes(quarters(change))));
        printf("%d\n", count);
    }
    else
    {
        //If a non-negative number or other data type is entered, restart
        inputAmount = get_float("Change owed: $");
    }

}