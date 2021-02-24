#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//string text = get_string("plaintext: ");
int main(int argc, string argv[1])

{
    if (argc != 2) // reprompt for argument if to many or to few arguments
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string arg = argv[1]; // create string for argument

    int key = atoi(arg); // convert string into integer

    int nonnumeric = 0; // reprompt for agument if nonnumeric

    for (int i = 0, n = strlen(arg); i < n; i++)
    {
        if (isalpha(arg[i]) || ispunct(arg[i]) || isblank(arg[i]) || isspace(arg[i]))
        {
            nonnumeric++;
        }
    }

    if (nonnumeric > 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string input = get_string("plaintext: "); // get user input to cipher

    for (int j = 0, k = strlen(input); j < k; j++) // cipher user input with key
    {
        if (isupper(input[j]))
        {
            input[j] %= 65;
            input[j] = (input[j] + key) % 26;
            input[j] += 65;
        }

        if (islower(input[j]))
        {
            input[j] %= 97;
            input[j] = (input[j] + key) % 26;
            input[j] += 97;
        }

        printf("ciphertext: %s\n", input); // print ciphered text
    }
}
