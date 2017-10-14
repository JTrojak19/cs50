#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    string userInput = get_string();
    char *token = NULL;
    char *search = " ";
    token = strtok(userInput, search);
    while (token != NULL)
    {
        if (islower(token[0]))
        {
            printf("%c", toupper(token[0]));
            token = strtok(NULL, search);
        }
        else
        {
            printf("%c", token[0]);
            token = strtok(NULL, search);
        }
    }
        printf("\n");
}
