#ifndef USERMENU_H
#define USERMENU_H


#include "LoginMenu.h"
#include "CarHandler.h"

namespace UserMenuAction
{
	enum 
	{
		SHOW_ALL_CARS = 1,
		RESERVE_NEW_CAR,
		RESERVE_USED_CAR,
		SHOW_ACCOUNT_RESERVED_CARS,
		SHOW_ACCOUNT_STATISTICS,
		SEARCHING_SORTING_AND_FILTRATION,
		BACK
	};
}

class UserMenu : virtual public ConsoleMenu
{
    ConsoleMenu* getNextMenu() override;
    static unsigned choice_;
public:
    UserMenu();
	UserMenu(const string& title, const vector<string>& items);
    unsigned selectMode() override;
    void resetChoice() override;
	void showTitle() override;
    void showItems() override;
    ~UserMenu();
};


#endif //USERMENU_H
