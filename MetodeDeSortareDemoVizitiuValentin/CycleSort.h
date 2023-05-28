#pragma once
#include "SorterBase.h"

class CycleSort : public SorterBase
{
public:
	CycleSort(int arraySize);
	void Sort(bool recordSorting = false) override;
};

