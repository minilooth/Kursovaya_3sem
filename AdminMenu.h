#ifndef ADMINMENU_H
#define ADMINMENU_H


#include "AccountManagementMenu.h"
#include "SearchingSortingAndFilteringMenu.h"
#include "CarHandler.h"

namespace AdminMenuAction
{
	enum 
	{
		ACCOUNT_MANAGEMENT = 1,
		ADD_CAR,
		SHOW_CARS,
		DELETE_CAR,
		EDIT_CAR,
		SELL_CAR,
		SHOW_STATISTICS,
		SEARCHING_SORITNG_AND_FILTRATION,
		BACK
	};
}

class AdminMenu : virtual public ConsoleMenu
{
private:
    ConsoleMenu* getNextMenu();
    static unsigned choice_;
public:
    AdminMenu();
	AdminMenu(const string& title, const vector<string>& items);
    unsigned selectMode();
    void resetChoice();
	void showTitle();
    void showItems();
    ~AdminMenu();
};


#endif //ADMINMENU_H
