#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Minutes: ");
    int minutes = get_int();
    int water_consumption = (192/16)*minutes;
    printf("%i\n", water_consumption);
}
