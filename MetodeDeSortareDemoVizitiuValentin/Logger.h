#pragma once

#include <iostream>
#include <string>
#include "Constants.h"

using std::cout;
using std::string;

class Logger
{
public:
	void LogInfo(string logText);
	void LogWarning(string logText);
	void LogImportant(string logText);
};

