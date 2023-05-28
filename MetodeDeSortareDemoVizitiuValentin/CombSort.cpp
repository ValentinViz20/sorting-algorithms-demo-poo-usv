#include "CombSort.h"

CombSort::CombSort(int arraySize) : SorterBase(arraySize)
{
}

void CombSort::Sort(bool recordSorting)
{
    int size = array.size();
    int gap = size;
    bool swapped = true;
    int temp;

    while (gap > 1 || swapped) 
    {
        // Update the gap value using the shrink factor
        gap = (gap * 10) / 13;

        if (gap < 1)
            gap = 1;

        swapped = false;

        // Compare elements with the current gap
        for (int i = 0; i < size - gap; i++) 
        {
            if (array[i] > array[i + gap]) 
            {

                temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;

                swapped = true;
                if (recordSorting) SaveFrame();
            }
        }
    }
}
