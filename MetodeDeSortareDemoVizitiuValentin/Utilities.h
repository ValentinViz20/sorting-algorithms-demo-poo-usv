#pragma once

#include <chrono>
#include <thread>
#include <string>

using std::string;

class Utilities
{
public:
	Utilities();
	static void Sleep(float seconds); // sleeps for the specified amount of seconds
	static string AddLeftSpaces(string text, int maxStringLen); // adds trailing spaces to the string
};

