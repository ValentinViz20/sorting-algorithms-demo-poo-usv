#pragma once

#include "SorterBase.h"

class BubbleSort : public SorterBase
{
public:
	BubbleSort(int arraySize);
	void Sort(bool recordSorting = false) override;
};

