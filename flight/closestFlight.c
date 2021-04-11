/*

    Name: closestFlight.c
    Purpose: Determines the flight closest to a user's arrival time at the simulated airport
    Author: grivera64
    Date: 04/10/2021

*/

/* Macros */
#include <stdio.h>

/* Function prototypes */
void printChart();                                              //prints daily flights table to terminal

int main()
{

    printChart();

    return 0;

}

void printChart()
{

    printf("%-20s%-20s\n", "Departure Time", "Arrival Time");
    printf("%10s%20s\n", "8:00 am", "10:16 am");
    printf("%10s%20s\n", "9:43 am", "11:52 am");
    printf("%10s%20s\n", "11:19 am", "1:31 am");
    printf("%10s%20s\n", "12:47 am", "3:00 pm");
    printf("%10s%20s\n", "2:00 pm", "4:08 pm");
    printf("%10s%20s\n", "3:45 pm", "5:55 pm");
    printf("%10s%20s\n", "7:00 pm", "9:20 am");
    printf("%10s%20s\n", "9:45 pm", "11:58 pm");

}