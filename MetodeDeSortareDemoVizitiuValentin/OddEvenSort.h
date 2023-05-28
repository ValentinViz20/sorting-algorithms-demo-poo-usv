#pragma once
#include "SorterBase.h"

class OddEvenSort : public SorterBase
{
public:
	OddEvenSort(int arraySize);
	void Sort(bool recordSorting = false) override;
};

