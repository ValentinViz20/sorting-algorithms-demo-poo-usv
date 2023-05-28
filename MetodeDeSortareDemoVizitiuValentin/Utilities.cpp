#include "Utilities.h"

Utilities::Utilities()
{
}

void Utilities::Sleep(float seconds)
{
	auto milisecondToSleep = std::chrono::milliseconds((int)(seconds * 1000));
	std::this_thread::sleep_for(milisecondToSleep);
}

string Utilities::AddLeftSpaces(string text, int maxStringLen)
{
	string newString(text);
	newString += string(maxStringLen - newString.size(), ' ');
	return newString;
}