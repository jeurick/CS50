#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)

{
    string text = get_string("Text: ");  // get user input
    printf("Grade ");
    int j = 0;
    int q = 0;
    int w = 0;
    for (int c = 0, n = strlen(text); c < n; c++) // get string length
    {
        if (isalpha(text[c])) // get letter count
        {
            j++;
        }
        if (text[c] == '.' || text[c] == '!' || text[c] == '?') // get sentence count
        {
            q++;
        }
        if (isblank(text[c])) // get word count
        {
            w++;
        }
    }
    float correctw = w + 1;

    float avgj = (j / correctw) * 100; // calc avg letters per 100 words

    float avgq = (q / correctw) * 100; // calc avg sentences per 100 words

    int index = round(0.0588 * avgj - 0.296 * avgq - 15.8); // calc and round grade level

    if (index < 1) // print results
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("%i\n", index);
    }
}
