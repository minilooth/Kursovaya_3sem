#ifndef SEARCHINGMENU_H
#define SEARCHINGMENU_H


#include "SearchingSortingAndFilteringMenu.h"


namespace SearchingMenuAction
{
	enum
	{
		SEARCH_BY_BRAND = 1,
		SEARCH_BY_MODEL,
		SEARCH_BY_YEAR_OF_PRODUCTION,
		SEARCH_BY_ENGINE_TYPE,
		BACK
	};
}

class SearchingMenu : virtual public ConsoleMenu
{
	ConsoleMenu* getNextMenu() override;
	static unsigned choice_;
public:
	SearchingMenu();
	SearchingMenu(const string& title, const vector<string>& items);
	unsigned selectMode() override;
	void resetChoice() override;
	void showTitle() override;
	void showItems() override;
	~SearchingMenu();
};


#endif // SEARCHINGMENU_H