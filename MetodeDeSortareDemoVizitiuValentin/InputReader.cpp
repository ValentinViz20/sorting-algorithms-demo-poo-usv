#include "InputReader.h"

#include <string>
using std::cin;
using std::cout;
using std::string;

InputReader::InputReader()
{
}


int InputReader::ReadNumber(int minValue, int maxValue)
{
    int number;
    string buffer;

    while (true)
    {
        cin >> buffer;

        try
        {
            number = std::stoi(buffer);
        }
        catch (const std::invalid_argument& ia) {
            cout << "Invalid argument: please type a number!\n>>> ";
            continue;
        }
        catch (const std::out_of_range& oor) {
            cout << "Number too large: please type a valid option\n>>> ";
            continue;
        }

        if (number > maxValue)
        {
            cout << "Number too big: please choose a number smaller than " << maxValue << "\n >>> ";
            continue;
        }
        if (number < minValue)
        {
            cout << "Number too small: please choose a number bigger than " << minValue << "\n >>> ";
            continue;
        }

        break;
    }

    cin.ignore();
    return number;
}

char InputReader::ReadOneChar()
{
    return getchar();
}

void InputReader::WaitForAnyKeyPress()
{
#ifdef _WIN32
    // Clear screen in Windows
    std::system("pause");
#else
    // Clear screen in Linux and other Unix-like systems
    std::system("read");
#endif
}

std::string InputReader::ReadString(int maxLen)
{
    string input;

    while (true)
    {
        cin >> input;

        if (input.size() > maxLen)
        {
            cout << "Input too large: please type less than " << maxLen << " characters.\n >>> ";
        }
        break;
    }

    return input;
}
