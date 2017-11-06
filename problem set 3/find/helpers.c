/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

bool binary_search(int value, int values[], int n);
void selection_sort (int values[], int n);
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (value < 0)
    {
        return false;
    }
    else
    {
        return binary_search(value, values, n);
    }
}

bool binary_search(int value, int values[], int n)
{
    int end = n - 1;
    int start = 0;

    while (end >= start)
    {
        int middle = (start + end)/2;

        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] > value)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    selection_sort(values, n);
    return;
}
void selection_sort (int values[], int n)
{
    int temp;

    for (int i = 0; i< n; i++)
    {
        int smallestIndex = i;

        for (int j = i + 1; j<n; j++)
        {
            if (values[smallestIndex] > values[j])
            {
                smallestIndex = j;
            }
        }
        temp = values[smallestIndex];
        values[smallestIndex] = values[i];
        values[i] = temp;
    }
}
