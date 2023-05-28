#pragma once
#include "SorterBase.h"

class SelectionSort :public SorterBase
{
public:
	SelectionSort(int arraySize);
	void Sort(bool recordSorting = false) override;
};

