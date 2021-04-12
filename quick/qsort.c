/*
* Program: qsort.c
* Purpose: Orders an array of size 7 in increasing order
*          using Quick Sort with pointers
* Author: grivera64
* Date: 04/12/2021 (Adapted from qsort.c from 03/08/2021)
*/

//Defining the header files to use
#include <stdio.h>
//Defining constants using Macro
#define N 7
#define EMPTY 987654321

//declaring function prototypes
void quick_sort(int *arr_first, int *arr_last, int *left, int *right);
int *split(int *arr_first, int *arr_last, int *left, int *right);

//main (driver) function
int main(void)
{

    //declaring an array with an initialized value of 0
    int arr[N] = {0};

    //requesting for user input
    printf("Enter %d values to sort: ", N);
    scanf("%d %d %d %d %d %d %d", 
    &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]);

    //calling quick sort alorithm and passing array by reference
    quick_sort(&arr[0], &arr[N - 1], &arr[0], &arr[N - 1]);

    //printing sorted array
    printf("\nNew array reads: ");

    for (int num = 0; num < N; num++)
    {

        printf("%d ", arr[num]);
    
    }

    printf("\n");


    //exiting program
    return 0;
}

//recursive function for sorting the array using the quick sort 
//algorithm
void quick_sort(int *arr_start, int *arr_end, int *left, int *right)
{

    //base case for recursive formula
    if (left >= right || left < arr_start || right > arr_end)
    {

        //stop recursion
        return;

    }

    //split the array into two
    int *middle = split(arr_start, arr_end, left, right);
    //check the first half
    quick_sort(arr_start, arr_end, left, middle);
    //check the second half
    quick_sort(arr_start, arr_end, middle + 1, right);
}

//returns a middle section of the array to split the array by
int *split(int *arr_start, int *arr_end, int *left, int *right)
{

    //setting the pivot of the array to start from
    int pivot = *left;
    *left = EMPTY;

    //iterate until the current values match the pivot's location
    //(using lecture 8 [February 24] algorithm technique)
    while (left <= right)
    {


        //if highIndex is not empty
        if (*right != EMPTY)
        {

            //check if matches pivot
            if (*right >= pivot)
            {

            //go to next index
            right--;

            }
            else
            {

            //switch and keep same pivot
            *left = *right;
            left++;
            *right = (left >= right) ? pivot : EMPTY;

            }

        }
        // if lowIndex is not empty
        else if (*left != EMPTY)
        {
            
            //check if matches pivot
            if (*left <= pivot)
            {

                //continue
                left++;

            }
            else
            {

                //switch and keep same pivot
                *right = *left;
                right--;
                *left = (left >= right) ? pivot : EMPTY;

            }

        }
        //if both are empty
        else
        {

            //fill the last EMPTY array slot with the pivot's value
            //(Shouldn't have a true difference as lowIndex == highIndex)
            if (*left == EMPTY)
            {

                *left = pivot;

            }
            else
            {

                *right = pivot;

            }

            break;
        }

    }

    //return the current pivot's index
    //(both highIndex and lowIndex contain its index)
    return left;
}