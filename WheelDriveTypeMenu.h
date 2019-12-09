#ifndef WHEELDRIVETYPEMENU_H
#define WHEELDRIVETYPEMENU_H


#include "ConsoleMenu.h"

enum WheelDriveType
{
	FWD = 1,
	RWD,
	AWD
};

class WheelDriveTypeMenu : virtual public ConsoleMenu
{
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	WheelDriveTypeMenu();
	WheelDriveTypeMenu(const string& title, const vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~WheelDriveTypeMenu();
};


#endif // WHEELDRIVETYPEMENU_H