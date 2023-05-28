#include "SorterBase.h"

SorterBase::SorterBase(int arraySize)
{
	// Initializes the array with the numbers from 0 to arraySize
	for (int i = 1; i <= arraySize; i++)
	{
		array.push_back(i);
	}
}

void SorterBase::SaveFrame()
{
	vector<int> vectorFrame(array);

	sortingFrames.push_back(vectorFrame);
}

void SorterBase::RandomizeArray()
{
	// Create a random number generator
	std::random_device rd;
	std::mt19937 g(rd());

	// Shuffle the vector using std::shuffle
	std::shuffle(array.begin(), array.end(), g);
}

string SorterBase::GetArraySample()
{
	string output = "[";

	//"1, 2, 3, 4, 5, [... 10 more numbers ...] , 9, 10, 11";

	if (array.size() >= 21)
	{
		for (int i = 0; i < 10; i++)
		{
			output += std::to_string(array[i]);
			output += ", ";
		}

		output += "[... " + std::to_string(array.size() - 20) + " more numbers ...], ";

		for (int i = array.size() - 10; i < array.size(); i++)
		{
			output += std::to_string(array[i]);
			if ((i + 1) < array.size())
			{
				output += ", ";
			}
		}
		output += "]";
	}
	else
	{
		for (int i = 0; i < array.size(); i++)
		{
			output += std::to_string(array[i]);
			if ((i + 1) < array.size())
			{
				output += ", ";
			}
		}
		output += "]";
	}

	return output;
}

void SorterBase::CopyArrayFrom(SorterBase* sourceAlgorithm)
{
	this->array.clear();

	for (int i = 0; i < sourceAlgorithm->array.size(); i++)
	{
		array.push_back(sourceAlgorithm->array[i]);
	}
}
