/*

    Name: validPalindrome.c
    Purpose: Determines whether a provided input is a valid palindrome
             (disregarding spaces or )

*/

#include <stdio.h>
#include <ctype.h>

int scan_line(char *output, int size);
int is_letter(int letter);
int validate_palindrome(char *input, int size);

int main(void)
{

    const int SIZE = 20;
    char answer[SIZE];

    printf("Enter a string message: ");
    int input_size = scan_line(&answer[0], SIZE);

    printf("User entered: %s\n", answer);

    int is_palindrome = validate_palindrome(&answer[0], input_size);

    printf("Your input is %sa palindrome!\n", (is_palindrome) ? "" : "not ");

    return 0;

}

int scan_line(char *output, int size)
{

    char c;
    int i = 0;

    while (isspace(c = getchar()));

    while (c != '\n' && c != EOF)
    {

        if (i < size && is_letter(c))
        {

            *output = tolower(c);
            output++;
            i++;

        }
        
        c = getchar();

    }

    *output = '\0';

    return i;

}

int is_letter(int letter)
{

    return (letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122);

}

int validate_palindrome(char *input, int size)
{

    for (char *left = input, *right = input + size - 1; left < input + size; left++, right--)
    {

        if (*left != *right)
        {

            return 0;

        }

    }

    return 1;

}