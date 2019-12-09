#ifndef FILTERINGMENU_H
#define FILTERINGMENU_H


#include "SearchingSortingAndFilteringMenu.h"


namespace FilteringMenuAction
{
	enum
	{
		SET_FILTER_BY_BODY_TYPE = 1,
		SET_FILTER_BY_WHEEL_DRIVE_TYPE,
		SET_FILTER_BY_TRANSMISSION_TYPE,
		SHOW_FILTERED_CARS,
		BACK
	};
}

class FilteringMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	FilteringMenu();
	FilteringMenu(const string& title, const vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~FilteringMenu();
};


#endif // FILTERINGMENU_H