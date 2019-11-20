#ifndef ENGINETYPEMENU_H
#define ENGINETYPEMENU_H


#include "ConsoleMenu.h"

enum EngineType
{
	PETROL = 1,
	DIESEL
};

class EngineTypeMenu : virtual public ConsoleMenu
{
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	EngineTypeMenu();
	EngineTypeMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~EngineTypeMenu();
};


#endif // ENGINETYPEMENU_H