#ifndef TYPEOFSORTING_H
#define TYPEOFSORTING_H


#include "ConsoleMenu.h"

namespace TypeOfSortingMenuAction
{
	enum
	{
		ASCENDING = 1,
		DESCENDING,
		BACK
	};
}

class TypeOfSortingMenu : virtual public ConsoleMenu
{
	ConsoleMenu* getNextMenu() override;
	static unsigned choice_;
public:
	TypeOfSortingMenu();
	TypeOfSortingMenu(const string& title, const vector<string>& items);
	unsigned selectMode() override;
	void resetChoice() override;
	void showTitle() override;
	void showItems() override;
	~TypeOfSortingMenu();
};


#endif // TYPEOFSORTING_H