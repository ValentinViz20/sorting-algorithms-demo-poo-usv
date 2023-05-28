#pragma once
#include "SorterBase.h"

class QuickSort : public SorterBase
{
public:
	QuickSort(int arraySize);
	void Sort(bool recordSorting = false) override;
private:
	bool recordSorting = false;

	void Swap(int& a, int& b); // Function to swap two elements
	void QuickSortStart(std::vector<int>& arr, int low, int high); // Function to implement QuickSort
	int Partition(std::vector<int>& arr, int low, int high); // Function to partition the vector and return the pivot index
};

