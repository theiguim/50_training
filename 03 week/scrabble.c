#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int get_scrabble_score(char letter)
{
    letter = toupper(letter);

    switch (letter)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'L':
        case 'N':
        case 'S':
        case 'T':
        case 'R':
            return 1;
        case 'D':
        case 'G':
            return 2;
        case 'B':
        case 'C':
        case 'M':
        case 'P':
            return 3;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            return 4;
        case 'K':
            return 5;
        case 'J':
        case 'X':
            return 8;
        case 'Q':
        case 'Z':
            return 10;
        default:
            return 0;
    }
}

int scrabble_word_score(string word)
{
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        score += get_scrabble_score(word[i]);
    }
    return score;
}

int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    int score1 = scrabble_word_score(p1);
    int score2 = scrabble_word_score(p2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
