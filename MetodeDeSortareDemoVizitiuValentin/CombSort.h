#pragma once

#include "SorterBase.h"
class CombSort : public SorterBase
{
public:
	CombSort(int arraySize);
	void Sort(bool recordSorting = false) override;
};

