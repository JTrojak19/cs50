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
        string keyword = argv[1];
        int j = 0;
        printf("ciphertext: ");
        for (int i = 0; i< strlen(plaintext); i++)
        {
            j = j % strlen(argv[1]);
            //printf("%i\n", j);
            j++;

            if (isalpha(plaintext[i]))
            {
                if (islower(plaintext[i]) && islower(keyword[j]))
                {
                    printf("%c", (((plaintext[i] - 97) + (keyword[j] - 97)) % 26) + 97);
                }
                else if (isupper(plaintext[i]) && islower(keyword[j]))
                {
                    printf("%c", (((plaintext[i] - 65) + (keyword[j] - 97)) % 26) + 65);
                }
                else if (islower(plaintext[i]) && isupper(keyword[j]))
                {
                    printf("%c", (((plaintext[i] - 97) + (keyword[j] - 65)) % 26) + 97);
                }
                else if (isupper(plaintext[i]) && isupper(keyword[j]))
                {
                    printf("%c", (((plaintext[i] - 65) + (keyword[j] - 65)) % 26) + 65);
                }
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
        }
        printf("\n");
    }
}
