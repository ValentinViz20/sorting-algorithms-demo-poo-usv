#pragma once
#include <vector>
#include <string>
#include <random>

using std::vector;
using std::string;

/// <summary>
/// Base Class for any sorting algorithm implementation
/// </summary>
class SorterBase
{
protected:
	// the array to sort 
	vector<int> array;

public:
	// a vector with copies of the array to sort at each step of the sorting process
	vector<vector<int>> sortingFrames;

	SorterBase(int arraySize);
	// The function that sorts the whole array
	// recordSorting specifies if the function should save all the sorting steps in the sortingFrames vector
	virtual void Sort(bool recordSorting = false) = 0;

	// Saves the current state of the array to the sortingFrames vector
	void SaveFrame();

	// Shuffles the elements of the array
	void RandomizeArray();

	// Returns the first and last 10 elements of the array into a formatted string
	string GetArraySample(); 

	// Copies the array of one algorithm to another
	void CopyArrayFrom(SorterBase* sourceAlgorithm);
};

