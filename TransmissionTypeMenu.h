#ifndef TRANSMISSIONTYPEMENU_H
#define TRANSMISSIONTYPEMENU_H


#include "ConsoleMenu.h"

enum TransmissionType
{
	MANUAL = 1,
	AUTOMATIC
};

class TransmissionTypeMenu : virtual public ConsoleMenu
{
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	TransmissionTypeMenu();
	TransmissionTypeMenu(string& title, vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~TransmissionTypeMenu();
};


#endif // TRANSMISSIONTYPEMENU_H