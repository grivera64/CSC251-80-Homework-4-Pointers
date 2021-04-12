/*

    Name: validPalindrome.c
    Purpose: Determines whether a provided input is a valid palindrome
             (disregarding spaces or )
    Author: grivera64
    Date: 04/12/2021

*/

/* Macros */
#include <stdio.h>                                                          //Includes standard C input output header
#include <ctype.h>                                                          //Includes tolower() and isspace()

/* Function Prototypes */
int scan_line(char *output, int size);
int is_letter(int letter);
int validate_palindrome(char *input, int size);

/* Main (driver) Function */
int main(void)
{

    /* local variables */
    const int SIZE = 20;
    char answer[SIZE];

    /* request user for a message as a string (char array) */
    printf("Enter a string message: ");
    int input_size = scan_line(&answer[0], SIZE);                           //scan_line is an adaptation of read_line 
                                                                            //created by Dr. Salehin

    printf("User entered: %s\n", answer);

    /* Check if the user input is a palindrome */
    int is_palindrome = validate_palindrome(&answer[0], input_size);

    /* Print the validation result in a user-friendly manner */
    printf("Your input is %sa palindrome!\n", (is_palindrome) ? "" : "not ");

    /* Terminate the Program */
    return 0;

}

/* Scans a line of input from the terminal ignoring not-letter characters */
int scan_line(char *output, int size)
{

    /* Local Variables */
    char c;
    int i = 0;

    /* Skips whitespace in front of user input in terminal */
    while (isspace(c = getchar()));

    /* Loop until a new line character or end of file is found */
    while (c != '\n' && c != EOF)
    {

        /* if still within the array and the input is a letter */
        if (i < size && is_letter(c))
        {

            /* Read the letter in its lowercase form to array location */
            *output = tolower(c);

            /* go to next available slot in array and save the addition count in i */
            output++;
            i++;

        }
        
        /* Get next character in terminal */
        c = getchar();

    }

    /* End string (char array) with a null character */
    *output = '\0';

    /* Return the size of the input (not size of array) */
    return i;

}

/* Return if the provided character is a letter (1 is true; 0 is false) */
int is_letter(int letter)
{

    /*                'A'             'Z'               'a'              'z' */
    return (letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122);

}

/* Validate if a provided character array of size size is a palindrome */
int validate_palindrome(char *input, int size)
{

    /*                   arr[0]             arr[size - 1]   0 to size - 1       0 + 1   size - 1 - 1 etc */
    for (char *left = input, *right = input + size - 1; left < input + size; left++, right--)
    {

        /* If the character on the left is not the same as on the right, then return false (0) */
        if (*left != *right)
        {

            return 0;

        }

    }

    /* If passed all checks, then return true (1) */
    return 1;

}