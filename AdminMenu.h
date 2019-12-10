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
		SEARCHING_SORTING_AND_FILTRATION,
		BACK
	};
}

class AdminMenu : virtual public ConsoleMenu
{
    ConsoleMenu* getNextMenu() override;
    static unsigned choice_;
public:
    AdminMenu();
	AdminMenu(const string& title, const vector<string>& items);
    unsigned selectMode() override;
    void resetChoice() override;
	void showTitle() override;
    void showItems() override;
    ~AdminMenu();
};


#endif //ADMINMENU_H
