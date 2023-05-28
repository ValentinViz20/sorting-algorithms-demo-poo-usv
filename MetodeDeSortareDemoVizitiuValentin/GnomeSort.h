#pragma once
#include "SorterBase.h"

class GnomeSort : public SorterBase
{
public:
	GnomeSort(int arraySize);
	void Sort(bool recordSorting = false) override;
};

