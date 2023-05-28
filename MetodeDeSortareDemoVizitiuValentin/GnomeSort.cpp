#include "GnomeSort.h"

GnomeSort::GnomeSort(int arraySize) : SorterBase(arraySize)
{
}

void GnomeSort::Sort(bool recordSorting)
{
    int size = array.size();
    int i = 1;
    int temp;

    while (i < size) 
    {
        if (i > 0 && array[i] < array[i - 1])
        {
            temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
            i--;

            if (recordSorting) SaveFrame();
        }
        else 
        {
            i++;
        }
    }
}
