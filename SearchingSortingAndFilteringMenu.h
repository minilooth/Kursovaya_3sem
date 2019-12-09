#ifndef SEARCHINGSORTINGANDFILTERINGMENU_H
#define SEARCHINGSORTINGANDFILTERINGMENU_H


#include "AccountHandler.h"

#include "SearchingMenu.h"
#include "SortingMenu.h"
#include "FilteringMenu.h"


namespace SearchingSortingAndFilteringMenuAction
{
	enum
	{
		SEARCHING = 1,
		SORTING,
		FILTERING,
		BACK
	};
}

class SearchingSortingAndFilteringMenu : virtual public ConsoleMenu
{
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	SearchingSortingAndFilteringMenu();
	SearchingSortingAndFilteringMenu(const string& title, const vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~SearchingSortingAndFilteringMenu();
};


#endif // SEARCHINGSORTINGANDFILTERINGMENU_H