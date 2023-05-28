#include "BubbleSort.h"

BubbleSort::BubbleSort(int arraySize) : SorterBase(arraySize)
{
}

void BubbleSort::Sort(bool recordSorting)
{
	int temp;
	bool oneSwap = true;
	int stop = array.size() - 1;
	
	while (oneSwap)
	{
		oneSwap = false;
		for (int i = 0; i < stop; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				oneSwap = true;

				if (recordSorting) SaveFrame();
			}
		}

		stop--; // the last element is always sorted
	}
}
