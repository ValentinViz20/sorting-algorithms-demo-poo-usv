#pragma once
#include "SorterBase.h"

class MergeSort : public SorterBase
{
public:
	MergeSort(int arraySize);
	void Sort(bool recordSorting = false) override;
private:
	int recordSorting = false;

	// Function to merge two sorted sub - vectors into one sorted vector
	void Merge(std::vector<int>& arr, int left, int mid, int right);
	
	// Function to implement Merge Sort
	void MergeSortStart(std::vector<int>& arr, int left, int right);
};


