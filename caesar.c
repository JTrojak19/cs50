#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("plaintext: ");
        string plaintext = get_string();
        int key = atoi(argv[1]);
        printf("ciphertext: ");
        for (int i = 0; i<strlen(plaintext); i++)
        {
            if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }
            else if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Invalid number of arguments\n");
        return 1;
    }
}
