#include "FileManager.h"

FileManager::FileManager()
{
    // Creates the folders required, if they don't exist
    const fs::path currentPath = fs::current_path();
    const fs::path fullPathData = currentPath / "data";
    const fs::path fullPathDataSaves = currentPath / "data\\saves";
    fs::create_directory(fullPathData);
    fs::create_directory(fullPathDataSaves);
}

void FileManager::SaveSortingFramesToFile(
    int currentFrame,
    string fileName,
    const vector<vector<int>> sortingFramesAlg1,
    const vector<vector<int>> sortingFramesAlg2,
    string algorthName1,
    string algorthName2
)
{
    const string filePath = "data\\saves\\" + fileName + ".csv";

    ofstream outputFile(filePath); // Open the file for writing
    auto frameSize = sortingFramesAlg1[0].size();

    if (outputFile.is_open()) 
    { 
        // Save the algorithms name
        outputFile << algorthName1 << "\n";

        // Iterate over all the frames one by one
        int j = currentFrame >= sortingFramesAlg1.size() ? sortingFramesAlg1.size() - 1 : currentFrame;
        for (; j < sortingFramesAlg1.size(); j++)
        {
            auto frame = sortingFramesAlg1[j];

            // Iterate over the numbers in the frame and save them
            for (int i = 0; i < frameSize; i++)
            {
                if (i < frameSize - 1)
                    outputFile << frame[i] << ",";
                else
                    outputFile << frame[i];
            }
            outputFile << "\n";
        }

        // Save the algorithms name
        outputFile << algorthName2 << "\n";

        // Iterate over all the frames one by one
        j = currentFrame >= sortingFramesAlg2.size() ? sortingFramesAlg2.size() - 1 : currentFrame;
        for (; j < sortingFramesAlg2.size(); j++)
        {
            auto frame = sortingFramesAlg2[j];

            // Iterate over the numbers in the frame and save them
            for (int i = 0; i < frameSize; i++)
            {
                if (i < frameSize - 1)
                    outputFile << frame[i] << ",";
                else
                    outputFile << frame[i];
            }
            outputFile << "\n";
        }

        outputFile.close();
    }
    else 
    {
        cout << "Failed to open the file.\n";
    }
}

void FileManager::LoadSortingFramesFromFile(
    string filename,
    SorterBase* dummyAlgoritm1,
    SorterBase* dummyAlgoritm2,
    string& algorithmName1,
    string& algorithmName2
)
{
    string filePath = "data\\saves\\" + filename;
    ifstream inputFile(filePath);

    if (inputFile.is_open()) 
    {
        string line;
        while (getline(inputFile, line)) 
        {
            vector<int> row;
            stringstream ss(line);
            string cell;

            // if the line has a coma, read the numbers from it
            if (line.find(",") != std::string::npos)
            {
                while (getline(ss, cell, ','))
                    row.push_back(stoi(cell));

                // Add the row to the data vector
                if (algorithmName2.size() <= 0)
                {
                    dummyAlgoritm1->sortingFrames.push_back(row);
                }
                else
                {
                    dummyAlgoritm2->sortingFrames.push_back(row);
                }
            }  

            else // if it doesn't have a come is the algorithm name
            {
                if (algorithmName1.size() <= 0)
                    algorithmName1 = line;
                else
                    algorithmName2 = line;
            }            
        }

        inputFile.close();
    }
    else 
    {
        cout << "Failed to open the file.\n";
    }
}

vector<string> FileManager::GetAllFilesFromFolder(string folderName)
{
    vector<string> files;

    const fs::path currentPath = fs::current_path();
    const fs::path fullPath = currentPath / folderName;

    try {
        for (const auto& entry : fs::directory_iterator(fullPath)) {
            if (fs::is_regular_file(entry)) {
                files.push_back(entry.path().filename().string());
            }
        }
    }
    catch (std::filesystem::filesystem_error exception)
    {
        return files;
    }
    
    return files;
}
