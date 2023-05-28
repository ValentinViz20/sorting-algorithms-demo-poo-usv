#pragma once

#include "SorterBase.h"

// A dummy algorithm to be filled with propreties
class DummyAlgorithm : public SorterBase
{
public:
	DummyAlgorithm();
	void Sort(bool recordSorting = false) override;
};

