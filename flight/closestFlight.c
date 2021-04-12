/*

    Name: closestFlight.c
    Purpose: Determines the flight closest to a user's arrival time at the simulated airport
    Author: grivera64
    Date: 04/10/2021

*/

/* Macros */
#include <stdio.h>
#include <math.h>
#define SIZE 8

/* Function prototypes */
void printChart();                                                                      //prints daily flights table to terminal
void to_minutes(int hours, int minutes, int *total);                                    //converts hh:mm to minutes

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);     //locates the closest time to desired

void to_clock(int total, int *hours, int *minutes);

/* Start of Program */
int main()
{

    //declaring local variables
    int hours, minutes, total;

    //creating arrays of size SIZE and 
    int departures[SIZE] = {0};
    int arrivals[SIZE] = {0};

    /* Initializing each array slot to time in 24-hour time in minutes */
    //for departures
    to_minutes(8, 0, &departures[0]);
    to_minutes(9, 43, &departures[1]);
    to_minutes(11, 19, &departures[2]);
    to_minutes(0, 47, &departures[3]);
    to_minutes(14, 0, &departures[4]);
    to_minutes(15, 45, &departures[5]);
    to_minutes(19, 0, &departures[6]);
    to_minutes(21, 45, &departures[7]);

    //for arrivals
    to_minutes(10, 16, &arrivals[0]);
    to_minutes(11, 52, &arrivals[1]);
    to_minutes(13, 31, &arrivals[2]);
    to_minutes(15, 0, &arrivals[3]);
    to_minutes(16, 8, &arrivals[4]);
    to_minutes(17, 55, &arrivals[5]);
    to_minutes(9, 20, &arrivals[6]);
    to_minutes(23, 58, &arrivals[7]);

    /* Show user the times available */
    printChart();

    /* Ask user for their preferred/desired time */
    printf("\nEnter your desired flight time in a 24-hour hh:mm format: ");
    scanf("%d:%d", &hours, &minutes);

    /* convert their 24-hour time to minutes */
    to_minutes(hours, minutes, &total);

    /* Creating pointers for use in find_closest_flight function */
    int *depart, *arrive;

    /* Point each pointer to the start of its respective array */
    depart = &departures[0];
    arrive = &arrivals[0];

    /* Find the closest  */
    find_closest_flight(total, depart, arrive);

    /* local variables */
    int depart_hours, depart_minutes, arrive_hours, arrive_minutes;
    
    /* Find the hours and minutes of the closest time in minutes */
    to_clock(*depart, &depart_hours, &depart_minutes);
    to_clock(*arrive, &arrive_hours, &arrive_minutes);

    /* Print result to user in a clean 12-hour clock format */
    printf("The closest departure time is %d:%02d %s, arriving at %d:%02d %s\n", 
            (depart_hours % 12) ? depart_hours % 12 : 12, depart_minutes, (depart_hours > 12) ? "p.m." : "a.m.", 
            (arrive_hours % 12) ? arrive_hours % 12 : 12, arrive_minutes, (depart_hours > 12) ? "p.m." : "a.m.");

    /* Terminate the program */
    return 0;

}

/* Prints the Chart/Table to the Terminal */
void printChart()
{

    /* Header */
    printf("%-20s%-20s\n", "Departure Time", "Arrival Time");
    
    /* Details under header */
    printf("%10s%20s\n", "8:00 am", "10:16 am");
    printf("%10s%20s\n", "9:43 am", "11:52 am");
    printf("%10s%20s\n", "11:19 am", "1:31 pm");
    printf("%10s%20s\n", "12:47 am", "3:00 pm");
    printf("%10s%20s\n", "2:00 pm", "4:08 pm");
    printf("%10s%20s\n", "3:45 pm", "5:55 pm");
    printf("%10s%20s\n", "7:00 pm", "9:20 am");
    printf("%10s%20s\n", "9:45 pm", "11:58 pm");

}

/* Converts inserted hours and minutes to just minutes */
void to_minutes(int hours, int minutes, int *total)
{

    //convert hours to minutes
    *total = hours * 60;

    //add rest of the minutes
    *total += minutes;

}

/* Finding the closest time to the desired time */
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{

    /* Create local pointers to store the address of the passed pointers */
    int *depart_pair = departure_time;
    int *arrival_pair = arrival_time;

    /* Search for the closest possible time */
    for (int i = 0; i < SIZE - 1; i++)
    {

        /*
            Check if the difference for the current depart time 
            is greater than the new depart time
        */
        if(abs(*(departure_time + i) - desired_time) > abs(*(departure_time + i + 1) - desired_time)
            && abs(*depart_pair - desired_time) >= abs(*(departure_time + i + 1) - desired_time))
        {

            /* If the current is greater, set the depart_pair to the next one */
            depart_pair = departure_time + i + 1;
            arrival_pair = arrival_time + i + 1;
            
        } //end if

    }

    /* 
        Set value at the address passed in to departure_time 
        to the new value of depart_pair and do the same with arrival_time
    */
    *departure_time = *depart_pair;
    *arrival_time = *arrival_pair;

}

void to_clock(int total, int *hours, int *minutes)
{

    *hours = total / 60;
    *minutes = total % 60;

}