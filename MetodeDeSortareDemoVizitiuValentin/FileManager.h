#pragma once

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "InputReader.h"
#include "SorterBase.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::getline;
namespace fs = std::filesystem;

class FileManager
{
public:
	FileManager(); // ctor, creates the required file paths when called
	void SaveSortingFramesToFile(
		int currentFrame,
		string fileName,
		const vector<vector<int>> sortingFramesAlg1,
		const vector<vector<int>> sortingFramesAlg2,
		string algorthName1,
		string algorthName2
	); // Saves the current satate of the algorithm duels to a file

	void LoadSortingFramesFromFile(
		string filename,
		SorterBase* dummyAlgoritm1,
		SorterBase* dummyAlgoritm2,
		string& algorithmName1,
		string& algorithmName2
	); // Loads any previously saved satate

	vector<string> GetAllFilesFromFolder(string folderName); // returns a vector with all the files from a folder
};

