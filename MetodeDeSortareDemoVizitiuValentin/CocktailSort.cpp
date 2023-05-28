#include "CocktailSort.h"

CocktailSort::CocktailSort(int arraySize) : SorterBase(arraySize)
{
}

void CocktailSort::Sort(bool recordSorting)
{
    bool swapped = true;
    int start = 0;
    int end = array.size() - 1;
    int temp = 0;

    while (swapped) 
    {
        // Forward pass (like Bubble Sort)
        swapped = false;
        for (int i = start; i < end; i++) 
        {
            if (array[i] > array[i + 1]) 
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                
                swapped = true;
                if (recordSorting) SaveFrame();
            }
        }
        end--;

        if (!swapped)
            break;

        // Backward pass
        swapped = false;
        for (int i = end - 1; i >= start; i--) 
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swapped = true;
                if (recordSorting) SaveFrame();
            }
        }
        start++;
    }
}
