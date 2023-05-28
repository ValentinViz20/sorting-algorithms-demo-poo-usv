#pragma once

#include <iostream>
#include <cstdio>

#include "Constants.h"

// Handles reading and validating user input inside the application
class InputReader
{
public:
	InputReader();
	int ReadNumber(int minValue = INT32_MIN, int maxValue = INT32_MAX); // Reads a number from the user
	char ReadOneChar(); // Reads only one char from the user
	void WaitForAnyKeyPress(); // Waits until the user presses any key
	std::string ReadString(int maxLen = 255); // Reads a string from the user
};

