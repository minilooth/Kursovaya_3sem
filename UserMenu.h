#ifndef USERMENU_H
#define USERMENU_H


#include "ConsoleMenu.h"
#include "LoginMenu.h"
#include "CarHandler.h"

namespace UserMenuAction
{
	enum
	{
		NEW_CARS = 1,
		CARS_FOR_SALE,
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
