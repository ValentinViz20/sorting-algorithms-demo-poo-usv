#pragma once

#include "SorterBase.h"

class CocktailSort : public SorterBase
{
public:
	CocktailSort(int arraySize);
	void Sort(bool recordSorting = false) override;
};

