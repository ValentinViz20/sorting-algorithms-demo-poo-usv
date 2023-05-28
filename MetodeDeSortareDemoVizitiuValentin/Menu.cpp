#include "Menu.h"


Menu::Menu(InputReader* inputReader, FileManager* fileManager, Logger* logger)
{
	_inputReader = inputReader;
	_fileManager = fileManager;
	_logger = logger;
}

void Menu::MainMenu()
{
	int option;
	while (true)
	{
		ClearTerminal();

		cout << YELLOW << R"DELIM(
 _____            _   _                ___  _                  _ _   _                    ______ ________  ________
/  ___|          | | (_)              / _ \| |                (_) | | |                   |  _  \  ___|  \/  |  _  |
\ `--.  ___  _ __| |_ _ _ __   __ _  / /_\ \ | __ _  ___  _ __ _| |_| |__  _ __ ___  ___  | | | | |__ | .  . | | | |
 `--. \/ _ \| '__| __| | '_ \ / _` | |  _  | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __| | | | |  __|| |\/| | | | |
/\__/ / (_) | |  | |_| | | | | (_| | | | | | | (_| | (_) | |  | | |_| | | | | | | | \__ \ | |/ /| |___| |  | \ \_/ /
\____/ \___/|_|   \__|_|_| |_|\__, | \_| |_/_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/ |___/ \____/\_|  |_/\___/ 
                               __/ |           __/ |                                                                
                              |___/           |___/                                                                  )DELIM";

		cout << RESET << "\n\nPlease select an option: \n"
			<< "1. Run two algorithms side by side\n"
			<< "2. Benchmark two algorithms\n"
			<< "3. Load previously saved algorithm duels\n"
			<< "4. Help\n"
			<< "5. Exit\n\n"
			<< ">>> ";

		option = _inputReader->ReadNumber();

		switch (option)
		{
		case 1:
			DuelSortingAlgorithmsMenu();
			break;
		case 2:
			BenchmarkSortingAlgorithmMenu();
			break;
		case 3:
			SelectAlgorithmSaveMenu();
			break;
		case 4:
			HelpMenu();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "Invalid option, please input one of the available option.\n"
				<< "Press ENTER to continue... ";
			_inputReader->ReadOneChar();
			break;
		}
	}
}


void Menu::DuelSortingAlgorithmsMenu()
{
	SorterBase* algorithmOne = nullptr;
	SorterBase* algorithmTwo = nullptr;
	string algorithmNameOne;
	string algorithmNameTwo;

	ClearTerminal();
	AlgorithmSelectionMenu(&algorithmOne, &algorithmTwo, algorithmNameOne, algorithmNameTwo);

	algorithmOne->RandomizeArray();
	algorithmTwo->RandomizeArray();

	algorithmOne->Sort(true);
	algorithmTwo->Sort(true);

	AlgorithmsDuelScreen(algorithmNameOne, algorithmNameTwo, algorithmOne, algorithmTwo);
	_inputReader->ReadOneChar();
}



void Menu::BenchmarkSortingAlgorithmMenu()
{
	ClearTerminal();

	SorterBase* algorithmOne = nullptr;
	SorterBase* algorithmTwo = nullptr;
	string algorithmNameOne;
	string algorithmNameTwo;

	cout << "\nPlease provide the size of the array to sort during the benchmark: \n"
		<< ">>> ";

	int arraySize = _inputReader->ReadNumber(1, ARRAY_TO_SORT_MAX_SIZE);

	_logger->LogInfo("Initializing sorting algorithms...\n");

	AlgorithmSelectionMenu(&algorithmOne, &algorithmTwo, algorithmNameOne, algorithmNameTwo, arraySize);

	ClearTerminal();

	_logger->LogInfo("Shuffling the arrays to sort...\n");
	algorithmOne->RandomizeArray();

	// copy the arrays so they are the same, so the performance is more accurate
	algorithmTwo->CopyArrayFrom(algorithmOne);

	_logger->LogImportant("The array looks like this before the sorting: " + algorithmOne->GetArraySample() + "\n");

	_logger->LogWarning("Sorting started for " + algorithmNameOne + ", please wait...\n");

	// Sorting the first algorithm ================================================
	auto startTime = std::chrono::high_resolution_clock::now();

	algorithmOne->Sort();

	auto endTime = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsedAlgorithmOne = endTime - startTime;

	_logger->LogWarning("Sorting started for " + algorithmNameTwo + ", please wait...\n");

	// Sorting the second algorithm ================================================
	startTime = std::chrono::high_resolution_clock::now();

	algorithmTwo->Sort();

	endTime = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsedAlgorithmTwo = endTime - startTime;

	// Display results =============================================================

	_logger->LogInfo("Displaying the arrays to make sure the sorting was correct: \n");
	_logger->LogImportant("Array sorted by " + algorithmNameOne + ": " + algorithmOne->GetArraySample() + "\n");
	_logger->LogImportant("Array sorted by " + algorithmNameTwo + ": " + algorithmTwo->GetArraySample() + "\n");

	_logger->LogInfo("THESE ARE THE RESULTS : \n\n");
	
	cout << YELLOW << Utilities::AddLeftSpaces("Algorithm", 20) << "|" << Utilities::AddLeftSpaces("     Time [seconds]", 20);
	cout << "\n" << string(45, '-') << "\n";

	cout << Utilities::AddLeftSpaces(algorithmNameOne, 20) 
		<< "|" 
		<< Utilities::AddLeftSpaces("     " + std::to_string(elapsedAlgorithmOne.count()), 20) << "\n";

	cout << Utilities::AddLeftSpaces(algorithmNameTwo, 20) 
		<< "|"
		<< Utilities::AddLeftSpaces("     " + std::to_string(elapsedAlgorithmTwo.count()), 20) << "\n\n" << RESET;

	_inputReader->WaitForAnyKeyPress();
}

void Menu::AlgorithmsDuelScreen(string algorithmOneName, string algorithmTwoName, SorterBase* algorithmOne, SorterBase* algorithmTwo)
{
	int maxFrame = algorithmOne->sortingFrames.size() > algorithmTwo->sortingFrames.size() ? algorithmOne->sortingFrames.size() : algorithmTwo->sortingFrames.size();
	
	bool runSimulationToEnd = false;
	string fileName;
	string tabs = "\t\t\t\t\t\t\t\t\t\t\t\t";
	char option = ' ';

	for (int i = 0; i < maxFrame; i++)
	{
		ClearTerminal();
		DisplaySideBySideAlgorithms(i, algorithmOneName, algorithmTwoName, algorithmOne, algorithmTwo);

		if (!runSimulationToEnd)
		{
			cout << tabs << "ENTER - Next step\n";
			cout << tabs << "1. Save current state to disk.\n";
			cout << tabs << "2. Run sorting until the end.\n";
			cout << tabs << "3. Return to main menu.\n\n";

			option = _inputReader->ReadOneChar();
			switch (option)
			{
			case '1':
				cout << "Please give a name for the save:\n>>> ";
				fileName = _inputReader->ReadString();
				_fileManager->SaveSortingFramesToFile(
					i,
					fileName,
					algorithmOne->sortingFrames,
					algorithmTwo->sortingFrames,
					algorithmOneName,
					algorithmTwoName
				);
				cout << "The state has been saved to a file. Load it again from the main menu.\n";
				_inputReader->WaitForAnyKeyPress();
				break;
			case '2':
				runSimulationToEnd = true;
				break;
			case '3':
				return;
			default:
				break;
			}
		}
		else
		{
			cout << tabs << "\nRunning the sorting until the end, please wait...\n";
			Utilities::Sleep(0.1);
		}
	}

	cout << "Sorting compelete!\n";
	_inputReader->WaitForAnyKeyPress();
}

void Menu::SelectAlgorithmSaveMenu()
{
	int option;
	vector<string> saves = _fileManager->GetAllFilesFromFolder("data\\saves");

	if (saves.size() <= 0)
	{
		cout << "There are no saved algorithm duels.";
		_inputReader->WaitForAnyKeyPress();
		return;
	}

	DummyAlgorithm* alg1 = new DummyAlgorithm();
	DummyAlgorithm* alg2 = new DummyAlgorithm();
	string algorithmName1;
	string algorithmName2;

	while (true)
	{
		ClearTerminal();
		cout << "\nPlease select one of the saves: \n";

		for (int i = 0; i < saves.size(); i++)
			cout << i + 1 << ". " << saves[i] << "\n";

		cout << saves.size() + 1 << ". Return to the main menu\n\n"
			<< ">>> ";

		option = _inputReader->ReadNumber();

		if (option == saves.size() + 1)
			return;

		else if (option >= 1 && option <= saves.size())
		{
			_fileManager->LoadSortingFramesFromFile(
				saves[option - 1],
				alg1,
				alg2,
				algorithmName1,
				algorithmName2
			);

			AlgorithmsDuelScreen(
				algorithmName1,
				algorithmName2,
				alg1,
				alg2);
			return;
		}
		else
		{
			cout << "Invalid option, please input one of the available option.\n"
				<< "Press ENTER to continue... ";
			_inputReader->ReadOneChar();
		}
	}
}

void Menu::AlgorithmSelectionMenu(SorterBase** alg1, SorterBase** alg2, string& algName1, string& algName2, int arraySize)
{
	int option;

	cout << "Please choose the two sorting algorithms you want to use:\n"
		<< "The available algorithms are:\n\n"
		<< "1. Bubble Sort\n"
		<< "2. Selection Sort\n"
		<< "3. Quick Sort\n"
		<< "4. Radix Sort\n"
		<< "5. Merge Sort\n"
		<< "6. Cocktail Sort\n"
		<< "7. Comb Sort\n"
		<< "8. Gnome Sort\n"
		<< "9. Odd-Even Sort\n"
		<< "10. Cycle Sort\n\n";

	while (true)
	{
		if (*alg1 == nullptr)
			cout << "Algorithm 1 >>> ";
		else
			cout << "Algorithm 2 >>> ";

		option = _inputReader->ReadNumber(1, 10);

		switch (option)
		{
		case 1:
			if (*alg1 == nullptr)
			{
				algName1 = "Bubble Sort";
				*alg1 = new BubbleSort(arraySize);
			}
			else
			{
				algName2 = "Bubble Sort";
				*alg2 = new BubbleSort(arraySize);
			}
			break;
		case 2:
			if (*alg1 == nullptr)
			{
				algName1 = "Insertion Sort";
				*alg1 = new SelectionSort(arraySize);
			}
			else
			{
				algName2 = "Insertion Sort";
				*alg2 = new SelectionSort(arraySize);
			}
			break;
		case 3:
			if (*alg1 == nullptr)
			{
				algName1 = "Quick Sort";
				*alg1 = new QuickSort(arraySize);
			}
			else
			{
				algName2 = "Quick Sort";
				*alg2 = new QuickSort(arraySize);
			}
			break;
		case 4:
			if (*alg1 == nullptr)
			{
				algName1 = "Radix Sort";
				*alg1 = new RadixSort(arraySize);
			}
			else
			{
				algName2 = "Radix Sort";
				*alg2 = new RadixSort(arraySize);
			}
			break;
		case 5:
			if (*alg1 == nullptr)
			{
				algName1 = "Merge Sort";
				*alg1 = new MergeSort(arraySize);
			}
			else
			{
				algName2 = "Merge Sort";
				*alg2 = new MergeSort(arraySize);
			}
			break;
		case 6:
			if (*alg1 == nullptr)
			{
				algName1 = "Cocktail Sort";
				*alg1 = new CocktailSort(arraySize);
			}
			else
			{
				algName2 = "Cocktail Sort";
				*alg2 = new CocktailSort(arraySize);
			}
			break;
		case 7:
			if (*alg1 == nullptr)
			{
				algName1 = "Comb Sort";
				*alg1 = new CombSort(arraySize);
			}
			else
			{
				algName2 = "Comb Sort";
				*alg2 = new CombSort(arraySize);
			}
			break;
		case 8:
			if (*alg1 == nullptr)
			{
				algName1 = "Gnome Sort";
				*alg1 = new GnomeSort(arraySize);
			}
			else
			{
				algName2 = "Gnome Sort";
				*alg2 = new GnomeSort(arraySize);
			}
			break;
		case 9:
			if (*alg1 == nullptr)
			{
				algName1 = "Odd-Even Sort";
				*alg1 = new OddEvenSort(arraySize);
			}
			else
			{
				algName2 = "Odd-Even Sort";
				*alg2 = new OddEvenSort(arraySize);
			}
			break;
		case 10:
			if (*alg1 == nullptr)
			{
				algName1 = "Cycle Sort";
				*alg1 = new CycleSort(arraySize);
			}
			else
			{
				algName2 = "Cycle Sort";
				*alg2 = new CycleSort(arraySize);
			}
			break;
		default:
			break;
		}

		if (*alg2 != nullptr)
			break;
	}
}

void Menu::DisplaySideBySideAlgorithms(int frame, string algorithmOneName, string algorithmTwoName, SorterBase* algorithmOne, SorterBase* algorithmTwo)
{
	string output = RED + string(MAX_LINE_LEN, BLOCK) + "\n";

	// 1st top red bar
	output += string(52, BLOCK) + CYAN + algorithmOneName + RED + string(50 - algorithmOneName.size() + 3, BLOCK);
	output += string(52, BLOCK) + CYAN + algorithmTwoName + RED + string(50 - algorithmTwoName.size() + 4, BLOCK) + "\n";

	// 2nd top bar and the algorithm names
	int algOneFrame = frame >= algorithmOne->sortingFrames.size() ? algorithmOne->sortingFrames.size() - 1 : frame;
	int algTwoFrame = frame >= algorithmTwo->sortingFrames.size() ? algorithmTwo->sortingFrames.size() - 1 : frame;

	// side bar + vector + middle + vector 2nd algorithm + size bar
	for (int i = ARRAY_SIZE_VISUALIZE; i >= 0; i--)
	{
		output += string(3, BLOCK) + string(25, ' ') + YELLOW;
		for (int j = 0; j < algorithmOne->sortingFrames[algOneFrame].size(); j++)
		{
			output += algorithmOne->sortingFrames[algOneFrame][j] >= i ? BLOCK : ' ';
		}

		output += RED + string(25, ' ') + string(5, BLOCK) + string(25, ' ') + YELLOW;

		for (int j = 0; j < algorithmTwo->sortingFrames[algTwoFrame].size(); j++)
		{
			output += algorithmTwo->sortingFrames[algTwoFrame][j] >= i ? BLOCK : ' ';
		}
		output += RED + string(25, ' ') + string(3, BLOCK) + "\n";
	}

	// top bottm bars, then reset
	output += RED + string(MAX_LINE_LEN, BLOCK) + "\n";
	output += RED + string(MAX_LINE_LEN, BLOCK) + "\n";
	output += RESET;

	cout << output;
}

void Menu::ClearTerminal()
{
#ifdef _WIN32
	// Clear screen in Windows
	std::system("cls");
#else
	// Clear screen in Linux and other Unix-like systems
	std::system("clear");
#endif
}

void Menu::HelpMenu()
{
	ClearTerminal();

	cout << YELLOW << R"DELIM(
 _____            _   _                ___  _                  _ _   _                    ______ ________  ________
/  ___|          | | (_)              / _ \| |                (_) | | |                   |  _  \  ___|  \/  |  _  |
\ `--.  ___  _ __| |_ _ _ __   __ _  / /_\ \ | __ _  ___  _ __ _| |_| |__  _ __ ___  ___  | | | | |__ | .  . | | | |
 `--. \/ _ \| '__| __| | '_ \ / _` | |  _  | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __| | | | |  __|| |\/| | | | |
/\__/ / (_) | |  | |_| | | | | (_| | | | | | | (_| | (_) | |  | | |_| | | | | | | | \__ \ | |/ /| |___| |  | \ \_/ /
\____/ \___/|_|   \__|_|_| |_|\__, | \_| |_/_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/ |___/ \____/\_|  |_/\___/ 
                               __/ |           __/ |                                                                
                              |___/           |___/                                                                  )DELIM";

	cout << CYAN << "\n\n1. What's the program for?\n\n";
	cout << YELLOW
		<< "This program allows visualising and benchmarking of sorting algorithms.\n"
		<< "The algorithms are displayed as line segments, the bigger the number, the longer the segment.\n"
		<< "Due to limitations while working in the terminal, only 50 segments can be displayed at once, for each alogrithm.\n"
		<< "The benchmark menu can sort larger lists, but without visualisation.\n\n";

	cout << CYAN << "2. What sorting algorithms are implemented?\n\n";
	cout << YELLOW
		<< "Select the first or second option in the main menu to view the list.\n\n";

	cout << CYAN << "3. How to use the menu?\n\n";
	cout << YELLOW
		<< "- Option 1 allows visualising 2 sorting algorithms side by side. During the sorting you may choose to save the current state of the sorting to a file, for later viewing.\n"
		<< "- Option 2 allows bentchmarking the speed of 2 sorting algorithms.\n"
		<< "- Option 3 allows reloading a prevously saved sorting back, and continuing visualisation. The files are saved as CSV.\n"
		<< "- Option 4 displays this screen.\n"
		<< "- Option 5 exists the program.\n\n";

	cout << CYAN << "4. Recommandations and Info: \n\n";
	cout << YELLOW
		<< "You SHOULD set the terminal font size to 13 or lower, otherwise everything will look bad.\n"
		<< "The program used CSV files to save the sorting algortims state, when choosing to save to file.\n\n";

	cout << RESET;

	_inputReader->WaitForAnyKeyPress();
}
