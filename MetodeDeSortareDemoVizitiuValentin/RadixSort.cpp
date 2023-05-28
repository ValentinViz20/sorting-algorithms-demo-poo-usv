#include "RadixSort.h"

RadixSort::RadixSort(int arraySize) : SorterBase(arraySize)
{
}

void RadixSort::Sort(bool recordSorting)
{
    this->recordSorting = recordSorting;
    int max = FindMax(array);

    // Perform counting sort for every digit
    for (int place = 1; max / place > 0; place *= 10)
    {
        CountingSort(array, place);
    }
}

int RadixSort::FindMax(vector<int>& arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

void RadixSort::CountingSort(vector<int>& arr, int place)
{
    const int radix = 10;
    int size = arr.size();
    vector<int> count(radix, 0);
    vector<int> output(size);

    // Count the occurrences of each digit in the current place
    for (int i = 0; i < size; i++) 
    {
        int digit = (arr[i] / place) % radix;
        count[digit]++;
    }

    // Compute the cumulative count
    for (int i = 1; i < radix; i++) 
    {
        count[i] += count[i - 1];
    }

    // Build the output array in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (arr[i] / place) % radix;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Update the original array with the sorted elements
    for (int i = 0; i < size; i++) 
    {
        arr[i] = output[i];
        if (recordSorting) SaveFrame();
    }
}
