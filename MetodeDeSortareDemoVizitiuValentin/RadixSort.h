#pragma once
#include "SorterBase.h"

class RadixSort : public SorterBase
{
public:
	RadixSort(int arraySize);
	void Sort(bool recordSorting = false) override;
private:
	int recordSorting = false;

	int FindMax(vector<int>& arr); // Function to find the maximum element in the vector
	void CountingSort(vector<int>& arr, int place); // Function to perform counting sort based on the digit at a specific place
};

