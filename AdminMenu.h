#ifndef ADMINMENU_H
#define ADMINMENU_H


#include "AccountManagementMenu.h"
#include "CarHandler.h"

namespace AdminMenuAction
{
	enum
	{
		ACCOUNT_MANAGEMENT = 1,
		ADD_CAR,
		SHOW_CARS,
		DELETE_CAR,
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
	AdminMenu(string& title, vector<string>& items);
    unsigned selectMode();
    void resetChoice();
	void showTitle();
    void showItems();
    ~AdminMenu();
};


#endif //ADMINMENU_H
