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
private:
	ConsoleMenu* getNextMenu();
	static unsigned choice_;
public:
	TypeOfSortingMenu();
	TypeOfSortingMenu(const string& title, const vector<string>& items);
	unsigned selectMode();
	void resetChoice();
	void showTitle();
	void showItems();
	~TypeOfSortingMenu();
};


#endif // TYPEOFSORTING_H