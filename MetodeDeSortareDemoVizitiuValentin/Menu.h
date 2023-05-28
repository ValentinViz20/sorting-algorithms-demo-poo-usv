#pragma once

#include <iostream>
#include <cstdlib> 
#include <chrono>

#include "InputReader.h"
#include "SorterBase.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "DummyAlgorithm.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "CombSort.h"
#include "CycleSort.h"
#include "GnomeSort.h"
#include "OddEvenSort.h"
#include "CocktailSort.h"
#include "Utilities.h"
#include "FileManager.h"
#include "Logger.h"

using std::cout;

/// <summary>
/// Handles the different menus and screens in the app
/// </summary>
class Menu
{
private:
	InputReader* _inputReader;
	FileManager* _fileManager;
	Logger* _logger;

	// Prints the fancy box for displaying the current frame from each algorithm
	void DisplaySideBySideAlgorithms(
		int frame,
		string algorithmOneName,
		string algorithmTwoName,
		SorterBase* algorithmOne,
		SorterBase* algorithmTwo
	);
public:
	Menu(InputReader* inputReader, FileManager* fileManager, Logger* logger);
	void MainMenu(); // Handles the main menu of the app
	void DuelSortingAlgorithmsMenu(); // Handles choosing what algorithms are used to visualize side by side

	void BenchmarkSortingAlgorithmMenu(); // Benchmarks an algorithm and shows the results

	// Displays the two algorithms side by side, and handles the different options
	void AlgorithmsDuelScreen(string algorithmOneName, string algorithmTwoName, SorterBase* algorithmOne, SorterBase* algorithmTwo); 

	// The submenu to load a previously saved sorting
	void SelectAlgorithmSaveMenu();

	void AlgorithmSelectionMenu(
		SorterBase** alg1,
		SorterBase** alg2, 
		string& algName1, 
		string& algName2, 
		int arraySize = ARRAY_SIZE_VISUALIZE
	); // the menu for selecting two algorithms

	void ClearTerminal(); // Clears everything in the terminal

	void HelpMenu(); // displays the help menu
};

