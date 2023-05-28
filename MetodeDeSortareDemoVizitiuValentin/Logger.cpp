#include "Logger.h"

void Logger::LogInfo(string logText)
{
	cout << YELLOW << "[INFO] " << logText << RESET;
}

void Logger::LogWarning(string logText)
{
	cout << RED << "[WARNING] " << logText << RESET;
}

void Logger::LogImportant(string logText)
{
	cout << GREEN << "[IMPORTANT] " << logText << RESET;
}
