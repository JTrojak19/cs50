#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    printf("Change: ");
    change = get_float();


    float amountInCents = round(change*100);
    int count = 0;
    printf("%f\n", amountInCents);
    for (int i = 1; i< (int)amountInCents; i++)
    {
        if ((int)amountInCents % 25 == 0)
        {
            amountInCents = amountInCents - 25;
            count = count + 1;
        }
        else if ((int)amountInCents % 10 == 0)
        {
            amountInCents = amountInCents - 10;
            count = count + 1;
        }
        else if ((int)amountInCents % 5 == 0)
        {
            amountInCents = amountInCents - 5;
            count = count + 1;
        }
        else if ((int)amountInCents % 1 == 0)
        {
            amountInCents = amountInCents - 1;
            count = count + 1;
        }
        printf("%i\n", count);
        printf("%f\n", amountInCents);
    }
}
