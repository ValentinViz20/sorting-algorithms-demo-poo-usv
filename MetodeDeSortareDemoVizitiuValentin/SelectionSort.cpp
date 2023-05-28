#include "SelectionSort.h"

SelectionSort::SelectionSort(int arraySize) : SorterBase(arraySize)
{
}

void SelectionSort::Sort(bool recordSorting)
{
	int temp;
	bool oneSwap = true;
	int stop = array.size() - 1;

	for (int i = 0; i < stop; i++)
	{
		int smallestPos = i;
		for (int j = i; j < array.size(); j++)
		{
			if (array[j] < array[smallestPos])
				smallestPos = j;
		}

		temp = array[smallestPos];
		array[smallestPos] = array[i];
		array[i] = temp;

		if (recordSorting) SaveFrame();
	}
}
