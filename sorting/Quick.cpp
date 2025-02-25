#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>


void quickSort(int arr[], int startingIndex, int endingIndex)
{
    if (startingIndex >= endingIndex)
    {
        return;
    }

    int pivotIndex = partition(arr, startingIndex, endingIndex);
    quickSort(arr, startingIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, endingIndex);
}

int partition(int arr[], int startingIndex, int endingIndex)
{
    int pivot = arr[endingIndex];
    int i = startingIndex - 1;

    for (int j = startingIndex; j < endingIndex; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]); // Use std::swap for safer and clearer swapping
        }
    }

    i++;
    std::swap(arr[i], arr[endingIndex]);

    return i;
}