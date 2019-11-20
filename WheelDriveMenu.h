#ifndef WHEELDRIVEMENU_H
#define WHEELDRIVEMENU_H


#include "ConsoleMenu.h"

enum WheelDrive
{
	FWD = 1,
	RWD,
	AWD
};

class WheelDriveMenu : virtual public ConsoleMenu
{
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	WheelDriveMenu();
	WheelDriveMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~WheelDriveMenu();
};


#endif // WHEELDRIVEMENU_H