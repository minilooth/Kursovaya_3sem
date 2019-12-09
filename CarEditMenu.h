#ifndef CAREDITMENU_H
#define CAREDITMENU_H


#include "ConsoleMenu.h"
#include "CarHandler.h"

namespace CarEditMenuAction
{
	enum
	{
		EDIT_BRAND = 1,
		EDIT_MODEL,
		EDIT_YEAR_OF_PRODUCTION,
		EDIT_BODY_TYPE,
		EDIT_TRANSMISSION_TYPE,
		EDIT_WHEEL_DRIVE_TYPE,
		EDIT_ENGINE_TYPE,
		EDIT_ENGINE_VOLUME,
		EDIT_BODY_COLOR,
		EDIT_INTERIOR_COLOR,
		EDIT_INTERIOR_MATERIAL,
		EDIT_MEALEAGE,
		EDIT_PRICE,
		EDIT_RESERVE_STATUS,
		EDIT_RESERVER_USERNAME,
		BACK
	};
}

class CarEditMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	CarEditMenu();
	CarEditMenu(const string& title, const vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~CarEditMenu();
};


#endif // CAREDITMENU_H