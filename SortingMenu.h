#ifndef SORTINGMENU_H
#define SORTINGMENU_H


#include "SearchingSortingAndFilteringMenu.h"


namespace SortingMenuAction
{
	enum
	{
		SORT_BY_YEAR_OF_PRODUCTION = 1,
		SORT_BY_ENGINE_VOLUME,
		SORT_BY_PRICE,
		BACK
	};
}

class SortingMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	SortingMenu();
	SortingMenu(const string& title, const vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~SortingMenu();
};


#endif // SORTINGMENU_H