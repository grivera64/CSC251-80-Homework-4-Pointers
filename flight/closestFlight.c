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
void printChart();                                              //prints daily flights table to terminal
void to_minutes(int hours, int minutes, int *total);            //converts hh:mm to minutes

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main()
{

    int hours, minutes, total;

    int departures[SIZE] = {0};
    int arrivals[SIZE] = {0};

    to_minutes(8, 0, &departures[0]);
    to_minutes(9, 43, &departures[1]);
    to_minutes(11, 19, &departures[2]);
    to_minutes(0, 47, &departures[3]);
    to_minutes(14, 0, &departures[4]);
    to_minutes(15, 45, &departures[5]);
    to_minutes(19, 0, &departures[6]);
    to_minutes(21, 45, &departures[7]);

    to_minutes(10, 16, &arrivals[0]);
    to_minutes(11, 52, &arrivals[1]);
    to_minutes(1, 31, &arrivals[2]);
    to_minutes(15, 0, &arrivals[3]);
    to_minutes(16, 8, &arrivals[4]);
    to_minutes(17, 55, &arrivals[5]);
    to_minutes(9, 20, &arrivals[6]);
    to_minutes(23, 58, &arrivals[7]);

    printChart();

    printf("\nEnter your desired flight time in a 24-hour hh:mm format: ");
    scanf("%d:%d", &hours, &minutes);

    to_minutes(hours, minutes, &total);

    printf("%d\n", total);

    int *depart, *arrive;

    depart = &departures[0];
    arrive = &arrivals[0];

    find_closest_flight(total, depart, arrive);

    printf("The closest time to %d is %d\n", total, *depart);


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

void to_minutes(int hours, int minutes, int *total)
{

    *total = hours * 60;
    *total += minutes;

}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{

    int *depart_pair = departure_time;
    int *arrival_pair = arrival_time;

    for (int i = 0; i < SIZE - 1; i++)
    {

        if(abs(*(depart_pair + i) - desired_time) > abs(*(depart_pair + i + 1) - desired_time))
        {

            depart_pair = departure_time + i + 1;
            arrival_pair = arrival_time + i + 1;
            
        }

    }

    *departure_time = *depart_pair;
    *arrival_time = *arrival_pair;

}