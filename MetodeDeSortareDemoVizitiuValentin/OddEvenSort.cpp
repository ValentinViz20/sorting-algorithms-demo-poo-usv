#include "OddEvenSort.h"

OddEvenSort::OddEvenSort(int arraySize) : SorterBase(arraySize)
{
}

void OddEvenSort::Sort(bool recordSorting)
{
    int size = array.size();
    bool sorted = false;
    int temp;

    while (!sorted) 
    {
        sorted = true;

        // Odd phase
        for (int i = 1; i < size - 1; i += 2) 
        {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = false;

                if (recordSorting) SaveFrame();
            }
        }

        // Even phase
        for (int i = 0; i < size - 1; i += 2) 
        {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = false;

                if (recordSorting) SaveFrame();
            }
        }
    }
}
