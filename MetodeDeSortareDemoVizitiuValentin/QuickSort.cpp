#include "QuickSort.h"

QuickSort::QuickSort(int arraySize) : SorterBase(arraySize)
{
}

void QuickSort::Sort(bool recordSorting)
{
    this->recordSorting = recordSorting;

    QuickSortStart(array, 0, array.size() - 1);
}

void QuickSort::Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int QuickSort::Partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];  // Select the rightmost element as the pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j <= high - 1; j++) 
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) 
        {
            i++;  // Increment index of the smaller element
            Swap(arr[i], arr[j]);

            if(recordSorting) SaveFrame();
        }
    }

    Swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the pivot index
}

void QuickSort::QuickSortStart(vector<int>& arr, int low, int high)
{
    if (low < high) 
    {
        // Partition the vector
        int pivotIndex = Partition(arr, low, high);

        // Recursively sort the sub-vectors
        QuickSortStart(arr, low, pivotIndex - 1);
        QuickSortStart(arr, pivotIndex + 1, high);
    }
}
