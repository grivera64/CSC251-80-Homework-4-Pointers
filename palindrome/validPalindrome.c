/*

    Name: validPalindrome.c
    Purpose: Determines whether a provided input is a valid palindrome
             (disregarding spaces or )

*/

#include <stdio.h>
#include <ctype.h>

int scan_line(char *output, int size);
int is_letter(int letter);

int main(void)
{

    const int SIZE = 20;
    char answer[SIZE];

    printf("Enter a string message: ");
    scan_line(&answer[0], SIZE);

    printf("User entered: %s\n", answer);

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