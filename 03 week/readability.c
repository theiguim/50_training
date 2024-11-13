#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0, words = 1, sentences = 0;

    int i = 0;

    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        i++;
    }

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = (int) (index + 0.5);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
