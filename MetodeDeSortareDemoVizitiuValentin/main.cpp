#include <iostream>
#include "Menu.h"
#include "InputReader.h"

int main()
{
	InputReader* inputReader = new InputReader();
	FileManager* fileManager = new FileManager();
	Logger* logger = new Logger();

	Menu* menu = new Menu(inputReader, fileManager, logger);

	menu->MainMenu();
	return 0;
}

