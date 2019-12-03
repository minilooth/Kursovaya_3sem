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
		FIND_CAR,
		BACK
	};
}

class UserMenu : virtual public ConsoleMenu
{
private:
    ConsoleMenu* getNextMenu();
    static unsigned choice_;
public:
    UserMenu();
	UserMenu(string& title, vector<string>& items);
    unsigned selectMode();
    void resetChoice();
	void showTitle();
    void showItems();
    ~UserMenu();
};


#endif //USERMENU_H
